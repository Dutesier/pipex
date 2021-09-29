/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:55:28 by dareias-          #+#    #+#             */
/*   Updated: 2021/09/29 18:03:28 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H
# define PROGRAM_NAME bash // needs to be changed to pipex!!!!!!!!!!!

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdio.h>

char	**ft_split(char const *s, char c);
char *ft_append(char *str, char *append);
char *ft_findpath(char **envp);
int ft_strcmp(char *str1, char *str2, int cmp);
char *ft_newpath(char *cmd, char **envp);

int ft_processes(char *argv[], char **envp, int sta);
int ft_first(int fd[], char *argv[], char **envp);
int ft_second(int fd[], char *argv[], char **envp);

int	ft_getfd(char *filename, int type);
void	ft_putstr_fd(char *s, int fd);
int ft_error(char *error);
int ft_errmsg(char *msg);
void ft_clean_ss(char **ss);
#endif
