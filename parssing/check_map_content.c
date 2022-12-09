/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 00:00:01 by mmessaou          #+#    #+#             */
/*   Updated: 2022/11/30 17:10:24 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	check_space_in_lines(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (++i < (get_map_lenght(map) - 2))
	{
		j = 0;
		while (map[i][++j])
		{
			if (map[i][j] == ' ')
			{
				if (map[i][j - 1] != '1' && map[i][j - 1] != ' ')
					return (0);
				if (map[i][j + 1] != '1' && map[i][j + 1] != ' ')
					return (0);
				if ((map[i + 1] && ft_strlen(map[i + 1]) > j
						&& map[i + 1][j] != ' ' && map[i + 1][j] != '1')
					|| (map[i - 1] && ft_strlen(map[i - 1]) > j
					&& map[i - 1][j] != ' ' && map[i - 1][j] != '1'))
					return (0);
			}
		}
	}
	return (1);
}

int	check_player(char c, bool b, t_data *data)
{
	if (c == '1' || c == '0' || c == ' ')
		return (2);
	if (c == 'N' && !b)
	{
		data->pl.rotationangle = 3 * (M_PI / 2);
		return (1);
	}
	if (c == 'W' && !b)
	{
		data->pl.rotationangle = M_PI;
		return (1);
	}
	if (c == 'S' && !b)
	{
		data->pl.rotationangle = M_PI / 2;
		return (1);
	}
	if (c == 'E' && !b)
	{
		data->pl.rotationangle = 0;
		return (1);
	}
	return (0);
}

bool	check_map_characters(t_data *data)
{
	int		i;
	int		j;
	bool	k;

	i = -1;
	k = false;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (check_player(data->map[i][j], k, data) == 1)
			{
				k = true;
				data->pl.x = (j * TILE_SIZE) + (TILE_SIZE / 2);
				data->pl.y = (i * TILE_SIZE) + (TILE_SIZE / 2);
			}
			else if (check_player(data->map[i][j], k, data) != 2)
				return (0);
		}
	}
	if (!k)
		return (0);
	return (1);
}

bool	check_zero_in_lines(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0' && (!map[i - 1][j] || !map[i + 1][j]))
				return (0);
		}
	}
	return (1);
}

bool	valid_lines(t_data *data)
{
	if (!check_space_in_lines(data->map) || !check_map_characters(data))
		return (0);
	return (1);
}
