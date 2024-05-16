/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:32:04 by sel-bouy          #+#    #+#             */
/*   Updated: 2023/11/27 11:56:48 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_forms(char sp, va_list params)
{
	int	count;

	count = 0;
	if (sp == 'c')
		count += ft_print_char(va_arg(params, int));
	else if (sp == 'd' || sp == 'i')
		ft_print_numbers(va_arg(params, int), &count);
	else if (sp == 's')
		ft_print_string(va_arg(params, char *), &count);
	else if (sp == 'u')
		ft_print_un_numbers(va_arg(params, unsigned int), &count);
	else if (sp == 'x')
		ft_print_hexl(va_arg(params, unsigned int), &count);
	else if (sp == 'X')
		ft_print_hexu(va_arg(params, unsigned int), &count);
	else if (sp == 'p')
	{
		count += write(1, "0x", 2);
		ft_print_adrs ((unsigned long)va_arg(params, void *), &count);
	}
	else if (sp == '%')
		count += ft_print_char('%');
	else
		count += ft_print_char(sp);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	params;
	int		i;
	int		count;

	va_start(params, s);
	if (write(1, "", 0) < 0)
		return (-1);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			i++;
			count += ft_print_forms(s[i], params);
		}
		else if (s[i] == '%' && s[i + 1] != '%')
		{
		}
		else
			count += ft_print_char(s[i]);
		i++;
	}
	va_end(params);
	return (count);
}
