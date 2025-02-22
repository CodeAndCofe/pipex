/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:46:53 by aferryat          #+#    #+#             */
/*   Updated: 2025/02/21 20:08:09 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include "stdio.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_list
{
	int		id;
	int		infile;
	int		outfile;
	int		fd[2];
	char	**arv;
	char	**env;
	char	**cmd1;
	char	**cmd2;
} t_pipex;

char	*ft_strjoin(char *str1, char *str2);
char	*ft_strdup(char	*str);
char	**ft_split(char *str, char sep);
int		ft_strlen(char *str);
int		count_word(char	*str, char sep);
void	freeup(char **sr, int d);
void	manager(t_pipex *info);
int		ft_strncmp(char	*str, char *str2, int len);
char	*character_joiner(char	*str, char c);

#endif