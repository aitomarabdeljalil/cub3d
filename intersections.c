/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:15:27 by aait-oma          #+#    #+#             */
/*   Updated: 2022/12/09 15:06:49 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <limits.h>

typedef struct s_ponit
{
    double x;
    double y;
}   t_ponit;

// remember to assk if simo already had strlen to not dublicate
int	ft_strlen1(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

bool    check_wall(double x, double y, t_data *dt)
{
    int i;
    int	j;
    
    j  = (int) floor(x / TILE_SIZE);
    i  = (int) floor(y / TILE_SIZE);
    if (i >= dt->lenght)
        return (false);
    if (dt->map[i] && j >= ft_strlen1(dt->map[i]))
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

void  horizontal_inter(t_data *dt, t_ray *ray)
{
    double dx, dy, xintersction, yintersction;

    ray->found_hor_hit = false;
    ray->wallhx = 0;
    ray->wallhy = 0;
    yintersction = floor(dt->pl.y / TILE_SIZE) * TILE_SIZE;
    if (ray->israydown)
        yintersction += TILE_SIZE;
    xintersction = dt->pl.x + (yintersction - dt->pl.y) / tan(ray->rayang);
    dy = TILE_SIZE;
    if (ray->israyup)
        dy *= -1;
    dx = TILE_SIZE / tan(ray->rayang);
    if (ray->israyleft && dx > 0)
        dx *= -1;
    if (ray->israyright && dx < 0)
        dx *= -1;
    
    double nexthtx;
    double nexthty;
    nexthtx = xintersction;
    nexthty = yintersction;
    int check = 0;
    if (ray->israyup)
        check = 1;
    while (nexthtx >= 0 && nexthtx <= dt->width * TILE_SIZE && nexthty >= 0 && nexthty <= dt->lenght * TILE_SIZE) 
    {
        if (check_wall(nexthtx, nexthty - check, dt))
        {
            ray->found_hor_hit = true;
            ray->wallhx = nexthtx;
            ray->wallhy = nexthty;
            break ;
        } else {
            nexthtx += dx;
            nexthty += dy;
        }
    }
}

void  vertical_inter(t_data *dt, t_ray *ray)
{
    double dx, dy, xintersction, yintersction;
    double nextvtx;
    double nextvty;
    int check = 0;

    ray->found_ver_hit = false;
    ray->wallvx = 0;
    ray->wallvy = 0;
    xintersction = floor(dt->pl.x / TILE_SIZE) * TILE_SIZE;
    if (ray->israyright)
        xintersction += TILE_SIZE;
    yintersction = dt->pl.y + (xintersction - dt->pl.x) * tan(ray->rayang);
    dx = TILE_SIZE;
    if (ray->israyleft)
        dx *= -1;
    dy = TILE_SIZE * tan(ray->rayang);
    if (ray->israyup && dy > 0)
        dy *= -1;
    if (ray->israydown && dy < 0)
        dy *= -1;    
    nextvtx = xintersction;
    nextvty = yintersction;
    if (ray->israyleft)
        check = 1;
    while (nextvtx >= 0 && nextvtx <= dt->width * TILE_SIZE && nextvty >= 0 && nextvty <= dt->lenght * TILE_SIZE) 
    {
        if (check_wall(nextvtx - check, nextvty, dt)) 
        {
            ray->found_ver_hit = true;
            ray->wallvx = nextvtx;
            ray->wallvy = nextvty;
            break ;
        } else {
            nextvtx += dx;
            nextvty += dy;
        }
    }
}

int raycasting(t_data *dt, t_ray *ray)
{
    double  dist_ih;
    double  dist_iv;

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
    if (dist_ih < dist_iv && ray->found_hor_hit)
        ray->distance = dist_ih;
    else
        ray->distance = dist_iv;
    render_rayline(dt, ray, ray->distance);
    return (0);
}