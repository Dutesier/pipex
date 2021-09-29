/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:47:18 by dareias-          #+#    #+#             */
/*   Updated: 2021/09/29 11:26:36 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex.h"

int	ft_getfd(char *filename, int type)
{
	int fd;

	if (type == 1)
		fd = open(filename, O_RDONLY);
	else
		fd = open(filename, O_WRONLY);
	return (fd);
}
