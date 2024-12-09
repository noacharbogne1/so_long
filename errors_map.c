/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:09:11 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/09 17:08:57 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_len(t_data *data)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(data->map.map[i]);
	i++;
	while (data->map.map[i])
	{
		if (len != ft_strlen(data->map.map[i]))
			errors(LEN, data);
		i++;
	}
	return (i);
}

void	check_elems(t_data *data)
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
				errors(CHAR, data);
			j++;
		}
		j = 0;
		i++;
	}
	if (data->map.c < 1 || data->map.e != 1 || data->map.p != 1)
		errors(CHAR2, data);
}

void	check_walls(t_data *data)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (data->map.map[0][len])
		len++;
	while (i < data->map.height)
	{
		while (data->map.map[i][j])
		{
			if (((i == 0 || i == data->map.height - 1)
					|| (j == 0 || j == len - 1)) && data->map.map[i][j] != '1')
				errors(WALLS, data);
			else
				j++;
		}
		j = 0;
		i++;
	}
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
