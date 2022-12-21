/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:37:50 by aait-oma          #+#    #+#             */
/*   Updated: 2022/12/21 00:08:16 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	mouse(int x, int y, t_data *dt)
{
	if (y > 0 && y < WINDOW_HEIGHT)
	{
		if (x > 0 && x < WINDOW_WIDTH)
		{
			if (x < dt->x)
				dt->pl.rotationangle -= dt->pl.rotationspeed;
			else
				dt->pl.rotationangle += dt->pl.rotationspeed;
		}
	}
	dt->x = x;
	return (0);
}
