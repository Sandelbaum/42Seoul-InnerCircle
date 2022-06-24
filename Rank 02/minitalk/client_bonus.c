/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:23:49 by kwolee            #+#    #+#             */
/*   Updated: 2022/06/24 14:25:22 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

t_client	g_client;

static void	verify_input(int argc, char **argv)
{
	int	i;
	int	l;

	i = 0;
	if (argc != 3)
		ft_puterr("Usage: ./client [pid_server] [message]\n");
	if (!(argv[2]))
		ft_puterr("Error: invalid message.\n");
	g_client.pid_server = (pid_t)ft_atoi(argv[1]);
	while (ft_isdigit(argv[1][i]))
		i++;
	l = ft_strlen(argv[1]);
	if (g_client.pid_server <= 100 || g_client.pid_server > 100000 || i != l)
		ft_puterr("Error: invalid server pid.\n");
	g_client.len = ft_strlen(argv[2]);
	if (g_client.len <= 0)
		ft_puterr("Error: invalid message.\n");
	g_client.pid_client = getpid();
	g_client.msg = argv[2];
}

static void	send_connection(void)
{
	int			usleep_checker;
	static int	try_cnt;

	usleep_checker = 0;
	try_cnt = 0;
	while (1)
	{
		kill(g_client.pid_server, SIGUSR2);
		usleep_checker = usleep(1000000);
		try_cnt++;
		if (usleep_checker != 0 || try_cnt == 10)
			break ;
	}
	if (try_cnt == 10)
		ft_puterr("Error: server didn't receive client's request.\n");
}

static void	check_connection(int signo, siginfo_t *siginfo, void *context)
{
	(void)siginfo;
	(void)context;
	if (signo == SIGUSR1)
		send_connection();
	if (signo == SIGUSR2)
	{
		sigaction(SIGUSR1, &g_client.phase_send_msglen, NULL);
		sigaction(SIGUSR2, &g_client.phase_send_msglen, NULL);
		send_intbit(g_client.pid_server, g_client.len);
	}
}

static void	init_sigaction(void)
{
	g_client.phase_send_con.sa_sigaction = check_connection;
	g_client.phase_send_msglen.sa_sigaction = send_msglen;
	g_client.phase_send_msg.sa_sigaction = send_msg;
	sigemptyset(&g_client.phase_send_con.sa_mask);
	sigemptyset(&g_client.phase_send_msglen.sa_mask);
	sigemptyset(&g_client.phase_send_msg.sa_mask);
	g_client.phase_send_con.sa_flags = SA_SIGINFO;
	g_client.phase_send_msglen.sa_flags = SA_SIGINFO;
	g_client.phase_send_msg.sa_flags = SA_SIGINFO;
}

int	main(int argc, char **argv)
{
	verify_input(argc, argv);
	ft_putpid(g_client.pid_client, 1);
	init_sigaction();
	sigaction(SIGUSR1, &g_client.phase_send_con, NULL);
	sigaction(SIGUSR2, &g_client.phase_send_con, NULL);
	send_connection();
	while (1)
		pause();
	return (0);
}
