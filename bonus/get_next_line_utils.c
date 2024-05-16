/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:26:48 by sel-bouy          #+#    #+#             */
/*   Updated: 2024/05/14 11:57:52 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_bonus.h"

size_t	ft_strlen(char *h)
{
	size_t	i;

	i = 0;
	if (!h)
		return (0);
	while (h[i] != '\0')
		i++;
	return (i);
}

char	*ft_search(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s + i);
	}
	return (NULL);
}

char	*ft_help_join(char *s1, char *s2, char *buff)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i] != '\0')
		{
			buff[i] = s1[i];
			i++;
		}
		free(s1);
	}
	if (s2)
	{
		while (s2[j] != '\0')
		{
			buff[i] = s2[j];
			i++;
			j++;
		}
	}
	buff[i] = '\0';
	return (buff);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*buff;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == 0)
		return (ft_strdup(s2));
	if (s2 == 0)
		return (ft_strdup(s1));
	if (s1[0] == '\n')
		return (eroor(""), NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	buff = malloc (s1_len + s2_len + 1);
	if (!buff)
		return (free(buff), NULL);
	return (ft_help_join(s1, s2, buff));
}

char	*ft_strdup(char *s)
{
	int		i;
	int		len;
	char	*cpy;

	i = 0;
	len = ft_strlen(s);
	if (s == 0)
		return (0);
	cpy = malloc (sizeof (char) * (len + 1));
	if (!cpy)
		return (free(cpy), NULL);
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
