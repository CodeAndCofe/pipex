/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:15:38 by aferryat          #+#    #+#             */
/*   Updated: 2025/02/23 13:36:12 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(char	*str, char *str2, int len)
{
	int	i;

	i = 0;
	while (str[i] == str2[i] && i < len)
		i++;
	return (str[i] - str2[i]);
}

char	*character_joiner(char	*str, char c)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(ft_strlen(str) + 2);
	if (new == NULL)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = c;
	new[i + 1] = '\0';
	return (new);
}

void	fstrct(t_pipex *st)
{
	freeup(st->cmd1, -1);
	freeup(st->cmd2, -1);
	free(st);
}

void	ft_putstr(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}