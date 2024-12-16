/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:09:33 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/16 18:48:47 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(t_data *data, int y, int x)
{
	data->map.map[data->map.y_e][data->map.x_e] = 'E';
	render_game(data, data->map.y_e, data->map.x_e,
	data->map.map[data->map.y_e][data->map.x_e]);
	if (data->map.map[y][x] == 'E')
	{
		print_moves(data);
		errors(NULL, data);
	}
}
