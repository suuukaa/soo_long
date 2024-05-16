# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 10:50:28 by sel-bouy          #+#    #+#              #
#    Updated: 2024/05/16 15:07:02 by sel-bouy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -fsanitize=address  -g
LIB = ./printf/libftprintf.a
LIB_BONUS = ./bonus/printf/libftprintf.a

SRC =  check_map.c ft_player.c ft_split.c player_moves.c position_player.c so_long.c\
		get_next_line.c get_next_line_utils.c so_long_utils.c

SRC_BONUS = ./bonus/check_map_bonus.c ./bonus/ft_player_bonus.c\
			./bonus/ft_split_bonus.c ./bonus/player_moves_bonus.c\
			./bonus/position_player_bonus.c ./bonus/so_long_bonus.c \
			./bonus/get_next_line.c ./bonus/get_next_line_utils.c \
			./bonus/so_long_utils_bonus.c ./bonus/so_long_utils2_bonus.c 

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: printf_first $(NAME)

%.o: %.c lib.h bonus/lib_bonus.h
	$(CC) -c $< -o $@

printf_first:
	@cd printf && make

bonus : printfbonus_first $(NAME_BONUS)

printfbonus_first:
	@cd ./bonus/printf && make

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIB) $(MLXFLAGS) -o $(NAME)
	
$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) $(LIB_BONUS) $(MLXFLAGS) -o $(NAME_BONUS)

clean:
	@cd printf && make clean
	@cd bonus/printf && make clean
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)
	
fclean: clean
	@cd printf && make fclean
	@cd bonus/printf && make fclean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)
	
re: fclean all