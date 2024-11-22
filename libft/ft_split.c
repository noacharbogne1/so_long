/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:22:33 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/22 10:36:27 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_free(char **dest, int j)
{
	while (j--)
		free(dest[j]);
	free(dest);
}

static int	ft_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (words);
}

static char	*ft_fill(char const *s, char c)
{
	char	*dest;
	int		i;
	int		j;
	int		len;

	i = 0;
	len = 0;
	j = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	dest = malloc((i + 1) * sizeof(char));
	if (dest == NULL)
		return (0);
	i = 0;
	while (j < len)
	{
		dest[j] = s[i + j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

static char	**ft_formed_split(char **dest, char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			dest[j] = ft_fill(&s[i], c);
			if (dest[j] == NULL)
			{
				ft_free(dest, j);
				return (0);
			}
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	dest[j] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;

	if (!s)
		return (0);
	dest = malloc((ft_words(s, c) + 1) * sizeof(char *));
	if (dest == NULL)
		return (0);
	dest = ft_formed_split(dest, s, c);
	return (dest);
}
