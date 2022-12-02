/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:37:22 by mmessaou          #+#    #+#             */
/*   Updated: 2022/06/27 11:39:34 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	data_init(t_data *data, char *file)
{
	data->content = first_read(file, data);
	if (!check_its_valide(data->content))
		ft_exit("the map contains invalide elements or wall", data);
		data->map = data->content + 6;
	if (!data->map[0] || !valid_wall(data->map))
		ft_exit("the map not exist, contains invalide wall or elements", data);
	if (!valid_lines(data->map))
		ft_exit("the map contains invalide player, characters or space", data);
	data->no = try_get_texture(data->content, 'N', 'O');
	data->so = try_get_texture(data->content, 'S', 'O');
	data->we = try_get_texture(data->content, 'W', 'E');
	data->ea = try_get_texture(data->content, 'E', 'A');
	if (!data->no || !data->so || !data->we || !data->ea)
		ft_exit("texture not found", data);
	data->c = try_get_color(data->content, 'C');
	data->f = try_get_color(data->content, 'F');
	if (!data->c || !data->f)
		ft_exit("color not found", data);
}
