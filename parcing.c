/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:32:47 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/21 17:49:33 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

t_buff	*create_list(void)
{
	t_buff	*lst;

	lst = malloc(sizeof(t_buff));
	if (!lst)
		return (NULL);
	lst->next = NULL;
	lst->buffer[BUFFER_SIZE + 1] = 0;
	return (lst);
}

char	*get_map(int fd)
{
	t_buff	*lst;
	t_buff	*new_node;
	t_buff	*tmp;
	char	*str;
	int		count;
	int		b;
	int		i;

	count = 0;
	b = 0;
	i = 0;
	lst = create_list();
	new_node = create_list();
	while (1)
	{
		b = read(fd, &new_node->buffer, BUFFER_SIZE);
		if (b <= 0)
			break;
		count++;
		ft_lstadd_back(&lst, new_node);
		new_node = create_list();
	}
	str = malloc(((count - 1) * BUFFER_SIZE + ft_strlen(ft_lstlast(lst)->buffer)) * sizeof(char));
	if (!str)
		return (0);
	tmp = lst;
	while (lst)
	{
		str = ft_strcnpy(str + i, lst->buffer, BUFFER_SIZE);
		i += ft_strlen(str);
		lst = lst->next;
	}
	free (new_node);
	ft_lstclear(&tmp);
	return (str);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*str;
	int		fd;

	str = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		str = get_map(fd);
		printf("%s", str);
		free(str);
		close(fd);
	}
}