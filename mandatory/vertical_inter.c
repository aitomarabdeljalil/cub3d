/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_inter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:59:12 by aait-oma          #+#    #+#             */
/*   Updated: 2022/12/20 21:21:35 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calc_delta_xy(t_ray *ray, double *dx, double *dy)
{
	ray->found_ver_hit = false;
	ray->wallvx = 0;
	ray->wallvy = 0;
	*dx = TILE_SIZE;
	if (ray->israyleft)
		*dx *= -1;
	*dy = TILE_SIZE * tan(ray->rayang);
	if (ray->israyup && *dy > 0)
		*dy *= -1;
	if (ray->israydown && *dy < 0)
		*dy *= -1;
}

static void	calc_intersction(t_data *dt, t_ray *ray,
							double *nextvtx, double *nextvty)
{
	double	xintersction;
	double	yintersction;

	xintersction = floor(dt->pl.x / TILE_SIZE) * TILE_SIZE;
	if (ray->israyright)
		xintersction += TILE_SIZE;
	yintersction = dt->pl.y + (xintersction - dt->pl.x) * tan(ray->rayang);
	*nextvtx = xintersction;
	*nextvty = yintersction;
}

static double	get_t1(t_ray *ray, double nextvtx)
{
	if (ray->israyleft)
		return (nextvtx - 1);
	return (nextvtx);
}

void	vertical_inter(t_data *dt, t_ray *ray)
{
	double	dx;
	double	dy;
	double	nextvtx;
	double	nextvty;
	double	t1;

	calc_delta_xy(ray, &dx, &dy);
	calc_intersction(dt, ray, &nextvtx, &nextvty);
	while (nextvtx >= 0 && nextvtx < dt->width * TILE_SIZE
		&& nextvty >= 0 && nextvty < dt->lenght * TILE_SIZE)
	{
		t1 = get_t1(ray, nextvtx);
		if (check_wall(t1, nextvty, dt))
		{
			ray->found_ver_hit = true;
			ray->wallvx = nextvtx;
			ray->wallvy = nextvty;
			break ;
		}
		else
		{
			nextvtx += dx;
			nextvty += dy;
		}
	}
}
