/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_structs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:44:41 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/09 12:29:46 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_buff	*create_list(void)
{
	t_buff	*lst;

	lst = malloc(sizeof(t_buff));
	if (!lst)
		return (NULL);
	lst->next = NULL;
	ft_memset(lst->buffer, 0, sizeof(lst->buffer));
	return (lst);
}

void	init_data(t_data *data)
{
	int	i;

	i = 0;
	data->mlx = NULL;
	data->window = NULL;
	while (i < 5)
	{
		data->imgs[i] = NULL;
		i++;
	}
	data->moves = 0;
	data->map.c = 0;
	data->map.p = 0;
	data->map.e = 0;
}

void	init_imgs(t_data *data)
{
	int	square;

	square = 32;
	if (data->window)
	{
		data->imgs[0] = mlx_xpm_file_to_image(data->mlx, PATH_BG, &square, &square);
		if (!data->imgs[0])
			errors(BG, data);
		data->imgs[1] = mlx_xpm_file_to_image(data->mlx, PATH_WALLS, &square, &square);
		if (!data->imgs[1])
			errors(WALLS_IMG, data);
		data->imgs[2] = mlx_xpm_file_to_image(data->mlx, PATH_P, &square, &square);
		if (!data->imgs[2])
			errors(P, data);
		data->imgs[3] = mlx_xpm_file_to_image(data->mlx, PATH_C, &square, &square);
		if (!data->imgs[3])
			errors(C, data);
		data->imgs[4] = mlx_xpm_file_to_image(data->mlx, PATH_E, &square, &square);
		if (!data->imgs[4])
			errors(E, data);
	}
}
