/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:09:11 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/22 12:53:52 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_len(char **map)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(map[i]);
	i++;
	while (map[i])
	{
		if (len != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
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

int	check_walls(char **map)
{
	int	i;
	int	j;
	int	i_len;
	int	j_len;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	i_len = i;
	while (map[i][j])
		j++;
	j_len = j;
	while (map[0][j])
	{
		if (map[0][j] != '1')
			return (0);
		j--;
	}
	while (map[i_len][j])
	{
		if (map[i_len][j] != '1')
			return (0);
		j++;
	}
	while (map[i][0])
	{
		if (map[i][0] != '1')
			return (0);
		i--;
	}
	while (map[i][j_len])
	{
		if (map[i][j_len] != '1')
			return (0);
		i++;
	}
	return (1);
}
