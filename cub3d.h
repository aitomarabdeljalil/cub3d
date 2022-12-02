/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:21:57 by aait-oma          #+#    #+#             */
/*   Updated: 2022/12/02 15:13:37 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdbool.h>
# include <errno.h>
# include <sys/types.h>
# include <fcntl.h>
# include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
# include "get_next_line/get_next_line.h"
# define TILE_SIZE 16
# define MAP_WIDTH 100
# define MAP_HEIGHT 100
// # define WINDOW_WIDTH 1000
# define FOV 60 //in degrees
// # define NUM_RAYS WINDOW_WIDTH
#define MLX_ERROR 1

#define RED_PIXEL 0xFF0000

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300


typedef struct s_mlx
{
    void            *mlx;
    void            *win;
    int 			hgt;
    int             wth;
    void            *bg;
    void            *wall;
    void			*img;
    void			*minimap;
    void			*addr;
    int				bits_per_pixel;
    unsigned int	*img_addres;
    int				size_line;
	int				endian;
	int				line_length;
} t_mlx;

typedef struct s_player
{
    int     x; //j
    int     y; //x
    double  radius;
    int     turndirection; // -1 if left, +1 if right
    int     walkdirection; // -1 if back, +1 if front
    double  rotationangle;
    double     movespeed;
    double  rotationspeed;
} t_player;


typedef struct s_data
{
    t_player    pl;
    t_mlx       ml;
    /*------------------*/
    char		**content;
    char        **map;
    char		*no;
	char		*so;
	char		*we;
	char		*ea;
    char		*f;
	char		*c;
    int			c_color;
	int			f_color;
}	t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

typedef struct s_ray
{
    double  rayang;
    double  wallhx;
    double  wallhy;
    double  distance;
    int     washitver;
    int     israydown;
    int     israyup;
    int     israyright;
    int     israyleft;
}   t_ray;

/* ------------ UTILS -------------- */
/* utils.c */
char	*ft_strjoin_one(char *s1, char *s2);
bool    ft_strspn(const char *s, const char *accept);
char	*skip_spaces(char *str);

/* utils_two.c */
int	ft_atoi(const char *str);
/* ft_split */
char	**ft_split(char *s, char c);

/* ------------ PARSSING -------------- */
/* read_file.c */
char	**first_read(char *file, t_data *data);

/* check_elements.c */
char	*try_get_texture(char **content, char a, char b);
char	*try_get_color(char **content, char a);
char	**try_get_map(char **content);
int		get_line_nbr(char **str);

/* check_map_format.c */
bool	check_its_valide(char **content);

/* check_map_wall.c */
bool	valid_wall(char **map);

/* data_init.c */
void	data_init(t_data *data, char *file);

/* check_map_content.c */
bool	valid_lines(char **map);
bool	check_zero_in_lines(char **map);

/* erroe,c */
void	ft_exit(char *message, t_data *data);
int		ft_exitt(void);


/* check_data.c */
bool	check_texture_path(char *path);
int		check_color(char *color);
int		get_color(int r, int g, int b);
void	ft_clear_tab(char **str);

/* get_data.c */
void	get_data(t_data *data, char *file);


/***************************************************/
/* ------------ RAYCASTING -------------- */
/* normalizeangle.c */
double normalizeangle(double angle);
/* to_rad.c */
double  to_rad(double degree);
/* render_line.c */
int	render_line(t_data *dt, double lng);


#endif