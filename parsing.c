/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:32:47 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/03 11:25:24 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int		j;
	t_elems	elems;
	t_pos	size;
	t_pos	p;

	j = 0;
	if (!check_map_len(map))
		return (0);
	size.y = check_map_len(map);
	if (!check_walls(map, size.y))
		return (0);
	elems = create_elems();
	if (!check_elems(map, elems))
		return (0);
	p = get_pos_p(map);
	while (map[0][j])
		j++;
	size.x = j;
	if (size.y > 30 || size.x > 60)
		return (0);
	if (!access_elems(map, size, p))
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
