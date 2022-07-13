/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:09:32 by kwolee            #+#    #+#             */
/*   Updated: 2022/07/11 19:22:50 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 1

typedef struct s_fd_list
{
	int					fd;
	char				*str;
	struct s_fd_list	*llink;
	struct s_fd_list	*rlink;
}t_fd_list;

char	*get_next_line(int fd);
char	*ft_gnl_strchr(const char *s, int c);
size_t	ft_gnl_strlen(const char *s);
size_t	ft_gnl_strlcpy(char *dst, const char *src, size_t size);
char	*ft_gnl_strjoin(char const *str, char const *buf);

#endif