/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:28:00 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/22 10:30:31 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*adress;

	adress = (unsigned char *)s;
	while (n > 0)
	{
		*adress = c;
		adress++;
		n--;
	}
	return (s);
}
