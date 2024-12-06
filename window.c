/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:26:28 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/06 11:11:17 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_loop_end(data->mlx);
		mlx_destroy_window(data->mlx, data->window);
		data->window = NULL;
	}
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
				mlx_put_image_to_window(data->mlx, data->window, data->imgs[0], j * TS, i * TS);
			else if (data->map.map[j][i] == '1')
				mlx_put_image_to_window(data->mlx, data->window, data->imgs[1], j * TS, i * TS);
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
	{
		mlx_destroy_window(data->mlx, data->window);
		data->window = NULL;
	}
	while (i < 5)
	{
		mlx_destroy_image(data->mlx, data->imgs[i]);
		i++;
	}
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

void	window(t_data *data)
{
	int	i;

	i = 0;
	data->mlx = mlx_init();
	if (!data->mlx)
		errors(MLX, data);
	data->window = mlx_new_window(data->mlx, data->map.width * TS, data->map.height * TS, "Window");
	init_imgs(data);
	if (!data->window)
	{
		errors(MLX, data);
		return ;
	}
	render(data);
	mlx_hook(data->window, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data->window, DestroyNotify, StructureNotifyMask, &close_window, &data);
	mlx_loop(data->mlx);
	mlx_destroy_display(data->mlx);
	while (i < 5)
	{
		mlx_destroy_image(data->mlx, data->imgs[i]);
		i++;
	}
	free(data->mlx);
	data->mlx = NULL;
}
