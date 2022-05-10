/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:15:11 by kwolee            #+#    #+#             */
/*   Updated: 2022/01/25 20:14:14 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*j_str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	j_str = (char *)malloc(s1_len + s2_len + 1);
	if (!j_str)
		return (NULL);
	ft_memcpy(j_str, s1, s1_len);
	ft_memcpy(j_str + s1_len, s2, s2_len);
	j_str[s1_len + s2_len] = '\0';
	return (j_str);
}
