/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:39:58 by sel-bouy          #+#    #+#             */
/*   Updated: 2024/05/14 12:41:08 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_bonus.h"

int	move_right(t_data *img)
{
	if (img->map[img->y][img->x + 1] == '0')
	{
		img->map[img->y][img->x] = '0';
		img->map[img->y][img->x + 1] = 'P';
		img->x += 1;
	}
	else if (img->map[img->y][img->x + 1] == 'C')
	{
		img->map[img->y][img->x] = '0';
		img->map[img->y][img->x + 1] = 'P';
		img->x += 1;
		img->c--;
	}
	else if (img->map[img->y][img->x + 1] == 'N')
		eroor("loseeeeer hahaha");
	else if (img->map[img->y][img->x + 1] == 'E' && img->colec == 0)
	{
		write(1, "Congratulation you win\n", 24);
		exit(0);
	}
	else
		return (1);
	return (0);
}

int	move_left(t_data *img)
{
	if (img->map[img->y][img->x - 1] == '0')
	{
		img->map[img->y][img->x] = '0';
		img->map[img->y][img->x - 1] = 'P';
		img->x -= 1;
	}
	else if (img->map[img->y][img->x - 1] == 'C')
	{
		img->map[img->y][img->x] = '0';
		img->map[img->y][img->x - 1] = 'P';
		img->x -= 1;
		img->c--;
	}
	else if (img->map[img->y][img->x - 1] == 'N')
		eroor("loseeeeer hahaha");
	else if (img->map[img->y][img->x - 1] == 'E' && img->colec == 0)
	{
		write(1, "Congratulation you win\n", 24);
		exit(0);
	}
	else
		return (1);
	return (0);
}

int	move_down(t_data *img)
{
	if (img->map[img->y + 1][img->x] == '0')
	{
		img->map[img->y][img->x] = '0';
		img->map[img->y + 1][img->x] = 'P';
		img->y += 1;
	}
	else if (img->map[img->y + 1][img->x] == 'C')
	{
		img->map[img->y][img->x] = '0';
		img->map[img->y + 1][img->x] = 'P';
		img->y += 1;
		img->c--;
	}
	else if (img->map[img->y + 1][img->x] == 'N')
		eroor("loseeeeer hahaha");
	else if (img->map[img->y + 1][img->x] == 'E' && img->colec == 0)
	{
		write(1, "Congratulation you win\n", 24);
		exit(0);
	}
	else
		return (1);
	return (0);
}

int	move_up(t_data *img)
{
	if (img->map[img->y - 1][img->x] == '0')
	{
		img->map[img->y - 1][img->x] = 'P';
		img->map[img->y][img->x] = '0';
		img->y -= 1;
	}
	else if (img->map[img->y - 1][img->x] == 'C')
	{
		img->map[img->y][img->x] = '0';
		img->map[img->y - 1][img->x] = 'P';
		img->y -= 1;
		img->c--;
	}
	else if (img->map[img->y - 1][img->x] == 'N')
		eroor("loseeeeer hahaha");
	else if (img->map[img->y - 1][img->x] == 'E' && img->colec == 0)
	{
		write(1, "Congratulation you win\n", 24);
		exit(0);
	}
	else
		return (1);
	return (0);
}

int	key_press(int keycode, t_data *img)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 13 || keycode == 126)
	{
		if (move_up(img) == 0)
			img->q++;
	}
	if (keycode == 0 || keycode == 123)
	{
		if (move_left(img) == 0)
			img->q++;
	}
	else if (keycode == 1 || keycode == 125)
	{
		if (move_down(img) == 0)
			img->q++;
	}
	else if (keycode == 2 || keycode == 124)
	{
		if (move_right(img) == 0)
			img->q++;
	}
	return (0);
}
