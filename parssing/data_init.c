/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:37:22 by mmessaou          #+#    #+#             */
/*   Updated: 2022/12/21 00:46:09 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parss.h"

void	player_init(t_data *data)
{
	data->pl.radius = 3;
	data->pl.turndirection = 0;
	data->pl.walkdirection = 0;
	data->pl.movespeed = 4;
	data->pl.rotationspeed = 3 * (M_PI / 180);
	data->lenght = get_map_lenght(data->map);
	data->width = get_map_width(data->map);
}

bool	texturs_init(t_data *data)
{
	int	bits_per_pixel;
	int	size_line;
	int	endian;

	data->txtrs[0].img = mlx_xpm_file_to_image(data->ml.mlx, data->no,
			&data->txtrs[0].img_width, &data->txtrs[0].img_height);
	data->txtrs[1].img = mlx_xpm_file_to_image(data->ml.mlx, data->so,
			&data->txtrs[1].img_width, &data->txtrs[1].img_height);
	data->txtrs[2].img = mlx_xpm_file_to_image(data->ml.mlx, data->ea,
			&data->txtrs[2].img_width, &data->txtrs[2].img_height);
	data->txtrs[3].img = mlx_xpm_file_to_image(data->ml.mlx, data->we,
			&data->txtrs[3].img_width, &data->txtrs[3].img_height);
	if (!data->txtrs[0].img || !data->txtrs[1].img
		|| !data->txtrs[2].img || !data->txtrs[3].img)
		return (0);
	data->txtrs[0].addr = mlx_get_data_addr(data->txtrs[0].img,
			&bits_per_pixel, &size_line, &endian);
	data->txtrs[1].addr = mlx_get_data_addr(data->txtrs[1].img,
			&bits_per_pixel, &size_line, &endian);
	data->txtrs[2].addr = mlx_get_data_addr(data->txtrs[2].img,
			&bits_per_pixel, &size_line, &endian);
	data->txtrs[3].addr = mlx_get_data_addr(data->txtrs[3].img,
			&bits_per_pixel, &size_line, &endian);
	return (1);
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
