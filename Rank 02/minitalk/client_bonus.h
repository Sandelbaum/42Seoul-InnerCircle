/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:24:03 by kwolee            #+#    #+#             */
/*   Updated: 2022/06/24 14:15:17 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include <signal.h>
# include "./libft/libft.h"

typedef struct s_client
{
	struct sigaction	phase_send_con;
	struct sigaction	phase_send_msglen;
	struct sigaction	phase_send_msg;
	pid_t				pid_client;
	pid_t				pid_server;
	int					len;
	char				*msg;
}t_client;

extern t_client	g_client;

void	send_intbit(pid_t pid_server, int data);
void	send_msglen(int signo, siginfo_t *siginfo, void *context);
void	send_msg(int signo, siginfo_t *siginfo, void *context);

#endif