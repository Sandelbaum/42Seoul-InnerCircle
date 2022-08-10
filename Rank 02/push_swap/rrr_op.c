/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:11:35 by kwolee            #+#    #+#             */
/*   Updated: 2022/08/10 15:03:24 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_info *info)
{
	t_number	*tmp;

	if (info->size_a < 2)
		return ;
	tmp = info->bottom_a;
	info->bottom_a = info->bottom_a->prev;
	info->bottom_a->next = NULL;
	info->top_a->prev = tmp;
	tmp->next = info->top_a;
	info->top_a = tmp;
	info->top_a->prev = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_info *info)
{
	t_number	*tmp;

	if (info->size_b < 2)
		return ;
	tmp = info->bottom_b;
	info->bottom_b = info->bottom_b->prev;
	info->bottom_b->next = NULL;
	info->top_b->prev = tmp;
	tmp->next = info->top_b;
	info->top_b = tmp;
	info->top_b->prev = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_info *info)
{
	t_number	*tmp;

	if (info->size_b < 2 || info->size_a < 2)
		return ;
	tmp = info->bottom_a;
	info->bottom_a = info->bottom_a->prev;
	info->bottom_a->next = NULL;
	info->top_a->prev = tmp;
	tmp->next = info->top_a;
	info->top_a = tmp;
	info->top_a->prev = NULL;
	tmp = info->bottom_b;
	info->bottom_b = info->bottom_b->prev;
	info->bottom_b->next = NULL;
	info->top_b->prev = tmp;
	tmp->next = info->top_b;
	info->top_b = tmp;
	info->top_b->prev = NULL;
	write(1, "rrr\n", 4);
}
