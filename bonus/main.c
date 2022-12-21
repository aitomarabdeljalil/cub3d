/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:49:39 by aait-oma          #+#    #+#             */
/*   Updated: 2022/12/21 00:44:28 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	to_exit(t_data *dt)
{
	ft_exit_cleanup(NULL, dt);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	dt;

	if (ac == 2)
	{
		if (WINDOW_WIDTH > 5000 || WINDOW_HEIGHT > 2600)
			ft_exit("invalid window");
		dt.x = WINDOW_WIDTH / 2;
		get_data(&dt, av[1]);
		key_init(&dt);
		game_init(&dt);
		if (!texturs_init(&dt))
			ft_exit_cleanup("Empty textur!", &dt);
		mlx_hook(dt.ml.win, 2, 1L << 0, keypress, &dt);
		mlx_hook(dt.ml.win, 3, 2L << 0, keyreleased, &dt);
		mlx_hook(dt.ml.win, 17, 2, to_exit, &dt);
		mlx_loop_hook(dt.ml.mlx, clear_reload, &dt);
		mlx_hook(dt.ml.win, 6, 1L << 1, mouse, &dt);
		mlx_loop(dt.ml.mlx);
	}
	else
		ft_exit("Invalid args");
	return (0);
}
