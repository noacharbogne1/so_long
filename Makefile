# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 08:31:13 by ncharbog          #+#    #+#              #
#    Updated: 2024/12/05 10:23:27 by ncharbog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

NAME = so_long

SRC = window.c \
	parsing.c \
	parsing2.c \
	create_structs.c \
	errors_map.c \
	errors_map2.c \
	libft/ft_lstadd_back.c \
	libft/ft_lstlast.c \
	libft/ft_memset.c \
	libft/ft_split.c \
	libft/ft_strlen.c \
	libft/libft_modified.c

OBJ = $(SRC:.c=.o)

MLX_DIR = mlx_linux

PRINTF_DIR = ft_printf

OBJ_MLX = $(MLX_DIR)/libmlx_Linux.a

OBJ_PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MLX) $(OBJ_PRINTF)
	$(CC) $(OBJ) $(OBJ_MLX) $(OBJ_PRINTF) -L$(MLX_DIR) -lmlx_Linux -L$(PRINTF_DIR) -lftprintf -L/usr/lib -I$(MLX_DIR) -I$(PRINTF_DIR) -lXext -lX11 -lm -lz -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -I$(MLX_DIR) -I$(PRINTF_DIR) -O3 -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_MLX) $(OBJ_PRINTF)
fclean: clean
	rm -f $(NAME)
re:	fclean all

.PHONY: all clean fclean re