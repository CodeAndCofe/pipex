/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:46:33 by aferryat          #+#    #+#             */
/*   Updated: 2025/02/22 06:24:40 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


static int	checker(char **av, int ac)
{
	if (ac == 1)
	{
		av = NULL;
		printf("error\n");
		return (-1);
	}
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*info;

	info = malloc(sizeof(t_pipex));
	info->arv = av;
	info->env = envp;
	info->cmd1 = ft_split(av[2], ' ');
	info->cmd2 = ft_split(av[3], ' ');
	if ((info->infile = open(av[0], O_RDONLY | O_CREAT, 0644)) == -1)
		return (-1);
	if ((info->outfile = open(av[4], O_WRONLY | O_CREAT, 0644)) == -1)
		return (-1);
	if (checker(info->arv, ac) == -1)
		return (0);
	if (pipe(info->fd) == -1)
		return (0);
	info->id = fork();
	if (info->id == -1)
		return (0);
	manager(info);
	free(info);
}
