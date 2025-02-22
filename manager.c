/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:30:36 by aferryat          #+#    #+#             */
/*   Updated: 2025/02/22 19:12:01 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char *access_path(char **str, char *cmd)
{
    char    *stjn;
    char    *new;
    int     i;

    i = 0;
    if (!str || !cmd)
        return (NULL);
    while (str[i])
    {
        new = character_joiner(str[i], '/');
        if (new == NULL)
            return (NULL);
        stjn = ft_strjoin(new, cmd);
        free(new);
        new = NULL;
        if (stjn == NULL)
        {
            return (NULL);
        }
        if (access(stjn, F_OK) == 0)
        {
            return (stjn);
        }
        free(stjn);
        stjn = NULL;
        i++;
    }
    return (NULL);
}

static char *str_find(t_pipex *info)
{
    int     i;
    char    *allpath;

    i = 0;
    while (ft_strncmp(info->env[i], "PATH=", 4) != 0 && info->env[i])
    {
        i++;
    }
    allpath = ft_strdup(&(info->env[i])[5]);
    if (allpath == NULL)
    {
        return (NULL);
    }
    return (allpath);
}

void	process_one(t_pipex *info)
{
	char	*path;
	char	*all;
	char	**paths;

	all = str_find(info);
	if (all == NULL)
		return ;
	paths = ft_split(all, ':');
	if (paths == NULL)
		return ;
	path = access_path(paths, info->cmd1[0]);
	if (path == NULL)
		return ;
	close(info->fd[0]);
	dup2(info->infile, STDIN_FILENO);
	dup2(info->fd[1], STDOUT_FILENO);
	close(info->fd[1]);
	if(execve(path, info->cmd1, NULL) == -1)
		perror("execute:@!\n");
}

void	process_two(t_pipex *info)
{
	char	*path;
	char	*all;
	char	**paths;

	all = str_find(info);
	if (all == NULL)
		return ;
	paths = ft_split(all, ':');
	if (paths == NULL)
		return ;
	path = access_path(paths, info->cmd2[0]);
	if (path == NULL)
		return ;
	close(info->fd[1]);
	dup2(info->outfile, STDOUT_FILENO);
	dup2(info->fd[0], STDIN_FILENO);
	close(info->fd[0]);
	if(execve(path, info->cmd2, NULL) == -1)
		perror("execute:@!\n");
}

void    manager(t_pipex *info)
{
    if (info->id == 0)
    {
        process_one(info);
    }
    info->id = fork();
    if (info->id == -1)
    {
        perror("probleme in fork !)\n");
        return ;
    }
    if (info->id == 0)
    {
        process_two(info);
    }
    wait(NULL);
    wait(NULL);
    close(info->fd[0]);
	close(info->infile);
	close(info->outfile);
}