/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleaner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:57:40 by dareias-          #+#    #+#             */
/*   Updated: 2021/09/29 18:03:10 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex.h"

void ft_clean_ss(char **ss)
{
	int i;

	i = 0;
	while (ss[i])
	{
		free(ss[i]);
		i++;
	}
	free(ss);
}
