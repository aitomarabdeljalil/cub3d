/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:53:41 by aait-oma          #+#    #+#             */
/*   Updated: 2022/12/21 00:07:56 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	game_init(t_data *dt)
{
	dt->ml.mlx = mlx_init();
	dt->ml.win = mlx_new_window(dt->ml.mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "cub3d");
	dt->ml.img = mlx_new_image(dt->ml.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	dt->ml.addr = mlx_get_data_addr(dt->ml.img, &dt->ml.bits_per_pixel,
			&dt->ml.line_length, &dt->ml.endian);
}

void	map_win(t_data *dt)
{
	render_rect(dt, (t_rect){0, 0, WINDOW_WIDTH,
		WINDOW_HEIGHT / 2, dt->c_color});
	render_rect(dt, (t_rect){0, WINDOW_HEIGHT / 2,
		WINDOW_WIDTH, WINDOW_HEIGHT / 2, dt->f_color});
	cast_rays(dt);
	render_minimap(dt);
	mlx_put_image_to_window(dt->ml.mlx, dt->ml.win, dt->ml.img, 0, 0);
}

int	clear_reload(t_data *dt)
{
	key_action(dt);
	map_win(dt);
	return (0);
}
