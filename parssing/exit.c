/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:19:50 by mmessaou          #+#    #+#             */
/*   Updated: 2022/12/20 20:59:05 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parss.h"

void	destroy_data(t_data *dt)
{
	int	i;

	i = -1;
	mlx_destroy_image(dt->ml.mlx, dt->ml.img);
	while (++i < 4)
	{
		mlx_destroy_image(dt->ml.mlx, dt->txtrs[i].img);
	}
	mlx_destroy_window(dt->ml.mlx, dt->ml.win);
}

int	ft_clear_tab(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	return (-1);
}

void	ft_exit(char *message)
{
	if (message)
	{
		printf("\033[0;31mError\n -- \x1B[33m%s.\n\x1B[0m", message);
		exit(1);
	}
	exit(0);
}

void	ft_exit_cleanup(char *message, t_data *data)
{
	if (data->content)
		ft_clear_tab(data->content);
	if (data->ml.mlx)
		destroy_data(data);
	if (message)
	{
		printf("\033[0;31mError\n -- \x1B[33m%s.\n\x1B[0m", message);
		exit(1);
	}
	exit(0);
}
