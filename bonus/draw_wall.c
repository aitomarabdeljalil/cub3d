/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:30:21 by aait-oma          #+#    #+#             */
/*   Updated: 2022/12/20 16:26:16 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_line(t_data *dt, double *arg, double dx, double dy)
{
	int		i;
	double	x;
	double	y;
	double	xi;
	double	yi;

	i = -1;
	x = arg[0];
	y = arg[1];
	xi = dx / arg[2];
	yi = dy / arg[2];
	while (++i < arg[2])
	{
		x += xi;
		y += yi;
		my_mlx_pixel_put(dt, floor(x), floor(y), 0xEEEEEEE);
	}
}

void	ft_draw_wall(t_data *dt, double xa, double ya, double yb)
{
	double	dx;
	double	dy;
	double	steps;
	double	*arg;

	dx = 0;
	dy = yb - ya;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	arg = malloc(sizeof(double) * 3);
	arg[0] = xa;
	arg[1] = ya;
	arg[2] = steps;
	draw_line(dt, arg, dx, dy);
	free(arg);
}
