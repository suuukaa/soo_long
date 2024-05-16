/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_i_need2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:19:23 by sel-bouy          #+#    #+#             */
/*   Updated: 2023/11/23 11:23:06 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

void	ft_print_string(char *s, int *size)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		(*size) = 6;
		return ;
	}
	while (s[i])
	{
		ft_print_char(s[i]);
		i++;
		(*size)++;
	}
}
