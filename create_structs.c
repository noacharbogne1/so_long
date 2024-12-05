/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_structs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:44:41 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/05 12:05:32 by ncharbog         ###   ########.fr       */
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
	data->map.c = 0;
	data->map.p = 0;
	data->map.e = 0;
}
