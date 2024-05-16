/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:00:53 by sel-bouy          #+#    #+#             */
/*   Updated: 2024/05/16 12:32:40 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_player(t_data *img, int i, int j)
{
	static int	coin;
	static int	door;

	if (img->map1[i][j] == 'E')
		door = 1;
	if (img->map1[i][j] == '1' || img->map1[i][j] == 'E')
		return (1);
	else if (img->map1[i][j] == 'C')
		coin += 1;
	img->map1[i][j] = '1';
	if (img->map1[i][j + 1] != '1')
		ft_player(img, i, j + 1);
	if (img->map1[i][j - 1] != '1')
		ft_player(img, i, j - 1);
	if (img->map1[i - 1][j] != '1')
		ft_player(img, i - 1, j);
	if (img->map1[i + 1][j] != '1')
		ft_player(img, i + 1, j);
	if (door && img->c == coin)
		return (1);
	return (0);
}
