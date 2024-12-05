/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:09:11 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/05 11:17:04 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_len(char **map)
{
	int		i;
	int	len;

	i = 0;
	len = ft_strlen(map[i]);
	i++;
	while (map[i])
	{
		if (len != ft_strlen(map[i]))
			errors(LEN, map);
		i++;
	}
	return (i);
}

int	check_elems(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data->map.map[i])
	{
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'C')
				data->map.c++;
			else if (data->map.map[i][j] == 'E' && data->map.e < 2)
				data->map.e++;
			else if (data->map.map[i][j] == 'P' && data->map.p < 2)
				data->map.p++;
			else if (data->map.map[i][j] != '0' && data->map.map[i][j] != '1')
				errors(CHAR, data->map.map);
			j++;
		}
		j = 0;
		i++;
	}
	if (data->map.c < 1 || data->map.e != 1 || data->map.p != 1)
		errors(CHAR2, data->map.map);
	return (1);
}

int	check_walls(char **map, int lines)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (map[0][len])
		len++;
	while (i < lines)
	{
		while (map[i][j])
		{
			if (((i == 0 || i == lines - 1) || (j == 0 || j == len - 1)) && map[i][j] != '1')
				errors(WALLS, map);
			else
				j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

t_pos	get_pos_p(char **map)
{
	t_pos	pos;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				pos.x = j;
				pos.y = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (pos);
}
