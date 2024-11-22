/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:32:47 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/22 16:25:08 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

t_buff	*create_list(void)
{
	t_buff	*lst;

	lst = malloc(sizeof(t_buff));
	if (!lst)
		return (NULL);
	lst->next = NULL;
	ft_memset(lst->buffer, 0, sizeof(lst->buffer));
	return (lst);
}

char	**get_map(int fd)
{
	t_buff	*lst;
	t_buff	*new_node;
	t_buff	*tmp;
	char	*str;
	char	**map;
	int		count;
	int		i;

	count = 0;
	i = 0;
	map = NULL;
	lst = create_list();
	new_node = create_list();
	while (1)
	{
		if (read(fd, &new_node->buffer, BUFFER_SIZE) <= 0)
			break;
		else
		{
			count++;
			ft_lstadd_back(&lst, new_node);
			new_node = create_list();
		}
	}
	str = malloc((count * BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (0);
	tmp = lst;
	while (lst)
	{
		str = ft_strcpy(str, lst->buffer, i);
		i = ft_strlen(str);
		lst = lst->next;
	}
	free(new_node);
	ft_lstclear(&tmp);
	map = ft_split(str, '\n');
	free(str);
	return (map);
}

int	check_map(char **map)
{
	int	lines;

	lines = 0;
	if (!check_map_len(map))
		return (0);
	lines = check_map_len(map);
	printf("%d", check_walls(map, lines));
	if (!check_walls(map, lines))
		return (0);
	if (!check_elems(map))
		return (0);
	return (1);
}

void	ft_free_map(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	while (i--)
		free(tab[i]);
	free(tab);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	char	**map;
	int		i;
	int		fd;

	map = NULL;
	i = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd >= 1024 || fd < 0)
			return (0);
		map = get_map(fd);
		close(fd);
		if (!check_map(map))
		{
			ft_free_map(map);
			return (0);
		}
		ft_free_map(map);
	}
}
