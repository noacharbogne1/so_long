/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:32:47 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/05 11:13:31 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

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

int	check_map(t_data *data)
{
	int		j;
	t_pos	size;
	t_pos	p;

	j = 0;
	check_map_len(data->map.map);
	size.y = check_map_len(data->map.map);
	check_walls(data->map.map, size.y);
	check_elems(data);
	p = get_pos_p(data->map.map);
	while (data->map.map[0][j])
		j++;
	size.x = j;
	if (size.y > 30 || size.x > 60) // à vérifier
		return (0);
	access_elems(data->map.map, size, p);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;

	init_data(&data);
	if (argc == 2)
	{
		check_argv(argv[1]);
		fd = open(argv[1], O_RDONLY);
		if (fd >= 1024 || fd < 0)
			return (0);
		data.map.map = get_map(fd);
		close(fd);
		check_map(&data);
		window(&data);
		ft_free_map(data.map.map);
	}
}
