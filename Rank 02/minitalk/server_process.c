/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:07:43 by kwolee            #+#    #+#             */
/*   Updated: 2022/06/23 21:27:46 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_server	g_server;

void	ping_wait(pid_t pid_client)
{
	kill(pid_client, SIGUSR1);
}

void	ping_next(pid_t pid_client)
{
	kill(pid_client, SIGUSR2);
}

static void	putmsg(void)
{
	int	i;

	i = 0;
	ft_putpid(g_server.pid_client, 1);
	while (g_server.msg[i])
	{
		write(1, &g_server.msg[i], 1);
		i++;
	}
	write(1, "\n", 1);
	free(g_server.msg);
}

void	receive_msglen(int signo, siginfo_t *siginfo, void *context)
{
	(void)context;
	if (siginfo->si_pid != g_server.pid_client)
		ping_wait(siginfo->si_pid);
	else
	{
		g_server.len <<= 1;
		g_server.len += (signo == SIGUSR2);
		g_server.len_bitcnt++;
		if (g_server.len_bitcnt == 32)
		{
			if (!g_server.msg)
				g_server.msg = (char *)ft_calloc(sizeof(char),
						(g_server.len + 1));
			sigaction(SIGUSR1, &g_server.phase_read_msg, NULL);
			sigaction(SIGUSR2, &g_server.phase_read_msg, NULL);
		}
		ping_next(g_server.pid_client);
	}
}

void	receive_msg(int signo, siginfo_t *siginfo, void *context)
{
	pid_t	tmp;

	(void)context;
	if (siginfo->si_pid != g_server.pid_client)
		ping_wait(siginfo->si_pid);
	else
	{
		tmp = g_server.pid_client;
		g_server.msg[g_server.msg_idx] <<= 1;
		g_server.msg[g_server.msg_idx] += (signo == SIGUSR2);
		g_server.msg_bitcnt++;
		if (g_server.msg_bitcnt == 8)
		{
			g_server.msg_idx++;
			g_server.msg_bitcnt = 0;
		}
		if (g_server.msg_idx == g_server.len)
		{
			putmsg();
			reinit_sigaction();
		}
		ping_next(tmp);
	}
}
