/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_i_need.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:06:26 by sel-bouy          #+#    #+#             */
/*   Updated: 2024/05/09 19:38:12 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_numbers(int n, int *size)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*size) = 11;
	}
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
			(*size) = 1;
		}
		if (n <= 9)
		{
			(*size)++;
			n = n + '0';
			write(1, &n, 1);
		}
		else
		{
			ft_print_numbers(n / 10, size);
			ft_print_numbers(n % 10, size);
		}
	}
}

void	ft_print_un_numbers(unsigned int n, int *size)
{
	if (n <= 9)
	{
		n = n + '0';
		write(1, &n, 1);
		(*size)++;
	}
	else
	{
		ft_print_un_numbers (n / 10, size);
		ft_print_un_numbers (n % 10, size);
	}
}

void	ft_print_hexl(unsigned int n, int *size)
{
	if (n < 16)
	{
		ft_print_char("0123456789abcdef"[n]);
		(*size)++;
	}
	else
	{
		ft_print_hexl (n / 16, size);
		ft_print_hexl (n % 16, size);
	}
}

void	ft_print_hexu(unsigned int n, int *size)
{
	if (n < 16)
	{
		ft_print_char ("0123456789ABCDEF"[n]);
		(*size)++;
	}
	else
	{
		ft_print_hexu (n / 16, size);
		ft_print_hexu (n % 16, size);
	}
}

void	ft_print_adrs(unsigned long n, int *size)
{
	if (n < 16)
	{
		ft_print_char ("0123456789abcdef"[n]);
		(*size)++;
	}
	else
	{
		ft_print_adrs (n / 16, size);
		ft_print_adrs (n % 16, size);
	}
}
