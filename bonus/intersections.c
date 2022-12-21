/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:15:27 by aait-oma          #+#    #+#             */
/*   Updated: 2022/12/20 16:26:27 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <limits.h>

bool	check_wall(double x, double y, t_data *dt)
{
	int	i;
	int	j;

	j = (int)(x / TILE_SIZE);
	i = (int)(y / TILE_SIZE);
	if (i >= dt->lenght)
		return (false);
	if (dt->map[i] && j >= ft_strlen(dt->map[i]))
		return (false);
	if (dt->map[i][j] != '1')
		return (false);
	return (true);
}

static void	draw_line(t_data *dt, double steps, double dx, double dy)
{
	int		i;
	double	x;
	double	y;
	double	xi;
	double	yi;

	i = 0;
	x = dt->pl.x;
	y = dt->pl.y;
	xi = dx / steps;
	yi = dy / steps;
	while (i < steps)
	{
		x = x + xi;
		y = y + yi;
		my_mlx_pixel_put(dt, floor(x), floor(y), 0x000000);
		i++;
	}
}

int	render_rayline(t_data *dt, t_ray *ray, double lng)
{
	double	nx;
	double	ny;
	double	dx;
	double	dy;
	double	steps;

	nx = dt->pl.x + cos(ray->rayang) * lng;
	ny = dt->pl.y + sin(ray->rayang) * lng;
	dx = nx - dt->pl.x;
	dy = ny - dt->pl.y;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	draw_line(dt, steps, dx, dy);
	return (0);
}

int	raycasting(t_data *dt, t_ray *ray)
{
	double	dist_ih;
	double	dist_iv;

	horizontal_inter(dt, ray);
	vertical_inter(dt, ray);
	if (!ray->found_ver_hit)
		dist_iv = LONG_MAX;
	else
		dist_iv = ft_distance(dt->pl.x, dt->pl.y, ray->wallvx, ray->wallvy);
	if (!ray->found_hor_hit)
		dist_ih = LONG_MAX;
	else
		dist_ih = ft_distance(dt->pl.x, dt->pl.y, ray->wallhx, ray->wallhy);
	if (dist_ih < dist_iv)
	{
		ray->distance = dist_ih;
		ray->found_ver_hit = false;
	}
	else
	{
		ray->distance = dist_iv;
		ray->found_hor_hit = false;
	}
	return (0);
}
