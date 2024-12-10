# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 08:31:13 by ncharbog          #+#    #+#              #
#    Updated: 2024/12/10 10:09:11 by ncharbog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

NAME = so_long

SRC = window.c \
	movement.c \
	end_game.c \
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
	libft/ft_strdup.c \
	libft/libft_modified.c

OBJ_DIR = .objects

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

MLX_DIR = mlx_linux

PRINTF_DIR = ft_printf

LIBFT_DIR = libft

OBJ_MLX = $(MLX_DIR)/libmlx.a

OBJ_MLX2 = $(MLX_DIR)/libmlx_Linux.a

OBJ_PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(OBJ_MLX):
	cd $(MLX_DIR) && make

$(OBJ_PRINTF):
	cd $(PRINTF_DIR) && make

$(NAME): $(OBJ) $(OBJ_MLX) $(OBJ_PRINTF) $(OBJ_MLX2)
	$(CC) $(OBJ) $(OBJ_MLX) $(OBJ_PRINTF) -L$(MLX_DIR) -lmlx -L$(PRINTF_DIR) -lftprintf -L/usr/lib -I$(MLX_DIR) -I$(PRINTF_DIR) -lXext -lX11 -lm -lz -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I/usr/include -I$(MLX_DIR) -I$(PRINTF_DIR) -O3 -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(OBJ_MLX) $(OBJ_PRINTF) $(OBJ_MLX2)
	cd $(PRINTF_DIR) && make clean
	find libft -name "*.o" -exec rm -f {} \;
fclean: clean
	rm -f $(NAME)
re:	fclean all

.PHONY: all clean fclean re
