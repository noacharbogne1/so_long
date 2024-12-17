/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:21:12 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/17 13:42:19 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_data *data)
{
	data->moves++;
	ft_printf("The total of moves is : %d\n", data->moves);
}

void	handle_movement_y(t_data *data, int new)
{
	if (data->map.c == 0)
		end_game(data, new, data->pos.x);
	if (data->map.map[new][data->pos.x] != '1')
	{
		if (data->map.map[new][data->pos.x] == 'C')
			data->map.c -= 1;
		data->map.map[data->pos.y][data->pos.x] = '0';
		data->map.map[new][data->pos.x] = 'P';
		render_game(data, data->pos.y, data->pos.x, '0');
		render_game(data, new, data->pos.x, 'P');
		data->pos.y = new;
		print_moves(data);
		if (data->map.c == 0)
		{
			data->map.map[data->map.y_e][data->map.x_e] = 'E';
			render_game(data, data->map.y_e, data->map.x_e,
				data->map.map[data->map.y_e][data->map.x_e]);
		}
	}
}

void	handle_movement_x(t_data *data, int new)
{
	if (data->map.c == 0)
		end_game(data, data->pos.y, new);
	if (data->map.map[data->pos.y][new] != '1')
	{
		if (data->map.map[data->pos.y][new] == 'C')
			data->map.c -= 1;
		data->map.map[data->pos.y][data->pos.x] = '0';
		data->map.map[data->pos.y][new] = 'P';
		render_game(data, data->pos.y, data->pos.x, '0');
		render_game(data, data->pos.y, new, 'P');
		data->pos.x = new;
		print_moves(data);
		if (data->map.c == 0)
		{
			data->map.map[data->map.y_e][data->map.x_e] = 'E';
			render_game(data, data->map.y_e, data->map.x_e,
				data->map.map[data->map.y_e][data->map.x_e]);
		}
	}
}
