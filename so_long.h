/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noacharbogne <noacharbogne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:56:05 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/04 15:46:53 by noacharbogn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "macros.h"
#include "ft_printf/ft_printf.h"
//#include "mlx_linux/mlx.h"
//#include <X11/X.h>
//#include <X11/keysym.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_buff
{
	struct s_buff	*next;
	char			buffer[BUFFER_SIZE + 2];
}	t_buff;

typedef struct s_elems
{
	int	c;
	int	p;
	int	e;
}	t_elems;

typedef	struct s_pos
{
	int	y;
	int	x;
}	t_pos;

typedef struct s_data
{
	void	*mlx;
	void	*window;
}	t_data;

// Libft
void	ft_lstadd_back(t_buff **lst, t_buff *new);
void	ft_lstclear(t_buff **lst);
t_buff	*ft_lstlast(t_buff *lst);
int		ft_strlen(const char *s);
char	*ft_strcpy(char *dest, char *src, int i);
void	*ft_memset(void *s, int c, size_t n);
char	**ft_split(char const *s, char c);

// parsing.c
t_buff	*create_list(void);
char	**get_map(int fd);
void	ft_free_map(char **tab);
t_elems	create_elems(void);
int		check_elems(char **map, t_elems elems);
int		check_map_len(char **map);
int		check_walls(char **map, int lines);
t_pos	get_pos_p(char **map);
int		access_elems(char **map, t_pos size, t_pos p);
void	flood_fill(char	**tmp, t_pos size, t_pos current, char to_fill);
void	errors(char *msg);
void	check_newline(char *str, t_buff *tmp, t_buff *new_node);
char	*create_str(t_buff *lst, t_buff *new_node, int count);

#endif