/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:40:03 by dareias-          #+#    #+#             */
/*   Updated: 2021/09/29 17:29:28 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex.h"

int ft_error(char *error)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(error, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	exit (1);
}

int ft_errmsg(char *msg)
{
	perror(msg);
	return (1);
}
