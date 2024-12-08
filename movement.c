/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:21:12 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/09 17:09:51 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_data *data)
{
	data->moves++;
	ft_printf("The total of moves is : %d\n", data->moves);
}

void	handle_e_y(t_data *data, int new)
{
	char	c;
	char	d;

	if (data->map.map[new][data->pos.x] != '1')
	{
		if (data->map.map[new][data->pos.x] == 'C')
			data->map.c -= 1;
		data->map.map[data->pos.y][data->pos.x] = 'E';
		data->map.map[new][data->pos.x] = 'P';
		c = data->map.map[data->pos.y][data->pos.x];
		d = data->map.map[new][data->pos.x];
		render_game(data, data->pos.y, data->pos.x, c);
		render_game(data, new, data->pos.x, d);
		data->pos.y = new;
		print_moves(data);
	}
	data->map.e = 1;
}

void	handle_e_x(t_data *data, int new)
{
	char	c;
	char	d;

	if (data->map.map[data->pos.y][new] != '1')
	{
		if (data->map.map[data->pos.y][new] == 'C')
			data->map.c -= 1;
		data->map.map[data->pos.y][data->pos.x] = 'E';
		data->map.map[data->pos.y][new] = 'P';
		c = data->map.map[data->pos.y][data->pos.x];
		d = data->map.map[data->pos.y][new];
		render_game(data, data->pos.y, data->pos.x, c);
		render_game(data, data->pos.y, new, d);
		data->pos.x = new;
		print_moves(data);
	}
	data->map.e = 1;
}

void	handle_movement_y(t_data *data, int new)
{
	char	c;
	char	d;

	if (data->map.e == 2)
		handle_e_y(data, new);
	if (data->map.map[new][data->pos.x] != '1')
	{
		if (data->map.map[new][data->pos.x] == 'C')
			data->map.c -= 1;
		if (data->map.map[new][data->pos.x] == 'E')
			end_game(data);
		data->map.map[data->pos.y][data->pos.x] = '0';
		data->map.map[new][data->pos.x] = 'P';
		c = data->map.map[data->pos.y][data->pos.x];
		d = data->map.map[new][data->pos.x];
		render_game(data, data->pos.y, data->pos.x, c);
		render_game(data, new, data->pos.x, d);
		data->pos.y = new;
		print_moves(data);
	}
}

void	handle_movement_x(t_data *data, int new)
{
	char	c;
	char	d;

	if (data->map.e == 2)
		handle_e_x(data, new);
	if (data->map.map[data->pos.y][new] != '1')
	{
		if (data->map.map[data->pos.y][new] == 'C')
			data->map.c -= 1;
		if (data->map.map[data->pos.y][new] == 'E')
			end_game(data);
		data->map.map[data->pos.y][data->pos.x] = '0';
		data->map.map[data->pos.y][new] = 'P';
		c = data->map.map[data->pos.y][data->pos.x];
		d = data->map.map[data->pos.y][new];
		render_game(data, data->pos.y, data->pos.x, c);
		render_game(data, data->pos.y, new, d);
		data->pos.x = new;
		print_moves(data);
	}
}
