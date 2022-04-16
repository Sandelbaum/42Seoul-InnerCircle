/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:42:56 by kwolee            #+#    #+#             */
/*   Updated: 2022/04/15 23:43:55 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	uint_len(unsigned int num)
{
	int	l;

	l = 0;
	while (num != 0)
	{
		l++;
		num = num / 10;
	}
	return (l);
}

int	print_dec(int n)
{
	int		l;
	char	*num;

	l = 0;
	num = ft_itoa(n);
	l = print_str(num);
	free(num);
	return (l);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		l;

	l = uint_len(n);
	num = (char *)malloc(sizeof(char) * (l + 1));
	if (num == NULL)
		return (0);
	num[l] = '\0';
	while (n != 0)
	{
		num[l - 1] = n % 10 + '0';
		n = n / 10;
		l--;
	}
	return (num);
}

int	print_uint(unsigned int n)
{
	int		l;
	char	*num;

	l = 0;
	if (n == 0)
		l = print_char('0');
	else
	{
		num = ft_uitoa(n);
		l = print_str(num);
		free(num);
	}
	return (l);
}
