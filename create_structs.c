/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_structs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:44:41 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/03 09:45:04 by ncharbog         ###   ########.fr       */
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

t_elems	create_elems(void)
{
	t_elems	elems;

	elems.c = 0;
	elems.p = 0;
	elems.e = 0;
	return (elems);
}
