/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:16:59 by aait-oma          #+#    #+#             */
/*   Updated: 2022/12/20 17:09:40 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	render_rect(t_data *data, t_rect rect)
{
	int		i;
	int		j;

	if (data->ml.win == NULL)
		return (1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			my_mlx_pixel_put(data, j++, i, rect.color);
		++i;
	}
	return (0);
}
