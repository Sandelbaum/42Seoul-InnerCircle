/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:54:48 by kwolee            #+#    #+#             */
/*   Updated: 2022/04/29 00:46:33 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
	{
		l++;
	}
	return (l);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	length;
	size_t	index;

	index = 0;
	length = 0;
	while (src[length])
		length++;
	while (index < length && index + 1 < dstsize)
	{
		dst[index] = src[index];
		index++;
	}
	if (dstsize > 0)
		dst[index] = '\0';
	return (length);
}

char	*ft_strjoin(char const *str, char const *buf)
{
	size_t	str_len;
	size_t	buf_len;
	char	*j_str;

	if (buf == NULL)
		return (NULL);
	buf_len = ft_strlen(buf);
	if (str == NULL)
	{
		j_str = (char *)malloc(buf_len + 1);
		if (j_str == NULL)
			return (NULL);
		ft_strlcpy(j_str, buf, buf_len + 1);
		return (j_str);
	}
	str_len = ft_strlen(str);
	j_str = (char *)malloc(str_len + buf_len + 1);
	if (j_str == NULL)
		return (NULL);
	ft_strlcpy(j_str, str, str_len + 1);
	ft_strlcpy(j_str + str_len, buf, buf_len + 1);
	return (j_str);
}
