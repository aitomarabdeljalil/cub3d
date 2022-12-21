/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 08:59:05 by aait-oma          #+#    #+#             */
/*   Updated: 2022/12/20 16:26:38 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ray_init(t_ray *ray, double ray_ang)
{
	ray->rayang = normalizeangle(ray_ang);
	ray->distance = 0;
	ray->wallhx = 0;
	ray->wallhy = 0;
	ray->israydown = 0;
	ray->israyup = 0;
	ray->israyright = 0;
	ray->israyleft = 0;
	if (ray->rayang > 0 && ray->rayang < M_PI)
		ray->israydown = 1;
	else
		ray->israyup = 1;
	if ((ray->rayang >= 0 && ray->rayang < M_PI / 2)
		|| (ray->rayang >= 3 * M_PI / 2 && ray->rayang < 2 * M_PI))
		ray->israyright = 1;
	else
		ray->israyleft = 1;
	ray->found_ver_hit = false;
	ray->found_hor_hit = false;
}

// wall[0] == wallheight;
// wall[1] == real_wall;
void	cast_rays(t_data *dt)
{
	t_ray	ray;
	int		i;
	double	distfrom_pp;
	double	crt_dis;
	double	wall[2];

	i = -1;
	ray_init(&ray, dt->pl.rotationangle - to_rad(FOV / 2));
	while (++i < NUM_RAYS)
	{
		raycasting(dt, &ray);
		crt_dis = ray.distance * cos(normalizeangle(ray.rayang
					- dt->pl.rotationangle));
		distfrom_pp = (WINDOW_WIDTH / 2) / tan(to_rad(FOV / 2.0));
		wall[0] = (distfrom_pp / crt_dis) * TILE_SIZE;
		wall[1] = wall[0];
		if (wall[0] > WINDOW_HEIGHT)
			wall[0] = WINDOW_HEIGHT;
		draw_strip(dt, i, &ray, wall);
		ray_init(&ray, ray.rayang + to_rad(FOV) / NUM_RAYS);
	}
}
