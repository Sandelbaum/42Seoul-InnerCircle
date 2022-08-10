/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:41:57 by kwolee            #+#    #+#             */
/*   Updated: 2022/08/09 20:01:13 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_split_str(char **split_str)
{
	int	index;

	index = 0;
	while (split_str[index])
		index++;
	return (index);
}

void	free_str(char **array)
{
	int	index;

	index = 0;
	while (array[index])
	{
		free(array[index]);
		index++;
	}
	free(array);
}

int	ft_atoll(const char *str)
{
	long long	result;
	int			np;
	int			chker;

	result = 0;
	np = 1;
	chker = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		np = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
		chker++;
	}
	result = result * np;
	if (*str != '\0' || chker > 10
		|| result > 2147483647 || result < -2147483648)
		puterr(1);
	return ((int)result);
}

void	str_to_array(int *array, int *arr_index, char **str)
{
	int	tmp_number;
	int	index;

	index = 0;
	while (str[index])
	{
		tmp_number = ft_atoll(str[index]);
		array[*arr_index] = tmp_number;
		(*arr_index)++;
		index++;
	}
}
