/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexdec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:43:01 by kwolee            #+#    #+#             */
/*   Updated: 2022/04/15 23:43:59 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexdec_len(unsigned int num)
{
	int	l;

	l = 0;
	while (num != 0)
	{
		l++;
		num = num / 16;
	}
	return (l);
}

static void	put_hexdec(unsigned int num, const char format)
{
	if (num >= 16)
	{
		put_hexdec(num / 16, format);
		put_hexdec(num % 16, format);
	}
	else
	{
		if (num <= 9)
			print_char(num + '0');
		else
		{
			if (format == 'x')
				print_char(num - 10 + 'a');
			else
				print_char(num - 10 + 'A');
		}
	}
}

int	print_hexdec(unsigned int num, const char format)
{
	if (num == 0)
		return (print_char('0'));
	else
		put_hexdec(num, format);
	return (hexdec_len(num));
}
