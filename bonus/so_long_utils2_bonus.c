/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:19:35 by sel-bouy          #+#    #+#             */
/*   Updated: 2024/05/14 12:34:21 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_bonus.h"

int	jdida(int n)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	if (n < 0)
	{
		i = 1;
		n *= -1;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	m;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	m = jdida (n);
	res = malloc (sizeof(char) *(m + 1));
	if (!res)
		return (0);
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	res[m] = '\0';
	while (n)
	{
		m--;
		res[m] = (n % 10) + '0';
		n = n / 10;
	}
	return (res);
}

int	moves(t_data *img)
{
	img->res = ft_itoa(img->q);
	mlx_string_put(img->mx, img->m1, 0, 0, 0x000000, "moves = ");
	mlx_string_put(img->mx, img->m1, 80, 0, 0x000000, img->res);
	return (0);
}

int	animation(t_data *i)
{
	put_image(i);
	return (0);
}
