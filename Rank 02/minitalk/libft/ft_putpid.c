/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:10:51 by kwolee            #+#    #+#             */
/*   Updated: 2022/06/22 17:18:08 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putpid(int pid, int flag)
{
	char	*pid_str;
	int		i;

	i = 0;
	pid_str = ft_itoa(pid);
	if (!pid_str)
		exit(1);
	if (flag == 1)
		write(1, "client pid: ", 12);
	else if (flag == 2)
		write(1, "server pid: ", 12);
	while (pid_str[i])
	{
		write(1, &pid_str[i], 1);
		i++;
	}
	free(pid_str);
	pid_str = NULL;
	write(1, "\n", 1);
}
