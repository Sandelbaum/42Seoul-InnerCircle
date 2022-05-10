/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:21:43 by kwolee            #+#    #+#             */
/*   Updated: 2022/01/25 20:14:22 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_i;

	dst_len = 0;
	src_i = 0;
	while (dst[dst_len] && dst_len < dstsize)
		dst_len++;
	while (src[src_i] && (dst_len + src_i + 1) < dstsize)
	{
		dst[dst_len + src_i] = src[src_i];
		src_i++;
	}
	if (dst_len < dstsize)
		dst[dst_len + src_i] = '\0';
	return (dst_len + ft_strlen(src));
}
