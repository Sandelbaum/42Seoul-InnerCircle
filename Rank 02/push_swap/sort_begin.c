/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_begin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:59:39 by kwolee            #+#    #+#             */
/*   Updated: 2022/08/10 15:18:15 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_info *info)
{
	int	top;
	int	mid;
	int	bot;

	top = info->top_a->content;
	mid = info->top_a->next->content;
	bot = info->top_a->next->next->content;
	if (top > mid && mid > bot && top > bot)
	{
		sa(info);
		rra(info);
	}
	else if (top > mid && bot > mid && top > bot)
		ra(info);
	else if (mid > top && mid > bot && bot > top)
	{
		sa(info);
		ra(info);
	}
	else if (top > mid && bot > mid && bot > top)
		sa(info);
	else if (mid > top && mid > bot && top > bot)
		rra(info);
}

static void	sort_over_three(t_info *info)
{
	int	a;
	int	b;

	select_pivot(info);
	while (info->size_a > 3)
		pb(info);
	if (info->size_a == 2)
	{
		if (info->top_a->content > info->top_a->next->content)
			sa(info);
	}
	if (info->size_a == 3)
		sort_three(info);
	while (info->size_b)
	{
		a = 0;
		b = 0;
		cal_min_rotate(info, &a, &b);
		rotate_all(info, &a, &b);
		rotate_a(info, a);
		rotate_b(info, b);
		pa(info);
	}
	sort_over_three_end(info);
}

void	sort_begin(t_info *info)
{
	if (info->size_a == 2)
	{
		if (info->top_a->content > info->top_a->next->content)
			sa(info);
	}
	else if (info->size_a == 3)
		sort_three(info);
	else
		sort_over_three(info);
}
