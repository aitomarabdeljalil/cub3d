/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:40:12 by aait-oma          #+#    #+#             */
/*   Updated: 2022/12/20 17:09:04 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->ml.addr + (y * WINDOW_WIDTH + x) * 4;
	*(unsigned int *) dst = color;
}
