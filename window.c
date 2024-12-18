/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:26:28 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/16 18:40:11 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_press(int keysym, t_data *data)
{
	int			new;

	new = 0;
	if (keysym == XK_Escape)
		errors(NULL, data);
	else if (keysym == XK_w)
		new = data->pos.y - 1;
	else if (keysym == XK_d)
		new = data->pos.x + 1;
	else if (keysym == XK_s)
		new = data->pos.y + 1;
	else if (keysym == XK_a)
		new = data->pos.x - 1;
	if (keysym == XK_w || keysym == XK_s)
		handle_movement_y(data, new);
	else if (keysym == XK_a || keysym == XK_d)
		handle_movement_x(data, new);
	return (0);
}

void	render_game(t_data *data, int y, int x, char c)
{
	void	*img;

	img = NULL;
	if (c == '0')
		img = data->imgs[0];
	else if (c == '1')
		img = data->imgs[1];
	else if (c == 'P')
	{
		img = data->imgs[2];
		data->pos.y = y;
		data->pos.x = x;
	}
	else if (c == 'C')
		img = data->imgs[3];
	else if (c == 'E')
		img = data->imgs[4];
	if (img != NULL)
		mlx_put_image_to_window(data->mlx, data->window, img, x * TS, y * TS);
	else
		errors(RENDER, data);
}

int	render(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (data->window != NULL)
	{
		while (data->map.map[y] && y < data->map.height)
		{
			x = 0;
			while (data->map.map[y][x] && x < data->map.width)
			{
				render_game(data, y, x, data->map.map[y][x]);
				x++;
			}
			y++;
		}
	}
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
	data->window = mlx_new_window(data->mlx, data->map.width * TS,
			data->map.height * TS, "Window");
	if (!data->window)
	{
		errors(MLX, data);
		return ;
	}
	init_imgs(data);
	render(data);
	mlx_key_hook(data->window, handle_press, data);
	mlx_hook(data->window, DestroyNotify, StructureNotifyMask,
		&close_window, data);
	mlx_loop(data->mlx);
}
