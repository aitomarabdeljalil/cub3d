/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:03:32 by mmessaou          #+#    #+#             */
/*   Updated: 2022/06/27 14:09:19 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	check_texture_path(char *path)
{
	int	fd;

	fd = open(path, O_RDWR);
	if (fd == -1)
		return (close(fd), 0);
	return (close(fd), 1);
}

int	check_color(char *color)
{
	char	**rgb;
	int		i;

	i = -1;
	rgb = ft_split(color, ',');
	while (rgb[++i])
	{
		if (!ft_strspn(rgb[i], "0123456789"))
		{
			ft_clear_tab(rgb);
			return (-1);
		}
	}
	i = -1;
	while (rgb[++i])
	{
		if (ft_atoi(rgb[i]) > 255)
		{
			ft_clear_tab(rgb);
			return (-1);
		}
	}
	i = get_color(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	ft_clear_tab(rgb);
	return (i);
}

int	get_color(int r, int g, int b)
{
	int	color;

	color = r << 16 | g << 8 | b;
	return (color);
}
