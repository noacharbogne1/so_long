/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:18:59 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/05 08:30:28 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	errors(char *msg, char **map)
{
	ft_printf("Error : %s\n", msg);
	if (map)
		ft_free_map(map);
	exit(EXIT_FAILURE);
}
