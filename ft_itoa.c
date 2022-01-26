/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:03:00 by kwolee            #+#    #+#             */
/*   Updated: 2022/01/25 21:05:36 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*p_op(void)
{
	char	*a;

	a = (char *)malloc(sizeof(char) * 11 + 1);
	if (!a)
		return (NULL);
	ft_strlcpy(a, "-2147483648", 12);
	return (a);
}

static char	*return_zero(void)
{
	char	*a;

	a = (char *)malloc(sizeof(char) * 1 + 1);
	if (!a)
		return (NULL);
	a[0] = '0';
	a[1] = '\0';
	return (a);
}

static int	int_len(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count = 1;
		n = -n;
	}
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*a;

	if (n == -2147483648)
		return (p_op());
	if (n == 0)
		return (return_zero());
	len = int_len(n);
	a = malloc(sizeof(char) * len + 1);
	a[len--] = '\0';
	if (!a)
		return (NULL);
	if (n < 0)
	{
		a[0] = '-';
		n = -n;
	}
	while (n)
	{
		a[len] = '0' + n % 10;
		n = n / 10;
		len--;
	}
	return (a);
}
