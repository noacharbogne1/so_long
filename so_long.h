/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:56:05 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/21 17:50:41 by ncharbog         ###   ########.fr       */
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
char	*get_map(int fd);
void	ft_lstadd_back(t_buff **lst, t_buff *new);
void	ft_lstclear(t_buff **lst);
t_buff	*ft_lstlast(t_buff *lst);
size_t	ft_strlen(const char *s);
char	*ft_strcnpy(char *dest, char *src, int len);

#endif