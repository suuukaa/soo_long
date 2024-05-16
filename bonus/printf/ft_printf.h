/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:24:03 by sel-bouy          #+#    #+#             */
/*   Updated: 2023/12/03 15:06:26 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h> 

int		ft_printf(const char *s, ...);
int		ft_print_char(int c);
void	ft_print_numbers(int n, int *size);
void	ft_print_string(char *s, int *size);
void	ft_print_un_numbers(unsigned int n, int *size);
void	ft_print_hexl(unsigned int n, int *size);
void	ft_print_hexu(unsigned int n, int *size);
void	ft_print_adrs(unsigned long n, int *size);

#endif
