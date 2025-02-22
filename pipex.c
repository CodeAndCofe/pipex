/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:56:15 by aferryat          #+#    #+#             */
/*   Updated: 2025/02/22 19:08:01 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	checker(t_pipex *info)
{
	if (info->ac == 1)
	{
		return (-1);
	}
    if ((info->infile = open(info->arv[1], O_RDONLY, 0644)) == -1)
    {
        return (perror("Infile"), -1);
    }
    if ((info->outfile = open(info->arv[4], O_WRONLY | O_CREAT, 0644)) == -1)
    {
        return (-1);
    }
	return (1);
}

int main(int ac, char **av, char **env)
{
    t_pipex *info;

    info = malloc(sizeof(t_pipex));
    info->arv = av;
    info->env = env;
    info->ac = ac;
    info->cmd1 = ft_split(av[2], ' ');
    info->cmd2 = ft_split(av[3], ' ');
    if (checker(info) == -1)
    {
        return (-1);
    }
    if (pipe(info->fd) == -1)
    {
        return (-1);
    }
    info->id = fork();
    if (info->id == -1)
    {
        return (-1);
    }
    manager(info);
    return (freeup(info->cmd1, -1), freeup(info->cmd2, -1), free(info), 0);
}
