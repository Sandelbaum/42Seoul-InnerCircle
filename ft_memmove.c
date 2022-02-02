/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:39:34 by kwolee            #+#    #+#             */
/*   Updated: 2022/01/28 15:17:02 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*source;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dest > source)
	{
		while (len)
		{
			len--;
			dest[len] = source[len];
		}
	}
	else if (dest <= source)
	{
		while (len)
		{
			*dest++ = *source++;
			len--;
		}
	}
	return (dst);
}
