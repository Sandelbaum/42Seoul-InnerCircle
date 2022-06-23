/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_send_phase_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:24:09 by kwolee            #+#    #+#             */
/*   Updated: 2022/06/23 21:27:01 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

t_client	g_client;

static void	send_bit(pid_t pid_server, int data, int data_size, int *idx)
{
	int	bitmask;

	bitmask = (1 << ((data_size * 8) - 1));
	if (((data << *idx) & bitmask) == bitmask)
	{
		(*idx)++;
		kill(pid_server, SIGUSR2);
	}
	else
	{
		(*idx)++;
		kill(pid_server, SIGUSR1);
	}
	usleep(100);
}

static void	send_strbit(pid_t pid_server, char *msg)
{
	static int	stridx;
	static int	bitcnt;

	if (bitcnt == 8)
	{
		stridx++;
		bitcnt = 0;
	}
	if (stridx == g_client.len)
		exit(0);
	send_bit(pid_server, msg[stridx], sizeof(char), &bitcnt);
}

void	send_intbit(pid_t pid_server, int data)
{
	static int	idx;

	if (idx < 32)
		send_bit(pid_server, data, sizeof(int), &idx);
	else if (idx == 32)
	{
		sigaction(SIGUSR1, &g_client.phase_send_msg, NULL);
		sigaction(SIGUSR2, &g_client.phase_send_msg, NULL);
		send_strbit(pid_server, g_client.msg);
	}
}

void	send_msglen(int signo, siginfo_t *siginfo, void *context)
{
	(void)signo;
	(void)siginfo;
	(void)context;
	send_intbit(g_client.pid_server, g_client.len);
}

void	send_msg(int signo, siginfo_t *siginfo, void *context)
{
	(void)signo;
	(void)siginfo;
	(void)context;
	send_strbit(g_client.pid_server, g_client.msg);
}
