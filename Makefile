# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 08:31:13 by ncharbog          #+#    #+#              #
#    Updated: 2024/12/04 10:50:37 by ncharbog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

NAME = so_long

SRC = window.c

OBJ = $(SRC:.c=.o)

MLX_DIR = mlx_linux

OBJ_MLX = $(MLX_DIR)/libmlx_Linux.a

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MLX)
	$(CC) $(OBJ) $(OBJ_MLX) -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -I$(MLX_DIR) -O3 -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_MLX)
fclean: clean
	rm -f $(NAME)
re:	fclean all

.PHONY: all clean fclean re