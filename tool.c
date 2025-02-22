/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:15:15 by aferryat          #+#    #+#             */
/*   Updated: 2025/02/20 15:15:26 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char	*str)
{
	int		i;
	char	*ptr;

	if (str == NULL)
		return (NULL);
	i = 0;
	ptr = malloc(ft_strlen(str) + 1);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	*retuno(char *str1, char *str2)
{
	if (str1 == NULL && str2 != NULL)
		return (str2);
	else if (str2 == NULL && str1 != NULL)
		return (str1);
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*ptr;

	if (str1 == NULL || str2 == NULL)
		return (retuno(str1, str2));
	i = 0;
	j = 0;
	ptr = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	while (str1[i])
	{
		ptr[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		ptr[i + j] = str2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}
