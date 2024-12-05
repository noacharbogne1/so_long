/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:26:28 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/05 12:08:11 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->window);
		data->window = NULL;
	}
	return (0);
}

int	render_background(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (data->map.map[x] && i < WINDOW_HEIGHT)
	{
		j = 0;
		while (data->map.map[x][y])
		{
			if (data->map.map[x][y] != '1' && j < WINDOW_WIDTH)
			{
				mlx_put_image_to_window(data->mlx, data->window, data->imgs[0], j, i);
				j += 32;
			}
			y++;
		}
		x++;
		i += 32;
	}
	return (0);
}

int	render(t_data *data)
{
	int	square;

	square = 32;
	if (data->window != NULL)
	{
		data->imgs[0] = mlx_xpm_file_to_image(data->mlx, PATH_BG, &square, &square);
		if (!data->imgs[0])
			errors(BG, data->map.map);
		render_background(data);
	}
	return (0);
}

int	close_window(t_data *data)
{
	if (data->window != NULL)
	{
		mlx_destroy_window(data->mlx, data->window);
		data->window = NULL;
	}
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

void	window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		errors(MLX, data->map.map);
	data->window = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Window");
	if (!data->window)
	{
		free(data->window);
		return ;
	}
	mlx_loop_hook(data->mlx, &render, &data);
	mlx_hook(data->window, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data->window, DestroyNotify, StructureNotifyMask, &close_window, &data);
	mlx_loop(data->mlx);
	mlx_destroy_display(data->mlx);
	mlx_destroy_image(data->mlx, data->imgs[0]);
	free(data->imgs[0]);
	free(data->mlx);
}
