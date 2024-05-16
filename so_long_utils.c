/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:17:11 by sel-bouy          #+#    #+#             */
/*   Updated: 2024/05/16 14:54:35 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	images(t_data *img)
{
	img->wa = "images/wall.xpm";
	img->fl = "images/floor.xpm";
	img->d = "images/door.xpm";
	img->o_d = "images/open_door.xpm";
	img->co = "images/coin.xpm";
	img->pl = "images/player.xpm";
	img->l = ft_strlen(img->map[0]);
	img->m = count(img->map);
}

void	norm(t_data *img)
{
	img->mx = mlx_init();
	img->m1 = mlx_new_window(img->mx, img->l * 64, img->m * 64, "so_long");
	img->wa = mlx_xpm_file_to_image(img->mx, img->wa, &img->y, &img->x);
	img->fl = mlx_xpm_file_to_image(img->mx, img->fl, &img->y, &img->x);
	img->pl = mlx_xpm_file_to_image(img->mx, img->pl, &img->y, &img->x);
	img->co = mlx_xpm_file_to_image(img->mx, img->co, &img->y, &img->x);
	img->d = mlx_xpm_file_to_image(img->mx, img->d, &img->y, &img->x);
	img->o_d = mlx_xpm_file_to_image(img->mx, img->o_d, &img->y, &img->x);
	img->x = x_player(img->map);
	img->y = y_player(img->map);
	img->b = img->x;
	img->a = img->y;
}

int	ft_exit(void)
{
	exit (1);
	return (0);
}

void	eroor(char *str)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit (1);
}

void	llong(t_data *i)
{
	if (i->c != 0)
		mlx_put_image_to_window(i->mx, i->m1, i->d, i->i * 64, i->j * 64);
	else
		mlx_put_image_to_window(i->mx, i->m1, i->o_d, i->i * 64, i->j * 64);
}
