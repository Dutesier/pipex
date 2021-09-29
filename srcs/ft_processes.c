/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:20:29 by dareias-          #+#    #+#             */
/*   Updated: 2021/09/29 11:46:59 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex.h"

int ft_processes(char *argv[], char **envp)
{
	int child_1; // Takes infile as input and pipes execve to child_2 as output
	int child_2; // Takes child_1 output as input and outputs execve to outfile
	int fd[2]; // fd[0] to read from child_1 and fd[1] to write to child_2

	if (pipe(fd) == -1)
		return (1);
	child_1 = fork();
	if (child_1 < 0)
		return (2);
	if (child_1 == 0) // means we are in child 1
	{
		ft_first(fd, argv, envp);
	}
	child_2 = fork();
	if (child_2 < 0)
		return (3);
	if (child_2 == 0)
	{
		wait(NULL);
		ft_second(fd, argv, envp);
	}
	return (0);
}

int ft_first(int fd[], char *argv[], char **envp)
{
	// rerout stdin to infile
	int		in;
	int		ret;
	char	*cmd;
	char	**argVE;

	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	in = ft_getfd(argv[1], 1);
	argVE = ft_split(argv[2], ' ');
	cmd = ft_newpath(argVE[0], envp);
	if (in == -1)
		return (1); // Error message of could not open file
	dup2(in, STDIN_FILENO);
	ret = execve(cmd, argVE, NULL);
	if (ret < 0)
	{
		perror("Could not execute: ");
		return (2);
	}
	return (3);
}

int ft_second(int fd[], char *argv[], char **envp)
{
	// reroute stdout to outfile
	// rerout stdin to pipe from child_1
	int		out;
	int		ret;
	char	*cmd;
	char	**argVE;

	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	out = ft_getfd(argv[4], 2);
	argVE = ft_split(argv[3], ' ');
	cmd = ft_newpath(argVE[0], envp);
	if (out == -1)
		return (1); // Error message of could not open file
	dup2(out, STDOUT_FILENO);
	ret = execve(cmd, argVE, NULL);
	if (ret < 0)
	{
		perror("Could not execute: ");
		return (2);
	}
	return (3);
}
