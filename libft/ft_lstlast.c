/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:29:39 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/22 10:30:27 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_buff	*ft_lstlast(t_buff *lst)
{
	t_buff	*temp;

	if (!lst)
		return (0);
	temp = lst;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}
