/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:58:32 by mmessaou          #+#    #+#             */
/*   Updated: 2022/11/30 13:28:44 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	space_in_first_line(char **map)
{
	int	j;
	int	i;

	j = 0;
	while (map[0][j])
	{
		if (map[0][j] == ' ')
		{
			i = 1;
			while (map[i] && map[i][j] && map[i][j] == ' ')
				i++;
			if (map[i] && map[i][j] && map[i][j] != '1')
				return (0);
			if (map[i] && (!map[i + 1] || !map[i + 1][j]))
				return (0);
		}
		j++;
	}
	return (1);
}

bool	space_in_last_line(char **map)
{
	int	j;
	int	i;
	int	len;

	len = get_map_lenght(map) - 1;
	j = 0;
	while (map[len][j])
	{
		if (map[len][j] == ' ')
		{
			i = len - 1;
			while (map[i] && map[i][j] && map[i][j] == ' ')
				i--;
			if (i > 0 && map[i] && map[i][j] && map[i][j] != '1')
				return (0);
			if (!map[i - 1] || !map[i - 1][j])
				return (0);
		}
		j++;
	}
	return (1);
}

bool	first_and_last_line(char **map)
{
	int	i;
	int	j;
	int	len;

	len = get_map_lenght(map) - 1;
	if (len < 2)
		return (0);
	i = -1;
	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != ' ' && map[0][j] != '1')
			return (0);
		j++;
	}
	j = 0;
	while (map[len][j])
	{
		if (map[len][j] != ' ' && map[len][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

bool	first_and_last_character(char **map)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	while (map[++i])
	{
		j = 0;
		len = ft_strlen(map[i]) - 1;
		while (map[i][j] == ' ')
			j++;
		while (map[i][len] == ' ')
			len--;
		if (map[i][j] != '1' || map[i][len] != '1')
			return (0);
	}
	return (1);
}

bool	valid_wall(char **map)
{
	if (!map || !first_and_last_line(map) || !first_and_last_character(map)
		|| !space_in_first_line(map) || !space_in_last_line(map)
		|| !check_zero_in_lines(map))
		return (0);
	return (1);
}
