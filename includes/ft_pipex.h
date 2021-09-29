/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:55:28 by dareias-          #+#    #+#             */
/*   Updated: 2021/09/29 11:27:15 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>

char	**ft_split(char const *s, char c);
char *ft_append(char *str, char *append);
char *ft_findpath(char **envp);
int ft_strcmp(char *str1, char *str2, int cmp);
char *ft_newpath(char *cmd, char **envp);

int ft_processes(char *argv[], char **envp);
int ft_first(int fd[], char *argv[], char **envp);
int ft_second(int fd[], char *argv[], char **envp);

int	ft_getfd(char *filename, int type);
#endif
