/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:19:05 by sel-bouy          #+#    #+#             */
/*   Updated: 2024/05/10 16:11:26 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			r++;
		while (s[i] != c && s[i])
			i++;
	}
	return (r);
}

static int	count_ch(char const *s, char c)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			word++;
			i++;
		}
		if (s[i - 1] != c)
			return (word);
	}
	return (0);
}

static char	**ft_free(char **res)
{
	int	i;

	i = 0;
	if (res)
	{
		while (res[i])
		{
			free(res[i]);
			i++;
		}
		free(res);
	}
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t n)
{
	unsigned int	nh;
	size_t			i;
	char			*n9lu;

	if (!s)
		return (0);
	nh = ft_strlen(s);
	if (s == 0)
		return (0);
	if (start > nh)
		n = 0;
	if (n > nh - start)
		n = nh - start;
	n9lu = malloc (sizeof(char) * (n + 1));
	if (n9lu == 0)
		return (free(n9lu), NULL);
	i = 0;
	while (i < n)
	{
		n9lu[i] = s[start + i];
		i++;
	}
	n9lu[i] = '\0';
	return (n9lu);
}

char	**ft_split(char *s, char c)
{
	char	**res;
	int		j;

	j = 0;
	if (s == 0)
		return (0);
	res = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (res == 0)
		return (free(res), NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			res[j] = ft_substr(s, 0, count_ch(s, c));
			if (!res[j])
				return (ft_free(res));
			s += count_ch(s, c);
			j++;
		}
	}
	res[j] = NULL;
	return (res);
}
