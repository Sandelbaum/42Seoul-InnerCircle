/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:25:05 by kwolee            #+#    #+#             */
/*   Updated: 2022/06/23 21:41:46 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include <signal.h>
# include "../libft/libft.h"

typedef struct s_server
{
	struct sigaction	phase_read_con;
	struct sigaction	phase_read_msglen;
	struct sigaction	phase_read_msg;
	pid_t				pid_client;
	unsigned int		len;
	unsigned int		len_bitcnt;
	unsigned int		msg_idx;
	unsigned int		msg_bitcnt;
	char				*msg;
}t_server;

extern t_server	g_server;

void	ping_wait(int pid_client);
void	ping_next(int pid_client);
void	receive_msglen(int signo, siginfo_t *siginfo, void *context);
void	receive_msg(int signo, siginfo_t *siginfo, void *context);
void	reinit_sigaction(void);

#endif