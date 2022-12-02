/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:04:43 by aait-oma          #+#    #+#             */
/*   Updated: 2022/11/24 18:19:54 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include <mlx.h>
#define MLX_ERROR 1

#define RED_PIXEL 0xFF0000

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

typedef struct s_data
{
	void	    *mlx_ptr;
	void	    *win_ptr;
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

/* The x and y coordinates of the rect corresponds to its upper left corner. */

int render_rect(t_data *data, t_rect rect)
{
	int	i;
	int j;

	if (data->win_ptr == NULL)
		return (1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_map(t_data *data, int x, int y, int color)
{
	render_rect(data, (t_rect){x, y, 32, 32, RED_PIXEL});
}

int	render(t_data *data)
{
	render_rect(data, (t_rect){0, 0, 32, 32, RED_PIXEL});
	return (0);
}

void	render_background(t_data *data, int color)
{
	int	i;
	int	j;

	if (data->win_ptr == NULL)
		return ;
	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, color);
		++i;
	}
}

int	ft_exit(t_data *data)
{
	(void)data;
	exit(0);
}

int    main(int ac, char **av)
{
    t_data    data;
    int        i;

    data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "my window");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}

    // render(&data);
    /* Setup hooks */ 
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, 17, 2, ft_exit, &data);
	mlx_loop(data.mlx_ptr);
    return 0;
}