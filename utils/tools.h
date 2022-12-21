/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:51:24 by mmessaou          #+#    #+#             */
/*   Updated: 2022/12/20 20:45:42 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H
# include "../parssing/parss.h"

/* ------------- utils ------------- */
/* utils.c */
char	*ft_strjoin_one(char *s1, char *s2);
bool	ft_strspn(const char *s, const char *accept);
// int		ft_strlen(char *str);
char	*skip_spaces(char *str);
/* utils_two.c */
int		ft_atoi(const char *str);
int		check_extension(char *str);
/* ft_split */
char	**ft_split(char *s, char c);

/* normalizeangle.c */
double	normalizeangle(double angle);
/* to_rad.c */
double	to_rad(double degree);
/* render_line.c */
int		render_line(t_data *dt, double lng);
/* my_mlx_pixel_put.c */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
/* ft_distance.c */
double	ft_distance(double xa, double ya, double xb, double yb);
/* render_rect.c */
int		render_rect(t_data *data, t_rect rect);
/* hundel_keys.c */
void	key_init(t_data *dt);
int		keypress(int keycode, t_data *dt);
int		keyreleased(int keycode, t_data *dt);
void	key_action(t_data *dt);
/* thereiswall.c */
bool	thereiswall(double x, double y, t_data *dt);

#endif