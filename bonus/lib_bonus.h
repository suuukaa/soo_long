/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:07:08 by sel-bouy          #+#    #+#             */
/*   Updated: 2024/05/15 20:25:08 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_BONUS_H
# define LIB_BONUS_H

# include "get_next_line.h"
# include "printf/ft_printf.h"
# include <libc.h>
# include <mlx.h>

typedef struct s_data
{
	int		y;
	int		x;
	int		i;
	int		j;
	int		c;
	int		colec;
	int		cc;
	int		a;
	int		b;
	int		endian;
	int		l;
	int		m;
	int		s;
	int		q;
	void	*img;
	void	*m1;
	void	*mx;
	char	*addr;
	char	**map;
	char	**map1;
	char	*wa;
	char	*fl;
	char	*d;
	char	*o_d;
	char	*co;
	char	*pl;
	char	*en;
	char	*en_r;
	char	*en_l;
	char	*ens[3];
	char	*res;
}				t_data;

int		check_line(t_data *img);
int		check_10epc(char *linee, int j);
void	read_line(t_data *img, char *file);
int		check_epc(t_data *img, int i, int j);
char	**ft_split(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t n);
int		count(char **h);
int		key_press(int keycode, t_data *img);
int		move_up(t_data *img);
int		move_down(t_data *img);
int		move_left(t_data *img);
int		move_right(t_data *img);
int		y_player(char **map);
int		x_player(char **map);
int		ft_player(t_data *img, int i, int j);
void	put_image(t_data *img);
char	*ft_strdup(char *s);
int		ft_exit(void);
void	images(t_data *img);
void	norm(t_data *img);
void	eroor(char *str);
void	ft_freee(t_data *img);
void	ft_2free(t_data *img);
void	norm_putimages(t_data *img, int k);
int		check(t_data *img);
void	llong(t_data *i);
char	*ft_itoa(int n);
int		jdida(int n);
int		moves(t_data *img);
int		animation(t_data *i);
int		enemy(t_data *img);
void	p_player(t_data *img);

#endif