/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:24:03 by aferryat          #+#    #+#             */
/*   Updated: 2025/02/22 16:26:34 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freeup(char **sr, int d)
{
	int	i;

	i = 0;
	if (d == -1)
	{
		while (sr[i] != NULL)
			i++;
		d = i;
	}
	while (d > 0)
	{
		free(sr[d]);
		d--;
	}
	free(sr);
}

static int	count_word(char	*str, char sep)
{
	int	word;
	int	i;
	
	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] == sep && str[i])
			i++;
		if (str[i])
			word++;
		while (str[i] != sep && str[i])
			i++;
	}
	return (word);
}

static char	*reall_split(char *str, char sep)
{
	char	*ptr;
	int		i;
	

	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	ptr = malloc(i + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (str[i] != sep && str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**ft_split(char *str, char sep)
{
	char	**ptr;
	int		i;
	int		y;

	if (str == NULL)
		return (NULL);
	ptr = malloc((count_word(str, sep) + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	y = 0;
	while (str[y])
	{
		while (str[y] == sep && str[y])
			y++;
		ptr[i] = reall_split(&(str)[y], sep);
		if (ptr[i] == NULL)
			return (freeup(ptr, i), NULL);
		while (str[y] != sep && str[y])
			y++;
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

