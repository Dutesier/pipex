/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:16:43 by dareias-          #+#    #+#             */
/*   Updated: 2021/09/29 19:19:17 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_pipex.h"

// Idea is: Have a process that seeks where the program is and returns it 
// through envp
// Have a process

int main(int argc, char *argv[], char **envp)
{
	int err;

	err = 0;
	if (argc != 5)
	{
		perror("Usage: ./pipex infile cmd1 cmd2 outfile");
		return (1);
	}
	err = ft_processes(argv, envp, -42);
	return (err);
}
