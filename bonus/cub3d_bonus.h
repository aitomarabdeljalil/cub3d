/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:21:57 by aait-oma          #+#    #+#             */
/*   Updated: 2022/12/21 00:16:15 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# include "../parssing/parss.h"
# include "../utils/tools.h"
/****************************************************/
/* ----------------- RAYCASTING ------------------- */
/****************************************************/

/* render_map.c */
void	game_init(t_data *dt);
void	map_win(t_data *dt);
int		clear_reload(t_data *dt);
/* rays.c */
void	cast_rays(t_data *dt);
int		raycasting(t_data *dt, t_ray *ray);
bool	check_wall(double x, double y, t_data *dt);
/* vertical_inter.c */
void	vertical_inter(t_data *dt, t_ray *ray);
/* horizontal_inter.c */
void	horizontal_inter(t_data *dt, t_ray *ray);
/* draw_wall.c */
void	ft_draw_wall(t_data *dt, double xa, double ya, double yb);
/* drawmap.c */
void	render_minimap(t_data *dt);
/* mouse.c */
int		mouse(int x, int y, t_data *dt);
/* draw_textures.c */
void	draw_strip(t_data *dt, double x, t_ray *ray, double wall[2]);

#endif
