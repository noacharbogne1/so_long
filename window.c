/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:26:28 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/06 16:12:27 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		errors(NULL, data);
	return (0);
}

int	render_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map.map[j] && j < data->map.height)
	{
		i = 0;
		while (data->map.map[j][i] && i < data->map.width)
		{
			if (data->map.map[j][i] != '1')
				mlx_put_image_to_window(data->mlx, data->window, data->imgs[0], i * TS, j * TS);
			else if (data->map.map[j][i] == '1')
				mlx_put_image_to_window(data->mlx, data->window, data->imgs[1], i * TS, j * TS);
			i++;
		}
		j++;
	}
	return (0);
}

int	render(t_data *data)
{
	int	square;

	square = 32;
	if (data->window != NULL)
		render_background(data);
	return (0);
}

int	close_window(t_data *data)
{
	int	i;

	i = 0;
	if (data->window != NULL)
		errors(NULL, data);
	return (0);
}

void	window(t_data *data)
{
	int	i;

	i = 0;
	data->mlx = mlx_init();
	if (!data->mlx)
		errors(MLX, data);
	data->window = mlx_new_window(data->mlx, data->map.width * TS, data->map.height * TS, "Window");
	if (!data->window)
	{
		errors(MLX, data);
		return ;
	}
	init_imgs(data);
	render(data);
	mlx_key_hook(data->window, handle_keypress, data);
	mlx_hook(data->window, DestroyNotify, StructureNotifyMask, &close_window, data);
	mlx_loop(data->mlx);
}
