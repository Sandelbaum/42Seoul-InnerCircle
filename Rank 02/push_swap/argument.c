/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:19:49 by kwolee            #+#    #+#             */
/*   Updated: 2022/08/09 19:56:17 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_str(int argc, char *argv[])
{
	int		index;
	int		size;
	int		count;
	char	**split_str;

	index = 0;
	size = 0;
	while (index < argc)
	{
		count = 0;
		while (argv[index][count])
		{
			if (!ft_isspace(argv[index][count]))
				break ;
			count++;
		}
		if (argv[index][count] == '\0')
			puterr(1);
		split_str = ft_split(argv[index], ' ');
		size += count_split_str(split_str);
		free_str(split_str);
		index++;
	}
	return (size - 1);
}

int	*argv_to_array(int argc, char *argv[], int size)
{
	int		argc_index;
	int		arr_index;
	int		*array;
	char	**split_str;

	argc_index = 1;
	arr_index = 0;
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		puterr(1);
	while (argc_index < argc)
	{
		split_str = ft_split(argv[argc_index], ' ');
		str_to_array(array, &arr_index, split_str);
		free_str(split_str);
		argc_index++;
	}
	array[arr_index] = '\0';
	return (array);
}

void	array_to_stack(t_info *info, int *array, int size)
{
	t_number	*new_node;
	int			index;

	index = 0;
	while (index < size)
	{
		new_node = init_stack();
		info->size_a += 1;
		info->bottom_a->content = (int)array[index];
		info->bottom_a->next = new_node;
		new_node->prev = info->bottom_a;
		info->bottom_a = new_node;
		index++;
	}
	info->bottom_a = info->bottom_a->prev;
	free(new_node);
}

void	check_array_sort(int *array, int size, int index)
{
	int	j;
	int	count;
	int	tmp;

	count = 0;
	while (index < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				count++;
			}
				j++;
		}
		if (array[index] == array[index + 1])
			puterr(1);
		index++;
	}
	if (count == 0)
		puterr(-1);
}
