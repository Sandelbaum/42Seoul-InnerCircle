/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_begin_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:54:47 by kwolee            #+#    #+#             */
/*   Updated: 2022/08/10 15:25:57 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_over_three_end(t_info *info)
{
	int	min_location;

	min_location = set_a_location_min(info);
	while (min_location)
	{
		if (min_location > 0)
		{
			ra(info);
			min_location--;
		}
		else
		{
			rra(info);
			min_location++;
		}
	}
}

void	devide_three_layer(t_info *info, int pivot1, int pivot2)
{
	if (info->top_a->content < pivot1)
	{
		pb(info);
		rb(info);
	}
	else if (info->top_a->content < pivot2)
		pb(info);
	else
		ra(info);
}

void	select_pivot(t_info *info)
{
	int	index;
	int	pivot1;
	int	pivot2;

	index = info->size_a / 3;
	pivot1 = info->array[index];
	index = info->size_a * 2 / 3;
	pivot2 = info->array[index];
	index = info->size_a;
	while (index)
	{
		devide_three_layer(info, pivot1, pivot2);
		index--;
	}
}

static int	cal_min(int a, int b, int a_loc, int b_loc)
{
	if (a < 0)
		a = a * -1;
	if (b < 0)
		b = b * -1;
	if (a_loc < 0)
		a_loc = a_loc * -1;
	if (b_loc < 0)
		b_loc = b_loc * -1;
	if (a + b > a_loc + b_loc)
		return (1);
	else
		return (0);
}

void	cal_min_rotate(t_info *info, int *a, int *b)
{
	int			a_location;
	int			b_location;
	int			index;
	t_number	*stack_b;
	int			num;

	index = 0;
	stack_b = info->top_b;
	while (index < info->size_b)
	{
		num = stack_b->content;
		a_location = set_a_location(num, info);
		if (index >= (info->size_b + 1) / 2)
			b_location = (info->size_b - index) * -1;
		else
			b_location = index;
		if (index == 0 || cal_min(*a, *b, a_location, b_location))
		{
			*a = a_location;
			*b = b_location;
		}
		stack_b = stack_b->next;
		index++;
	}
}
