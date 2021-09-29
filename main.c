/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:16:43 by dareias-          #+#    #+#             */
/*   Updated: 2021/09/29 11:17:00 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_pipex.h"

// Idea is: Have a process that seeks where the program is and returns it 
// through envp
// Have a process

int main(int argc, char *argv[], char **envp)
{
	/*char **argVE;
	char *cmd;
	char **path;
	int i;
	int z;*/

	if (argc != 5)
		return (1);
	ft_processes(argv, envp);
	/*argVE = ft_split(argv[2], ' ');
	path = ft_split(ft_findpath(envp), ':');
	i = -1;
	z = 0;
	cmd = ft_newpath(argVE[0], envp);
	while (i == -1)
	{
		i = execve(cmd, argVE, NULL);
		if (i < 0)
			perror("Could not execute: ");
	}
	printf("\nCMD: %s\nargVE[0]: %s\nargVE[1]: %s\n", cmd, argVE[0], argVE[1]);
	return (0);*/
}
