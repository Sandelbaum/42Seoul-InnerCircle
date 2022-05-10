/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:25:10 by kwolee            #+#    #+#             */
/*   Updated: 2022/04/29 12:34:25 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_fd_list	*init_fd(t_fd_list *head, int fd)
{
	t_fd_list	*node;

	node = head->rlink;
	while (node != NULL)
	{
		if (node->fd == fd)
			return (node);
		else
			node = node->rlink;
	}
	node = (t_fd_list *)malloc(sizeof(t_fd_list));
	if (node == NULL)
		return (NULL);
	node->fd = fd;
	node->str = NULL;
	node->llink = head;
	node->rlink = head->rlink;
	if (head->rlink != NULL)
		head->rlink->llink = node;
	head->rlink = node;
	return (node);
}

static char	*read_fd(t_fd_list *node)
{
	char	*buf;
	char	*str;
	char	*tmp;
	ssize_t	r_status;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	r_status = 0;
	str = node->str;
	while (str == NULL || ft_strchr(str, '\n') == NULL)
	{
		r_status = read(node->fd, buf, BUFFER_SIZE);
		if (r_status < 1)
			break ;
		buf[r_status] = '\0';
		tmp = str;
		str = ft_strjoin(str, buf);
		free(tmp);
	}
	free(buf);
	if (r_status < 0)
		return (NULL);
	node->str = str;
	return (str);
}

static char	*get_one_line(t_fd_list *node)
{
	size_t	len;
	char	*str;
	char	*left;

	if (ft_strchr(node->str, '\n') != NULL)
		len = ft_strchr(node->str, '\n') - node->str + 1;
	else
		len = ft_strchr(node->str, '\0') - node->str;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, node->str, len + 1);
	left = (char *)malloc(ft_strlen(node->str + len) + 1);
	if (left == NULL)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(left, node->str + len, ft_strlen(node->str + len) + 1);
	free(node->str);
	node->str = left;
	return (str);
}

static void	del_node(t_fd_list *node)
{
	free(node->str);
	node->llink->rlink = node->rlink;
	if (node->rlink)
		node->rlink->llink = node->llink;
	free(node);
}

char	*get_next_line(int fd)
{
	static t_fd_list	head;
	t_fd_list			*node;
	char				*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	node = init_fd(&head, fd);
	if (node == NULL)
		return (NULL);
	if (read_fd(node) == NULL || *(node->str) == '\0')
	{
		del_node(node);
		node = NULL;
		return (NULL);
	}
	line = get_one_line(node);
	if (line == NULL)
	{
		del_node(node);
		node = NULL;
		return (NULL);
	}
	return (line);
}
