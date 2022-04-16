/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:43:04 by kwolee            #+#    #+#             */
/*   Updated: 2022/04/15 23:44:03 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptr_len(uintptr_t ptr)
{
	int	l;

	l = 0;
	while (ptr != 0)
	{
		l++;
		ptr = ptr / 16;
	}
	return (l);
}

static void	put_ptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		put_ptr(ptr / 16);
		put_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			print_char(ptr + '0');
		else
			print_char(ptr - 10 + 'a');
	}
}

int	print_ptr(unsigned long long ptr)
{
	int	l;

	l = 2;
	put_str("0x");
	if (ptr == 0)
		l += print_char('0');
	else
	{
		put_ptr(ptr);
		l += ptr_len(ptr);
	}
	return (l);
}
