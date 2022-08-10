/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_al.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:36:00 by kwolee            #+#    #+#             */
/*   Updated: 2022/08/10 15:03:36 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_a_location(int num, t_info *info)
{
	int	n;

	if (num < get_stack_min(info->top_a))
		n = set_a_location_min(info);
	else if (num > get_stack_max(info->top_a))
		n = set_a_location_max(info);
	else
		n = set_a_location_mid(num, info);
	return (n);
}

void	rotate_all(t_info *info, int *a, int *b)
{
	while (*a && *b && (*a > 0 && *b > 0))
	{
		rr(info);
		*a = *a - 1;
		*b = *b - 1;
	}
	while (*a && *b && (*a < 0 && *b < 0))
	{
		rrr(info);
		*a = *a + 1;
		*b = *b + 1;
	}
}

void	rotate_a(t_info *info, int a)
{
	while (a)
	{
		if (a > 0)
		{
			ra(info);
			a--;
		}
		else
		{
			rra(info);
			a++;
		}
	}
}

void	rotate_b(t_info *info, int b)
{
	while (b)
	{
		if (b > 0)
		{
			rb(info);
			b--;
		}
		else
		{
			rrb(info);
			b++;
		}
	}
}
