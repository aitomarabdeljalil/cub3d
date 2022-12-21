/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:00:52 by aait-oma          #+#    #+#             */
/*   Updated: 2022/12/20 16:26:19 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_miniplayer(t_data *dt, double x, double y, int color)
{
	int	i;
	int	j;

	i = y - 1;
	while (++i < y + 3)
	{
		j = x - 1;
		while (++j < x + 3)
		{
			if (i >= 0 && j >= 0 && i < MAP_WIDTH && j < MAP_HEIGHT)
				my_mlx_pixel_put(dt, i, j, color);
		}
	}
}

void	draw_square(t_data *dt, double y, double x, int color)
{
	int	i;
	int	j;

	i = y - 1;
	while (++i < y + TILE_SIZE)
	{
		j = x - 1;
		while (++j < x + TILE_SIZE)
		{
			if (i >= 0 && j >= 0 && i < MAP_WIDTH && j < MAP_HEIGHT)
				my_mlx_pixel_put(dt, i, j, color);
		}
	}
}

void	render_minimap(t_data *dt)
{
	int	dx;
	int	dy;
	int	i;
	int	j;

	dx = dt->pl.x - 100;
	dy = dt->pl.y - 100;
	i = -1;
	while (dt->map[++i])
	{
		j = -1;
		while (dt->map[i][++j])
		{
			if (dt->map[i][j] == '1')
				draw_square(dt, (i * TILE_SIZE - dy), \
				(j * TILE_SIZE - dx), 0x000000);
			if (dt->map[i][j] == '0' || dt->map[i][j] == 'S'
				|| dt->map[i][j] == 'N' || dt->map[i][j] == 'E'
				|| dt->map[i][j] == 'W')
				draw_square(dt, (i * TILE_SIZE - dy), \
				(j * TILE_SIZE - dx), 0xFFFFFF);
		}
	}
	draw_miniplayer(dt, (dt->pl.x - dx - 1), \
	(dt->pl.y - dy - 1), 0x880000);
}
