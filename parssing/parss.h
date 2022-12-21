/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parss.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:11:50 by mmessaou          #+#    #+#             */
/*   Updated: 2022/12/21 00:38:41 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSS_H
# define PARSS_H
# include <unistd.h>
# include <stdbool.h>
# include <errno.h>
# include <sys/types.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include "../get_next_line/get_next_line.h"
# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 800
# define TILE_SIZE 32
# define MAP_WIDTH 200
# define MAP_HEIGHT 200
# define FOV 60 //in degrees
# define NUM_RAYS WINDOW_WIDTH
# define RED_PIXEL 0xFF0000

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	char	*addr;
	void	*img;
	int		bits_per_pixel;
	int		endian;
	int		line_length;
}	t_mlx;

typedef struct s_key
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		left;
	int		right;
}	t_key;

typedef struct s_player
{
	double	x;
	double	y;
	double	radius;
	int		turndirection;
	int		walkdirection;
	double	rotationangle;
	double	movespeed;
	double	rotationspeed;
}	t_player;

typedef struct s_texturs
{
	void		*img;
	char		*addr;
	int			img_height;
	int			img_width;
}	t_texturs;

typedef struct s_data
{
	t_player	pl;
	t_mlx		ml;
	t_key		key;
	t_texturs	txtrs[4];
	char		**content;
	char		**map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	int			c_color;
	int			f_color;
	int			lenght;
	int			width;
	int			x;
}	t_data;

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}	t_rect;

typedef struct s_ray
{
	double		rayang;
	double		wallhx;
	double		wallhy;
	double		wallvx;
	double		wallvy;
	double		distance;
	int			washitver;
	int			israydown;
	int			israyup;
	int			israyright;
	int			israyleft;
	bool		found_ver_hit;
	bool		found_hor_hit;
}	t_ray;

/* ------------ UTILS -------------- */
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
/* ------------ PARSSING -------------- */
/* read_file.c */
char	**first_read(char *file);
/* check_elements.c */
char	*try_get_texture(char **content, char a, char b);
char	*try_get_color(char **content, char a);
int		get_map_lenght(char **str);
int		get_map_width(char **str);
/* check_map_format.c */
bool	check_its_valide(char **content);
/* check_map_wall.c */
bool	valid_wall(char **map);
/* data_init.c */
void	data_init(t_data *data, char *file);
bool	texturs_init(t_data *data);
/* check_map_content.c */
bool	valid_lines(t_data *data);
bool	check_zero_in_lines(char **map);
/* exit.c */
void	ft_exit(char *message);
void	ft_exit_cleanup(char *message, t_data *data);
int		ft_clear_tab(char **str);
/* check_data.c */
bool	check_texture_path(char *path);
int		check_color(char *color);
int		get_color(int r, int g, int b);
/* get_data.c */
void	get_data(t_data *data, char *file);

#endif
