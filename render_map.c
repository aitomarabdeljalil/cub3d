/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:53:41 by aait-oma          #+#    #+#             */
/*   Updated: 2022/12/09 18:01:22 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_init(t_data *dt)
{
	dt->ml.mlx = mlx_init();
	dt->ml.win = mlx_new_window(dt->ml.mlx, MAP_WIDTH, MAP_HEIGHT, "cub3d");
	dt->ml.img = mlx_new_image(dt->ml.mlx, MAP_WIDTH, MAP_HEIGHT);
	dt->ml.addr = mlx_get_data_addr(dt->ml.img, &dt->ml.bits_per_pixel,
			&dt->ml.line_length, &dt->ml.endian);
}

void	print_map(t_data *th, int x, int y)
{
	int		tx;
	int		ty;

	tx = x * TILE_SIZE;
	ty = y * TILE_SIZE;
	if (th->map[x][y] == '1')
		render_rect(th, (t_rect){ty, tx, TILE_SIZE, TILE_SIZE, RED_PIXEL});
	else
		render_rect(th, (t_rect){ty, tx, TILE_SIZE, TILE_SIZE, 0xffffff});
	render_rect(th, (t_rect){th->pl.x, th->pl.y, 1, 1, RED_PIXEL});
	cast_rays(th);
	render_line(th, 15);
}

void	map_win(t_data *dt)
{
	int	x;
	int	y;

	x = -1;
	render_rect(dt, (t_rect){0, 0, WINDOW_WIDTH,
		WINDOW_HEIGHT / 2, dt->c_color});
	render_rect(dt, (t_rect){0, WINDOW_HEIGHT / 2,
		WINDOW_WIDTH, WINDOW_HEIGHT / 2, dt->f_color});
	while (dt->map[++x])
	{
		y = -1;
		while (dt->map[x][++y])
			print_map(dt, x, y);
	}
	mlx_put_image_to_window(dt->ml.mlx, dt->ml.win, dt->ml.img, 0, 0);
}

int	clear_reload(t_data *dt)
{
	mlx_clear_window(dt->ml.mlx, dt->ml.win);
	render_rect(dt, (t_rect){0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 0});
	key_action(dt);
	map_win(dt);
	return (0);
}
