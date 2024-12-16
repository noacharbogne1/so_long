/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:01:27 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/16 17:58:04 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_argv(char *str)
{
	int		i;
	int		j;
	char	*ber;

	i = 0;
	j = 0;
	ber = ".ber";
	while (str[i])
		i++;
	if (i == 4)
		errors (ARGV, NULL);
	i = i - 4;
	while (str[i])
	{
		while (str[i + j] == ber[j])
		{
			j++;
			if (ber[j] == '\0')
				return (1);
		}
		i++;
	}
	errors(ARGV, NULL);
	return (0);
}

void	ft_free_map(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	while (i--)
		free(tab[i]);
	free(tab);
}

void	get_pos_e(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map.map[j])
	{
		while(data->map.map[j][i])
		{
			if (data->map.map[j][i] == 'E')
			{
				data->map.y_e = j;
				data->map.x_e = i;
				data->map.map[j][i] = '0';
				return ;
			}
			i++;
		}
		j++;
		i = 0;
	}
}
