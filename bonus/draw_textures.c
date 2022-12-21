/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:20:17 by mmessaou          #+#    #+#             */
/*   Updated: 2022/12/20 16:26:05 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_texturs	get_texture(t_data *dt, t_ray *ray)
{
	if (ray->found_hor_hit && ray->israyup)
		return (dt->txtrs[0]);
	else if (ray->found_hor_hit && ray->israydown)
		return (dt->txtrs[1]);
	else if (ray->found_ver_hit && ray->israyright)
		return (dt->txtrs[2]);
	else
		return (dt->txtrs[3]);
}

// wall[0] == wallheight;
// wall[1] == real_wall;
void	draw_strip(t_data *dt, double x, t_ray *ray, double wall[2])
{
	t_texturs	txtr;
	int			txtr_x;
	int			txtr_y;
	int			y;
	int			dis_from_top;

	txtr = get_texture(dt, ray);
	if (ray->found_ver_hit)
		txtr_x = fmod(ray->wallvy, TILE_SIZE) / TILE_SIZE * txtr.img_width;
	else
		txtr_x = fmod(ray->wallhx, TILE_SIZE) / TILE_SIZE * txtr.img_width;
	y = (WINDOW_HEIGHT / 2.0) - (wall[0] / 2.0) - 1;
	while (++y < (WINDOW_HEIGHT / 2.0) + (wall[0] / 2.0))
	{
		dis_from_top = y + (wall[1] / 2) - (WINDOW_HEIGHT / 2);
		txtr_y = dis_from_top / wall[1] * txtr.img_height;
		my_mlx_pixel_put(dt, floor(x), floor(y),
			((int *)txtr.addr)[(txtr.img_width * txtr_y) + txtr_x]);
	}
}
