/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:26:28 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/04 12:05:17 by ncharbog         ###   ########.fr       */
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

int	render_background(void *img, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < WINDOW_HEIGHT)
	{
		while (j < WINDOW_WIDTH)
			mlx_xpm_file_to_image(data->mlx, PATH_BG, i, j);
		j = 0;
		i++;
	}
	return (0);
}

int	render(t_data *data)
{
	void	*img;

	if (data->window != NULL)
	{
		img = mlx_xpm_file_to_image(data->mlx, PATH_BG, SQUARE, SQUARE);
		if (!img)
			return (0);
		render_background(data, img);
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

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (0);
	data.window = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Window");
	if (!data.window)
	{
		free(data.window);
		return (0);
	}
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.window, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.window, DestroyNotify, StructureNotifyMask, &close_window, &data);
	mlx_loop(data.mlx);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}
