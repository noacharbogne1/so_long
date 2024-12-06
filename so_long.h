/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:56:05 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/06 10:25:09 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "macros.h"
#include "ft_printf/ft_printf.h"
#include "mlx_linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_buff
{
	struct s_buff	*next;
	char			buffer[BUFFER_SIZE + 2];
}	t_buff;

typedef	struct s_pos
{
	int	y;
	int	x;
}	t_pos;

typedef	struct s_map
{
	char	**map;
	int		c;
	int		p;
	int		e;
	int		width;
	int		height;
}	t_map;


typedef struct s_data
{
	void	*mlx;
	void	*window;
	void	*imgs[5];
	t_map	map;
}	t_data;

// Libft/
void	ft_lstadd_back(t_buff **lst, t_buff *new);
void	ft_lstclear(t_buff **lst);
t_buff	*ft_lstlast(t_buff *lst);
int		ft_strlen(const char *s);
char	*ft_strcpy(char *dest, char *src, int i);
void	*ft_memset(void *s, int c, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);

// parsing.c
char	*create_str(t_buff *lst, t_buff *new_node, int count);
void	check_newline(char *str, t_buff *tmp, t_buff *new_node);
char	**get_map(int fd);
int		check_map(t_data *data);

// parsing2.c
int		check_argv(char *str);
void	ft_free_map(char **tab);

// create_structs.c
t_buff	*create_list(void);
void	init_data(t_data *data);
void	init_imgs(t_data *data);

// errors_map.c
int		check_map_len(t_data *data);
int		check_elems(t_data *data);
int		check_walls(t_data *data);
t_pos	get_pos_p(char **map);

// errors_map2.c
void	flood_fill(char	**tmp, t_pos size, t_pos cur, char to_fill);
int		access_elems(t_data *data, t_pos size, t_pos p);
void	errors(char *msg, t_data *data);

// window.c
int		handle_keypress(int keysym, t_data *data);
int		render_background(t_data *data);
int		render(t_data *data);
int		close_window(t_data *data);
void	window(t_data *data);

#endif