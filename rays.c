/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 08:59:05 by aait-oma          #+#    #+#             */
/*   Updated: 2022/12/09 18:19:41 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		|| (ray->rayang >= 3 * M_PI / 2 && ray->rayang < 2 * M_PI ))
		ray->israyright = 1;
	else
		ray->israyleft = 1;
	ray->found_ver_hit = false;
	ray->found_hor_hit = false;
}

void	ft_drawline(t_data *dt, double xa, double ya, double xb, double yb)
{
    double	dx = xb - xa;
	double  dy = yb - ya;
	double	steps;

	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	int		i;
	double	x;
	double	y;
	double	xi;
	double	yi;

	i = 0;
	x = xa;
	y = ya;
	xi = dx / steps;
	yi = dy / steps;
	while (i < steps)
	{
		x += xi;
		y += yi;
		my_mlx_pixel_put(dt, floor(x), floor(y), RED_PIXEL);
		i++;
	}
}

void	cast_rays(t_data *dt)
{
    t_ray   ray;
    double  ray_ang;
    int     i;
	double  distfrom_pp;
	double  wallheight;
	double 	correct_dis;

	i = 0;
    ray_ang = dt->pl.rotationangle - to_rad(FOV / 2);
    while (i < NUM_RAYS)
    {
		dt->pl.rotationangle = normalizeangle(dt->pl.rotationangle);
		ray_init(&ray, ray_ang);
		raycasting(dt, &ray);
		correct_dis = ray.distance * cos(ray.rayang - dt->pl.rotationangle);
		distfrom_pp = (WINDOW_WIDTH / 2) / tan(FOV / 2);
		wallheight = (TILE_SIZE / correct_dis) * distfrom_pp;
		// printf("%f\n", wallheight);
		wallheight =  wallheight < 0 ? - wallheight : wallheight;
		if (wallheight > WINDOW_HEIGHT)
			wallheight = WINDOW_HEIGHT;
		// ft_drawline(dt, i, (WINDOW_HEIGHT / 2) - (wallheight / 2), i, (WINDOW_HEIGHT / 2) - (wallheight / 2) + wallheight);
		render_rect(dt, (t_rect){i, (WINDOW_HEIGHT / 2) - (wallheight / 2), 1, wallheight, RED_PIXEL});
        ray_ang += to_rad(FOV) / NUM_RAYS;
        i++;
    }
    
}
