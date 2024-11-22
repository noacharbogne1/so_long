/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:56:05 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/22 16:34:37 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

typedef struct s_buff
{
	struct s_buff	*next;
	char			buffer[BUFFER_SIZE + 2];
}	t_buff;

t_buff	*create_list(void);
char	**get_map(int fd);
void	ft_lstadd_back(t_buff **lst, t_buff *new);
void	ft_lstclear(t_buff **lst);
t_buff	*ft_lstlast(t_buff *lst);
int	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, char *src, int i);
void	*ft_memset(void *s, int c, size_t n);
char	**ft_split(char const *s, char c);
void	ft_free_map(char **tab);
int		check_elems(char **map);
int		check_map_len(char **map);
int		check_walls(char **map, int lines);

#endif