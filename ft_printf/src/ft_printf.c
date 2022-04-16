/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:42:47 by kwolee            #+#    #+#             */
/*   Updated: 2022/04/16 00:39:19 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_formats(va_list *ap, const char format)
{
	int	l;

	l = 0;
	if (format == 'c')
		l = print_char(va_arg(*ap, int));
	else if (format == '%')
		l = print_char('%');
	else if (format == 's')
		l = print_str(va_arg(*ap, char *));
	else if (format == 'd' || format == 'i')
		l = print_dec(va_arg(*ap, int));
	else if (format == 'u')
		l = print_uint(va_arg(*ap, unsigned int));
	else if (format == 'x' || format == 'X')
		l = print_hexdec(va_arg(*ap, unsigned int), format);
	else if (format == 'p')
		l = print_ptr(va_arg(*ap, unsigned long long));
	return (l);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		l;

	i = 0;
	l = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			l += check_formats(&ap, str[i + 1]);
			i++;
		}
		else
			l += print_char(str[i]);
		i++;
	}
	va_end(ap);
	return (l);
}
