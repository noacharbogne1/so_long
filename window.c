/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:26:28 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/03 17:13:29 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keysym, void *mlx, void *window)
{
	if (keysym = XK_Escape)
		mlx_destroy_window(mlx, window);
	return (0);
}



void	window(void)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	if (!mlx)
		return ;
	window = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Window");
	if (!window)
	{
		free(window);
		return ;
	}
	mlx_destroy_window(mlx, window);
	mlx_destroy_display(mlx);
	free(mlx);
}