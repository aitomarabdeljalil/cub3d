/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:37:22 by mmessaou          #+#    #+#             */
/*   Updated: 2022/12/09 12:00:29 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_init(t_data *data)
{
	data->pl.radius = 3;
	data->pl.turndirection = 0;
	data->pl.walkdirection = 0;
	data->pl.movespeed = 1.5;
	data->pl.rotationspeed = 2 * (M_PI / 180);
	data->lenght = get_map_lenght(data->map);
	data->width = get_map_width(data->map);
}

void	data_init(t_data *data, char *file)
{
	data->content = first_read(file);
	if (!check_its_valide(data->content))
		ft_exit_cleanup("the map contains invalide elements or wall", data);
		data->map = data->content + 6;
	if (!data->map[0] || !valid_wall(data->map))
		ft_exit_cleanup("the map not exist, contains invalide wall or elements",
			data);
	if (!valid_lines(data))
		ft_exit_cleanup("the map contains invalide player, characters or space",
			data);
	data->no = try_get_texture(data->content, 'N', 'O');
	data->so = try_get_texture(data->content, 'S', 'O');
	data->we = try_get_texture(data->content, 'W', 'E');
	data->ea = try_get_texture(data->content, 'E', 'A');
	if (!data->no || !data->so || !data->we || !data->ea)
		ft_exit_cleanup("texture not found", data);
	data->c = try_get_color(data->content, 'C');
	data->f = try_get_color(data->content, 'F');
	if (!data->c || !data->f)
		ft_exit_cleanup("color not found", data);
	player_init(data);
}
