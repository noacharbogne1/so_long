/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:18:59 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/16 18:15:36 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_tmp(t_data *data)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = malloc((data->map.height + 1) * sizeof(char *));
	if (!tmp)
		return (0);
	while (i < data->map.height)
	{
		tmp[i] = ft_strdup(data->map.map[i]);
		if (!tmp[i])
		{
			while (i > 0)
			{
				free(tmp[i]);
				i--;
			}
			free(tmp);
		}
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

void	flood_fill(char	**tmp, t_pos size, t_pos cur, char to_fill)
{
	if (cur.x < 0 || cur.y < 0 || cur.x >= size.x || cur.y >= size.y
		|| tmp[cur.y][cur.x] == to_fill)
		return ;
	tmp[cur.y][cur.x] = '1';
	flood_fill(tmp, size, (t_pos){cur.y + 1, cur.x}, to_fill);
	flood_fill(tmp, size, (t_pos){cur.y - 1, cur.x}, to_fill);
	flood_fill(tmp, size, (t_pos){cur.y, cur.x + 1}, to_fill);
	flood_fill(tmp, size, (t_pos){cur.y, cur.x - 1}, to_fill);
}

void	access_elems(t_data *data, t_pos size, t_pos p)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = get_tmp(data);
	flood_fill(tmp, size, p, '1');
	while (tmp[i])
	{
		while (tmp[i][j])
		{
			if (tmp[i][j] == 'E' || tmp[i][j] == 'C')
			{
				ft_free_map(tmp);
				errors(ELEMS, data);
			}
			j++;
		}
		i++;
		j = 0;
	}
	ft_free_map(tmp);
}

void	errors(char *msg, t_data *data)
{
	int	i;

	i = 0;
	if (msg)
		ft_printf("Error\n%s", msg);
	if (data)
	{
		while (i < 5)
		{
			if (data->mlx && data->imgs[i])
				mlx_destroy_image(data->mlx, data->imgs[i]);
			i++;
		}
		if (data->mlx)
		{
			if (data->window)
				mlx_destroy_window(data->mlx, data->window);
			mlx_destroy_display(data->mlx);
			free(data->mlx);
		}
		if (data->map.map)
			ft_free_map(data->map.map);
	}
	exit(EXIT_FAILURE);
}
