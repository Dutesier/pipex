/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:04:27 by dareias-          #+#    #+#             */
/*   Updated: 2021/09/22 10:51:49 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex.h"

char *ft_findpath(char **envp)
{
	int i;

	i = 0;
	while (ft_strcmp(envp[i], "PATH", 4) == 0)
		i++;
	return (envp[i]);
}

char *ft_newpath(char *cmd, char **envp)
{
	int		i;
	char	**path;
	char	*full_cmd;

	i = 0;
	path = ft_split(ft_findpath(envp), ':');
	while (path[i] != NULL)
	{
		full_cmd = ft_append(path[i], cmd);
		if (access(full_cmd, F_OK) == 0)
			return (full_cmd);
		free(full_cmd);
		i++;
	}
	return (NULL);
}
