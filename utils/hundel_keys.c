/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundel_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:44:36 by aait-oma          #+#    #+#             */
/*   Updated: 2022/12/09 18:06:54 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	key_init(t_data *dt)
{
	dt->key.a = 0;
	dt->key.w = 0;
	dt->key.s = 0;
	dt->key.d = 0;
	dt->key.left = 0;
	dt->key.right = 0;
}

bool	thereiswall(int x, int y, t_data *dt)
{
	int		i;
	int		j;

	i = floor((double)y / TILE_SIZE);
	j = floor((double)x / TILE_SIZE);
	if (dt->map[i][j] == '1')
		return (true);
	return (false);
}

void	key_action(t_data *dt)
{
	double		movestep;
	double		new_x;
	double		new_y;

	new_x = dt->pl.x;
	new_y = dt->pl.y;
	if (dt->key.w == 1)
	{
		dt->pl.walkdirection = 1;
		movestep = dt->pl.walkdirection * dt->pl.movespeed;
		new_x += cos(dt->pl.rotationangle) * movestep;
		new_y += sin(dt->pl.rotationangle) * movestep;
	}
	if (dt->key.s == 1)
	{
		dt->pl.walkdirection = -1;
		movestep = dt->pl.walkdirection * dt->pl.movespeed;
		new_x += cos(dt->pl.rotationangle) * movestep;
		new_y += sin(dt->pl.rotationangle) * movestep;
	}
	if (dt->key.a == 1)
	{
		movestep = dt->pl.movespeed;
		new_x += cos(dt->pl.rotationangle - (M_PI / 2)) * movestep;
		new_y += sin(dt->pl.rotationangle - (M_PI / 2)) * movestep;
	}
	if (dt->key.d == 1)
	{
		movestep = dt->pl.movespeed;
		new_x += cos(dt->pl.rotationangle + (M_PI / 2)) * movestep;
		new_y += sin(dt->pl.rotationangle + (M_PI / 2)) * movestep;
	}
	if (dt->key.right == 1)
	{
		dt->pl.turndirection = 1;
		dt->pl.rotationangle += dt->pl.turndirection * dt->pl.rotationspeed;
	}
	if (dt->key.left == 1)
	{
		dt->pl.turndirection = -1;
		dt->pl.rotationangle += dt->pl.turndirection * dt->pl.rotationspeed;
	}
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
		exit(0);
	return (0);
}

int	keyreleased(int keycode, t_data *dt)
{
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
