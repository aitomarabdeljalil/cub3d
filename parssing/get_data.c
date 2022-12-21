/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:35:39 by mmessaou          #+#    #+#             */
/*   Updated: 2022/12/20 20:59:01 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parss.h"

void	get_data(t_data *data, char *file)
{
	data_init(data, file);
	if (!check_texture_path(data->no))
		ft_exit_cleanup("NO ./path not found", data);
	if (!check_texture_path(data->so))
		ft_exit_cleanup("SO ./path not found", data);
	if (!check_texture_path(data->we))
		ft_exit_cleanup("WE ./path not found", data);
	if (!check_texture_path(data->ea))
		ft_exit_cleanup("EA ./path not found", data);
	data->c_color = check_color(data->c);
	if (data->c_color == -1)
		ft_exit_cleanup("C color not found or invalid values", data);
	data->f_color = check_color(data->f);
	if (data->f_color == -1)
		ft_exit_cleanup("F color not found or invalid values", data);
}
