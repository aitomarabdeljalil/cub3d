/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:49:39 by aait-oma          #+#    #+#             */
/*   Updated: 2022/12/02 17:57:42 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->ml.addr + (y * data->ml.line_length + x * (data->ml.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int render_rect(t_data *data, t_rect rect)
{
	int	i;
	int j;

	if (data->ml.win == NULL)
		return (1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			mlx_pixel_put(data->ml.mlx, data->ml.win, j++, i, rect.color);
		++i;
	}
	return (0);
}

void find_player(char **map, t_player *player)
{
	int i;
	int j;
	
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '0' && map[i][j] != '1')
			{
                player->x = j * TILE_SIZE + TILE_SIZE / 2;
				player->y = i * TILE_SIZE + TILE_SIZE / 2;
            }
		}
	}
}

void	player_init(t_data *dt)
{
	find_player(dt->map, &dt->pl);
	dt->pl.radius = 3;
	dt->pl.turndirection = 0;
	dt->pl.walkdirection = 0;
	dt->pl.movespeed = 4;
	dt->pl.rotationspeed = 2 * (M_PI / 180);
	dt->pl.rotationangle =  3 * M_PI / 2;
}

void	game_init(t_data *dt)
{

	dt->ml.hgt = 7;
	dt->ml.wth = 13;
	dt->ml.mlx = mlx_init();
	dt->ml.win = mlx_new_window(dt->ml.mlx, 1000, 1000, "cub3d");
	dt->ml.minimap = mlx_new_image(dt->ml.mlx, MAP_WIDTH, MAP_HEIGHT);
	
	player_init(dt);
}

void	print_win(t_data *th, int x, int y)
{
	if (th->map[x][y] == '1')
		render_rect(th, (t_rect){y * TILE_SIZE, x * TILE_SIZE, TILE_SIZE, TILE_SIZE, RED_PIXEL});
	else
		render_rect(th, (t_rect){y * TILE_SIZE, x * TILE_SIZE, TILE_SIZE, TILE_SIZE, 0xfffffff});
	render_rect(th, (t_rect){th->pl.x, th->pl.y, 1, 1, RED_PIXEL});
	render_line(th, 15);
}

void	reload_win(t_data *dt)
{
	int	x;
	int	y;

	x = 0;
	while (dt->map[x])
	{
		y = 0;
		while (dt->map[x][y])
		{
			print_win(dt, x, y);
			y++;
		}
		x++;
	}
}

int	clear_reload(t_data *dt)
{
	mlx_clear_window(dt->ml.mlx, dt->ml.win);
	reload_win(dt);
	return (0);
}

bool	thereiswall(int x, int y, t_data *dt)
{
	int i;
	int j;

	i = floor((double)y / TILE_SIZE);
	j = floor((double)x / TILE_SIZE);
	if (dt->map[i][j] == '1')
		return (true);
	return (false);
}

int 	keyPress(int keycode, t_data *dt)
{
	double movestep;
	int	new_x;
	int	new_y;
    
	new_x = dt->pl.x;
	new_y = dt->pl.y;
	dt->pl.rotationangle = normalizeangle(dt->pl.rotationangle);
	if (keycode == 13) // key 13 == W
	{
		dt->pl.walkdirection = 1;
		movestep = dt->pl.walkdirection * dt->pl.movespeed;
		new_x += (int)(cos(dt->pl.rotationangle) * movestep);
		new_y += (int)(sin(dt->pl.rotationangle) * movestep);
	}
	if (keycode == 1) // key 1 == S
	{
		dt->pl.walkdirection = -1;
		movestep = dt->pl.walkdirection * dt->pl.movespeed;
		new_x += (int)(cos(dt->pl.rotationangle) * movestep); 
		new_y += (int)(sin(dt->pl.rotationangle) * movestep);
	}
	if (keycode == 0) // key 0 == A
	{
		new_x += (int)(cos(dt->pl.rotationangle - (M_PI / 2)) * dt->pl.movespeed);
		new_y += (int)(sin(dt->pl.rotationangle - (M_PI / 2)) * dt->pl.movespeed);
	}
	if (keycode == 2) // key 2 == D
	{
		new_x += (int)(cos(dt->pl.rotationangle + (M_PI / 2)) * dt->pl.movespeed);
		new_y += (int)(sin(dt->pl.rotationangle + (M_PI / 2)) * dt->pl.movespeed);
	}
	if (keycode == 124)
	{
		dt->pl.turndirection = 1;
		dt->pl.rotationangle += dt->pl.turndirection * dt->pl.rotationspeed;
	}
	else if (keycode == 123)
	{
		dt->pl.turndirection = -1;
		dt->pl.rotationangle += dt->pl.turndirection * dt->pl.rotationspeed;
	}
	if (keycode == 53)
		exit(0);
	if (!thereiswall(new_x, new_y, dt))
	{
		dt->pl.x = new_x;
		dt->pl.y = new_y;
	}
	return 0;
}

int 	keyreleased(int keycode, t_data *dt)
{
	if (keycode == 13)
		dt->pl.walkdirection = 0;
	else if (keycode == 1)
		dt->pl.walkdirection = 0;
	else if (keycode == 124)
		dt->pl.turndirection = 0;
	else if (keycode == 123)
		dt->pl.turndirection = 0;
	return 0;
}

int main(int ac, char **av)
{
	t_data	*dt;

	(void)ac;
	dt = malloc(sizeof(t_data));
	get_data(dt, av[1]);
	game_init(dt);
	reload_win(dt);
	mlx_hook(dt->ml.win, 2, 1L<<0, keyPress, dt);
	mlx_hook(dt->ml.win, 3, 2L<<0, keyreleased, dt);
	mlx_loop_hook(dt->ml.mlx, clear_reload, dt);
	mlx_loop(dt->ml.mlx);
	free(dt);
    return (0);
}
