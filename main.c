/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:49:39 by aait-oma          #+#    #+#             */
/*   Updated: 2022/12/07 17:32:57 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_data	dt;

	(void)ac;
	get_data(&dt, av[1]);
	key_init(&dt);
	game_init(&dt);
	map_win(&dt);
	mlx_hook(dt.ml.win, 2, 1L<<0, keypress, &dt);
	mlx_hook(dt.ml.win, 3, 2L<<0, keyreleased, &dt);
	mlx_loop_hook(dt.ml.mlx, clear_reload, &dt);
	mlx_loop(dt.ml.mlx);
    return (0);
}
