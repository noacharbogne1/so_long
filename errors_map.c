/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:09:11 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/22 17:11:59 by ncharbog         ###   ########.fr       */
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

int	check_elems(char **map)
{
	int	i;
	int	j;
	int	e;
	int	p;
	int	c;

	i = 0;
	j = 0;
	e = 0;
	p = 0;
	c = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c++;
			else if (map[i][j] == 'E' && e < 2)
				e++;
			else if (map[i][j] == 'P' && p < 2)
				p++;
			else if (map[i][j] != '0' && map[i][j] != '1')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	if (c >= 1 && e == 1 && p == 1)
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
			if ((i != 0 && i != lines - 1) && (j >= 1 && j <= len - 2) && map[i][j] == '1')
				return (0);
			else
				j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
