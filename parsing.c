/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:32:47 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/05 08:39:32 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	check_argv(char *str)
{
	int		i;
	int		j;
	char	*ber;

	i = 0;
	j = 0;
	ber = ".ber";
	while (str[i])
		i++;
	if (i == 4)
		errors (ARGV, NULL);
	i = i - 4;
	while (str[i])
	{
		while (str[i + j] == ber[j])
		{
			j++;
			if (ber[j] == '\0')
				return (1);
		}
		i++;
	}
	errors(ARGV, NULL);
	return (0);
}

char	*create_str(t_buff *lst, t_buff *new_node, int count)
{
	t_buff	*tmp;
	char	*str;
	int		i;

	i = 0;
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
	check_newline(str, tmp, new_node);
	return (str);
}
void	check_newline(char *str, t_buff *tmp, t_buff *new_node)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '\n')
		{
			free(str);
			ft_lstclear(&tmp);
			free(new_node);
			errors(NEWLINE, NULL);
		}
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			free(str);
			ft_lstclear(&tmp);
			free(new_node);
			errors(NEWLINE, NULL);
		}
		i++;
	}
	free(new_node);
	ft_lstclear(&tmp);
}

char	**get_map(int fd)
{
	t_buff	*lst;
	t_buff	*new_node;
	char	*str;
	char	**map;
	int		count;

	count = 0;
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
	str = create_str(lst, new_node, count);
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
	check_map_len(map);
	size.y = check_map_len(map);
	check_walls(map, size.y);
	elems = create_elems();
	check_elems(map, elems);
	p = get_pos_p(map);
	while (map[0][j])
		j++;
	size.x = j;
	if (size.y > 30 || size.x > 60) // à vérifier
		return (0);
	access_elems(map, size, p);
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

int	main(int argc, char **argv)
{
	char	**map;
	int		fd;

	map = NULL;
	if (argc == 2)
	{
		check_argv(argv[1]);
		fd = open(argv[1], O_RDONLY);
		if (fd >= 1024 || fd < 0)
			return (0);
		map = get_map(fd);
		close(fd);
		check_map(map);
		ft_free_map(map);
	}
}
