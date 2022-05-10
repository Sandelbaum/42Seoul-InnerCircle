/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:57:45 by kwolee            #+#    #+#             */
/*   Updated: 2022/01/27 00:55:14 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != '\0' && s[i] != c)
			i++;
		count++;
	}
	return (count);
}

static void	free_all(char **ans, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(ans[i++]);
	free(ans);
}

static char	*split_word(char const *s, int len)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	split_each(char const *s, char c, char **ans)
{
	int	i;
	int	count;
	int	index;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		index = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		ans[count] = split_word(s + index, i - index);
		if (!ans[count])
		{
			free_all(ans, count);
			return ;
		}
		count++;
	}
	ans[count] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**ans;

	ans = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!ans)
		return (NULL);
	split_each(s, c, ans);
	return (ans);
}
