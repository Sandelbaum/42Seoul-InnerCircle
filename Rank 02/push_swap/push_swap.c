/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:04:24 by kwolee            #+#    #+#             */
/*   Updated: 2022/08/10 15:19:41 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	puterr(int type)
{
	if (type >= 1)
		write(2, "Error\n", 6);
	exit(1);
}

t_number	*init_stack(void)
{
	t_number	*num;

	num = NULL;
	num = (t_number *)malloc(sizeof(t_number));
	num->prev = NULL;
	num->content = 0;
	num->next = NULL;
	return (num);
}

static t_info	*init_info(void)
{
	t_number	*stack_a;
	t_info		*info;

	info = NULL;
	info = (t_info *)malloc(sizeof(t_info));
	stack_a = init_stack();
	info->array = NULL;
	info->size_a = 0;
	info->top_a = stack_a;
	info->bottom_a = stack_a;
	info->size_b = 0;
	return (info);
}

int	main(int argc, char *argv[])
{
	int			array_size;
	int			*num_array;
	t_info		*info;

	if (argc < 2)
		puterr(-1);
	array_size = 0;
	info = init_info();
	array_size = count_str(argc, argv);
	num_array = argv_to_array(argc, argv, array_size);
	array_to_stack(info, num_array, array_size);
	check_array_sort(num_array, array_size, 0);
	info->array = (int *)num_array;
	sort_begin(info);
	return (0);
}
