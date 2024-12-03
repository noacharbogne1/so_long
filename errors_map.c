/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:09:11 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/03 11:28:35 by ncharbog         ###   ########.fr       */
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
			return (0);
		i++;
	}
	if (len == i)
		return (0);
	return (i);
}

int	check_elems(char **map, t_elems elems)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				elems.c++;
			else if (map[i][j] == 'E' && elems.e < 2)
				elems.e++;
			else if (map[i][j] == 'P' && elems.p < 2)
				elems.p++;
			else if (map[i][j] != '0' && map[i][j] != '1')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	if (elems.c >= 1 && elems.e == 1 && elems.p == 1)
		return (1);
	return (0);
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
				return (0);
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
				pos.x = i;
				pos.y = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (pos);
}

void	flood_fill(char	**tmp, t_pos size, t_pos p)
{

}

int	access_elems(char **map, t_pos size, t_pos p)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = map;
	flood_fill(tmp, size, p, 1);
	while (tmp[i])
	{
		while (tmp[i][j])
		{
			if (tmp[i][j] == 'E' || tmp[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	free(tmp);
	return (1);
}
