/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_inter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 09:02:07 by aait-oma          #+#    #+#             */
/*   Updated: 2022/12/20 21:21:14 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calc_delta_xy(t_ray *ray, double *dx, double *dy)
{
	ray->found_hor_hit = false;
	ray->wallhx = 0;
	ray->wallhy = 0;
	*dy = TILE_SIZE;
	if (ray->israyup)
		*dy *= -1;
	*dx = TILE_SIZE / tan(ray->rayang);
	if (ray->israyleft && *dx > 0)
		*dx *= -1;
	if (ray->israyright && *dx < 0)
		*dx *= -1;
}

static void	calc_intersction(t_data *dt, t_ray *ray,
							double *nexthtx, double *nexthty)
{
	double	xintersction;
	double	yintersction;

	yintersction = floor(dt->pl.y / TILE_SIZE) * TILE_SIZE;
	if (ray->israydown)
		yintersction += TILE_SIZE;
	xintersction = dt->pl.x + (yintersction - dt->pl.y) / tan(ray->rayang);
	*nexthtx = xintersction;
	*nexthty = yintersction;
}

static double	get_t1(t_ray *ray, double nexthty)
{
	if (ray->israyup)
		return (nexthty - 1);
	return (nexthty);
}

void	horizontal_inter(t_data *dt, t_ray *ray)
{
	double	dx;
	double	dy;
	double	nexthty;
	double	nexthtx;
	double	t1;

	calc_delta_xy(ray, &dx, &dy);
	calc_intersction(dt, ray, &nexthtx, &nexthty);
	while (nexthtx >= 0 && nexthtx < dt->width * TILE_SIZE
		&& nexthty >= 0 && nexthty < dt->lenght * TILE_SIZE)
	{
		t1 = get_t1(ray, nexthty);
		if (check_wall(nexthtx, t1, dt))
		{
			ray->found_hor_hit = true;
			ray->wallhx = nexthtx;
			ray->wallhy = nexthty;
			break ;
		}
		else
		{
			nexthtx += dx;
			nexthty += dy;
		}
	}
}
