/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:16:21 by kwolee            #+#    #+#             */
/*   Updated: 2022/01/27 00:58:02 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*front;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = ft_lstnew(f(lst->content));
	if (!tmp)
		return (NULL);
	lst = lst->next;
	front = tmp;
	while (lst)
	{
		ft_lstadd_back(&tmp, ft_lstnew(f(lst->content)));
		tmp = tmp->next;
		if (!tmp)
		{
			ft_lstclear(&front, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (front);
}
