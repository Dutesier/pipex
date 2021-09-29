/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:20:29 by dareias-          #+#    #+#             */
/*   Updated: 2021/09/29 19:05:34 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex.h"

static void ft_closer(int clo, int fd[])
{
	if (clo == 2)
	{
		close(fd[0]);
		close(fd[1]);
	}
	if (clo == 1)
		close(fd[1]);
	if (clo == 0)
		close(fd[0]);
}

int ft_processes(char *argv[], char **envp, int sta)
{
	pid_t child_1; // Takes infile as input and pipes execve to child_2 as output
	pid_t child_2; // Takes child_1 output as input and outputs execve to outfile
	int fd[2]; // fd[0] to read from child_1 and fd[1] to write to child_2

	if (pipe(fd) == -1)
		return (ft_errmsg("Pipe: "));
	child_1 = fork();
	if (child_1 < 0)
		return (ft_errmsg("Fork: "));
	if (child_1 == 0)
		return (ft_first(fd, argv, envp));
	waitpid(child_1, &sta, 0);
	sta = WEXITSTATUS(sta);
	if (sta != 0)
	{
		ft_closer(2, fd);
		return (sta);
	}
	child_2 = fork();
	if (child_2 < 0)
		return (ft_errmsg("Fork: "));
	if (child_2 == 0)
		return (ft_second(fd, argv, envp));
	ft_closer(2, fd);
	return (0);
}

int ft_first(int fd[], char *argv[], char **envp)
{
	int		in;
	int		ret;
	char	*cmd;
	char	**argVE;

	close(fd[0]);
	in = ft_getfd(argv[1], 1);
	if (in == -1)
	{
		close(fd[1]);
		exit (1);
	}
	dup2(in, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	argVE = ft_split(argv[2], ' ');
	cmd = ft_newpath(argVE[0], envp);
	ret = execve(cmd, argVE, NULL);
	if (ret < 0)
	{
		ft_clean_ss(argVE);
		free(cmd);
		return (ft_error(cmd));
	}
	return (1);
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
	printf("Got here");
	out = ft_getfd(argv[4], 2);
	if (out == -1)
	{
		close(fd[0]);
		exit (1);
	}// Error message of could not open file
	dup2(fd[0], STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	argVE = ft_split(argv[3], ' ');
	cmd = ft_newpath(argVE[0], envp);
	ret = execve(cmd, argVE, NULL);
	if (ret < 0)
	{
		ft_clean_ss(argVE);
		free(cmd);
		return (ft_error(cmd));
	}
	return (1);
}
