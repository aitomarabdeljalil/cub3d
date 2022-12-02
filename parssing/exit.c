/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:34:14 by aait-oma          #+#    #+#             */
/*   Updated: 2022/11/25 15:32:55 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_clear_tab(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

int	ft_exitt(void)
{
	exit(1);
}

void	ft_exit(char *message, t_data *data)
{
	(void)data;
	if (message)
	{
		printf("\033[0;31mError : \x1B[33m%s.\n\x1B[0m", message);
		exit(1);
	}
	exit(0);
}
