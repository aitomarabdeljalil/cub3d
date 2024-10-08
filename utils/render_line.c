/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:02:47 by aait-oma          #+#    #+#             */
/*   Updated: 2022/12/20 17:09:33 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

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
		my_mlx_pixel_put(dt, floor(x), floor(y), RED_PIXEL);
		i++;
	}
}

int	render_line(t_data *dt, double lng)
{
	double	nx;
	double	ny;
	double	dx;
	double	dy;
	double	steps;

	nx = dt->pl.x + cos(dt->pl.rotationangle) * lng;
	ny = dt->pl.y + sin(dt->pl.rotationangle) * lng;
	dx = nx - dt->pl.x;
	dy = ny - dt->pl.y;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	draw_line(dt, steps, dx, dy);
	return (0);
}
