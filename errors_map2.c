/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:18:59 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/05 09:56:43 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char	**tmp, t_pos size, t_pos cur, char to_fill)
{
	if (cur.x < 0 || cur.y < 0 || tmp[cur.y][cur.x] == to_fill)
		return ;
	tmp[cur.y][cur.x] = '1';
	flood_fill(tmp, size, (t_pos){cur.y + 1, cur.x}, to_fill);
	flood_fill(tmp, size, (t_pos){cur.y - 1, cur.x}, to_fill);
	flood_fill(tmp, size, (t_pos){cur.y, cur.x + 1}, to_fill);
	flood_fill(tmp, size, (t_pos){cur.y, cur.x - 1}, to_fill);
}

int	access_elems(char **map, t_pos size, t_pos p)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = map;
	flood_fill(tmp, size, p, '1');
	while (tmp[i])
	{
		while (tmp[i][j])
		{
			if (tmp[i][j] == 'E' || tmp[i][j] == 'C')
				errors(ELEMS, map);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

void	errors(char *msg, char **map)
{
	ft_printf("Error : %s\n", msg);
	if (map)
		ft_free_map(map);
	exit(EXIT_FAILURE);
}
