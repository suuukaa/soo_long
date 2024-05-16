/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:45:09 by sel-bouy          #+#    #+#             */
/*   Updated: 2024/05/16 14:53:58 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	count(char **h)
{
	int	i;

	i = 0;
	while (h[i])
		i++;
	return (i);
}

void	norm_putimages(t_data *i)
{
	i->i = -1;
	while (i->map[i->j][++i->i])
	{
		if (i->map[i->j][i->i] == '1')
			mlx_put_image_to_window(i->mx, i->m1, i->wa, i->i * 64, i->j * 64);
		else if (i->map[i->j][i->i] == '0')
			mlx_put_image_to_window(i->mx, i->m1, i->fl, i->i * 64, i->j * 64);
		else if (i->map[i->j][i->i] == 'P')
			mlx_put_image_to_window(i->mx, i->m1, i->pl, i->i * 64, i->j * 64);
		else if (i->map[i->j][i->i] == 'C')
		{
			mlx_put_image_to_window(i->mx, i->m1, i->fl, i->i * 64, i->j * 64);
			mlx_put_image_to_window(i->mx, i->m1, i->co, i->i * 64, i->j * 64);
			i->colec++;
		}
		else if (i->map[i->j][i->i] == 'E')
		{
			mlx_put_image_to_window(i->mx, i->m1, i->fl, i->i * 64, i->j * 64);
			llong(i);
		}
	}
}

void	put_image(t_data *img)
{
	img->j = -1;
	img->colec = 0;
	while (img->map[++img->j] != NULL)
		norm_putimages(img);
	if (img->j > 21 || img->i > 40)
		eroor("long map");
}

void	copy_map(t_data *img, char *file)
{
	char	*line;
	char	*join;
	int		fd;

	fd = open(file, O_RDONLY);
	join = get_next_line(fd);
	line = NULL;
	if (!join)
		eroor("empty file");
	while (join)
	{
		line = ft_strjoin(line, join);
		free (join);
		join = get_next_line(fd);
	}
	img->map1 = ft_split(line, '\n');
	free (line);
}

int	main(int ac, char **av)
{
	t_data	img;

	img.s = ft_strlen(av[1]) - 1;
	if (ac != 2)
		eroor("we wanna 2 arguments");
	if (av[1][img.s] != 'r' || av[1][img.s - 1] != 'e'
		|| av[1][img.s - 2] != 'b' || av[1][img.s - 3] != '.')
		eroor("the file must be end with .ber");
	read_line(&img, av[1]);
	copy_map(&img, av[1]);
	images(&img);
	norm(&img);
	if (ft_player(&img, img.a, img.b) == 0)
		eroor("invalid path");
	if (img.wa == NULL || img.fl == NULL || img.d == NULL
		|| img.co == NULL || img.pl == NULL || img.o_d == NULL)
		return (eroor("images are invalid "), 0);
	put_image(&img);
	mlx_hook(img.m1, 2, 0, key_press, &img);
	mlx_hook(img.m1, 17, 0, ft_exit, &img);
	mlx_loop(img.mx);
}
