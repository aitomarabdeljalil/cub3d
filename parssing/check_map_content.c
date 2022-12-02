/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 00:00:01 by mmessaou          #+#    #+#             */
/*   Updated: 2022/06/27 11:24:58 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	check_space_in_lines(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (++i < (get_line_nbr(map) - 2))
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

bool	check_map_characters(char **map)
{
	int		i;
	int		j;
	bool	k;

	i = -1;
	k = false;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != ' ')
			{
				if ((map[i][j] == 'N' || map[i][j] == 'W'
					|| map[i][j] == 'S' || map[i][j] == 'E') && !k)
					k = true;
				else
					return (0);
			}
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

bool	valid_lines(char **map)
{
	if (!check_space_in_lines(map) || !check_map_characters(map))
		return (0);
	return (1);
}
