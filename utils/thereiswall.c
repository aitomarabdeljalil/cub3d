/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thereiswall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:17:18 by aait-oma          #+#    #+#             */
/*   Updated: 2022/12/20 17:07:02 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

bool	thereiswall(double x, double y, t_data *dt)
{
	int		i;
	int		j;

	i = floor(y / TILE_SIZE);
	j = floor(x / TILE_SIZE);
	if (dt->map[i][j] == '1' || dt->map[i][j] == ' ' || dt->map[i][j] == '\0')
		return (true);
	return (false);
}
