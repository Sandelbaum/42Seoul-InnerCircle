/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:19:08 by kwolee            #+#    #+#             */
/*   Updated: 2022/06/23 21:32:29 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_server	g_server;

static void	receive_connection(int signo, siginfo_t *siginfo, void *context)
{
	(void)signo;
	(void)context;
	if (g_server.pid_client == 0)
	{
		g_server.pid_client = siginfo->si_pid;
		sigaction(SIGUSR1, &g_server.phase_read_msglen, NULL);
		sigaction(SIGUSR2, &g_server.phase_read_msglen, NULL);
		ping_next(g_server.pid_client);
	}
	else if (g_server.pid_client)
		ping_wait(siginfo->si_pid);
}

static void	init_sigaction(void)
{
	g_server.phase_read_con.sa_sigaction = receive_connection;
	g_server.phase_read_msglen.sa_sigaction = receive_msglen;
	g_server.phase_read_msg.sa_sigaction = receive_msg;
	sigemptyset(&g_server.phase_read_con.sa_mask);
	sigemptyset(&g_server.phase_read_msglen.sa_mask);
	sigemptyset(&g_server.phase_read_msg.sa_mask);
	g_server.phase_read_con.sa_flags = SA_SIGINFO;
	g_server.phase_read_msglen.sa_flags = SA_SIGINFO;
	g_server.phase_read_msg.sa_flags = SA_SIGINFO;
}

void	reinit_sigaction(void)
{
	g_server.pid_client = 0;
	g_server.len = 0;
	g_server.len_bitcnt = 0;
	g_server.msg_idx = 0;
	g_server.msg_bitcnt = 0;
	g_server.msg = NULL;
	sigaction(SIGUSR1, &g_server.phase_read_con, NULL);
	sigaction(SIGUSR2, &g_server.phase_read_con, NULL);
}

int	main(void)
{
	ft_putpid(getpid(), 2);
	init_sigaction();
	sigaction(SIGUSR1, &g_server.phase_read_con, NULL);
	sigaction(SIGUSR2, &g_server.phase_read_con, NULL);
	while (1)
		pause();
	return (0);
}
