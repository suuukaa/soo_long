/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:14:32 by sel-bouy          #+#    #+#             */
/*   Updated: 2024/05/14 11:41:14 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	check_epc(t_data *img, int i, int j)
{
	int	e;
	int	p;

	e = 0;
	img->c = 0;
	p = 0;
	while (img->map[i])
	{
		j = -1;
		while (img->map[i][++j])
		{
			if (img->map[i][j] == 'P')
				p++;
			if (img->map[i][j] == 'E')
				e++;
			if (img->map[i][j] == 'C')
				img->c++;
		}
		i++;
	}
	if (p != 1 || e != 1 || img->c < 1)
		return (eroor("invalid content"), 0);
	return (0);
}

void	read_line(t_data *img, char *file)
{
	char	*line;
	char	*join;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		eroor("file not opened");
	join = get_next_line(fd);
	line = NULL;
	if (!join)
		eroor("read line error");
	while (join)
	{
		line = ft_strjoin(line, join);
		free(join);
		join = get_next_line(fd);
	}
	img->map = ft_split(line, '\n');
	free(line);
	check_line(img);
}

int	check_10epc(char *linee, int j)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (linee[k])
		k++;
	k--;
	if (linee[0] == '1' && linee[k] == '1' && j == k)
	{
		while (linee[i])
		{
			if (linee[i] != '1' && linee[i] != '0' && linee[i] != 'E'
				&& linee[i] != 'P' && linee[i] != 'C')
				return (1);
			i++;
		}
	}
	else
		return (1);
	return (0);
}

int	check_line(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (img->map[i])
		i++;
	if (i == 0)
		eroor("empty file");
	while (img->map[0][j] && img->map[i - 1][j])
	{
		if ((img->map[0][j] != '1' && img->map[0][j] != '\n')
			|| img->map[0][j] == '\n')
			return (eroor("must be surrounded by walls"), 0);
		if ((img->map[i - 1][j] != '1' && img->map[i - 1][j] != '\n'
			&& img->map[0][j] == '\0'))
			return (eroor("must be surrounded by walls"), 0);
		j++;
	}
	check(img);
	check_epc(img, 1, 0);
	return (0);
}

int	check(t_data *img)
{
	int	i;

	i = 1;
	while (img->map[i])
	{
		if (check_10epc(img->map[i], ft_strlen(img->map[0]) - 1) == 1)
			return (eroor("len error"), 0);
		i++;
	}
	return (0);
}
