# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 21:18:48 by sel-bouy          #+#    #+#              #
#    Updated: 2024/05/07 15:36:02 by sel-bouy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SCRS = ft_all_i_need.c\
		ft_printf.c\
		ft_all_i_need2.c

OBJS = $(SCRS:.c=.o)  #substitution reference

CC = cc -Wall -Wextra -Werror

AR = ar -rc

RM = rm -f

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

all : $(NAME)

%.o: %.c ft_printf.h
	$(CC) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all