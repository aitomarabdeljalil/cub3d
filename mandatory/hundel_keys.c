/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundel_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:44:36 by aait-oma          #+#    #+#             */
/*   Updated: 2022/12/20 16:36:30 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_init(t_data *dt)
{
	dt->key.a = 0;
	dt->key.w = 0;
	dt->key.s = 0;
	dt->key.d = 0;
	dt->key.left = 0;
	dt->key.right = 0;
}

static void	cal_new_cord(t_data *dt, double *new_x, double *new_y, int walk_dir)
{
	double		mvstep;

	dt->pl.walkdirection = walk_dir;
	mvstep = dt->pl.walkdirection * dt->pl.movespeed;
	if (dt->key.a || dt->key.d)
	{
		mvstep = dt->pl.movespeed;
		*new_x += cos(dt->pl.rotationangle + (walk_dir * (M_PI / 2))) * mvstep;
		*new_y += sin(dt->pl.rotationangle + (walk_dir * (M_PI / 2))) * mvstep;
	}
	if (dt->key.w || dt->key.s)
	{
		*new_x += cos(dt->pl.rotationangle) * mvstep;
		*new_y += sin(dt->pl.rotationangle) * mvstep;
	}
}

void	key_action(t_data *dt)
{
	double		new_x;
	double		new_y;

	new_x = dt->pl.x;
	new_y = dt->pl.y;
	if (dt->key.w == 1)
		cal_new_cord(dt, &new_x, &new_y, 1);
	if (dt->key.s == 1)
		cal_new_cord(dt, &new_x, &new_y, -1);
	if (dt->key.a == 1)
		cal_new_cord(dt, &new_x, &new_y, -1);
	if (dt->key.d == 1)
		cal_new_cord(dt, &new_x, &new_y, 1);
	if (dt->key.right == 1)
		dt->pl.rotationangle += dt->pl.rotationspeed;
	if (dt->key.left == 1)
		dt->pl.rotationangle -= dt->pl.rotationspeed;
	if (!thereiswall(new_x, new_y, dt))
	{
		dt->pl.x = new_x;
		dt->pl.y = new_y;
	}
}

int	keypress(int keycode, t_data *dt)
{
	dt->pl.rotationangle = normalizeangle(dt->pl.rotationangle);
	if (keycode == 13)
		dt->key.w = 1;
	if (keycode == 1)
		dt->key.s = 1;
	if (keycode == 0)
		dt->key.a = 1;
	if (keycode == 2)
		dt->key.d = 1;
	if (keycode == 124)
		dt->key.right = 1;
	if (keycode == 123)
		dt->key.left = 1;
	if (keycode == 53)
		ft_exit_cleanup(NULL, dt);
	return (0);
}

int	keyreleased(int keycode, t_data *dt)
{
	dt->pl.rotationangle = normalizeangle(dt->pl.rotationangle);
	if (keycode == 13)
		dt->key.w = 0;
	if (keycode == 1)
		dt->key.s = 0;
	if (keycode == 124)
		dt->key.right = 0;
	if (keycode == 123)
		dt->key.left = 0;
	if (keycode == 0)
		dt->key.a = 0;
	if (keycode == 2)
		dt->key.d = 0;
	return (0);
}
