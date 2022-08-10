/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_al_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:38:07 by kwolee            #+#    #+#             */
/*   Updated: 2022/08/10 15:03:32 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_min(t_number *stack)
{
	int	n;

	n = stack->content;
	while (stack)
	{
		if (n > stack->content)
			n = stack->content;
		stack = stack->next;
	}
	return (n);
}

int	set_a_location_min(t_info *info)
{
	int			n;
	int			index;
	int			tmp;
	t_number	*stack_a;

	n = 0;
	tmp = 0;
	stack_a = info->top_a;
	index = get_stack_min(stack_a);
	while (stack_a)
	{
		tmp = stack_a->content;
		if (tmp == index)
			break ;
		n++;
		stack_a = stack_a->next;
	}
	if (n >= (info->size_a + 1) / 2)
		n = (info->size_a - n) * -1;
	return (n);
}

int	get_stack_max(t_number *stack)
{
	int	n;

	n = stack->content;
	while (stack)
	{
		if (n < stack->content)
			n = stack->content;
		stack = stack->next;
	}
	return (n);
}

int	set_a_location_max(t_info *info)
{
	int			n;
	int			index;
	int			tmp;
	t_number	*stack_a;

	n = 0;
	tmp = 0;
	stack_a = info->top_a;
	index = get_stack_max(stack_a);
	while (stack_a)
	{
		tmp = stack_a->content;
		if (tmp == index)
			break ;
		n++;
		stack_a = stack_a->next;
	}
	n++;
	if (n >= (info->size_a + 1) / 2)
		n = (info->size_a - n) * -1;
	return (n);
}

int	set_a_location_mid(int num, t_info *info)
{
	t_number	*stack_a;
	int			n;

	stack_a = info->top_a;
	n = 1;
	while (stack_a->next)
	{
		if (num > stack_a->content && num < stack_a->next->content)
			break ;
		n++;
		stack_a = stack_a->next;
	}
	if (n >= (info->size_a + 1) / 2)
		n = (info->size_a - n) * -1;
	return (n);
}
