#include <unistd.h>
#include <mlx.h>
#define TILE_SIZE 32
#define RED_PIXEL 0xFF0000

typedef struct	s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
}	t_rect;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// int render_rect(t_data *data, t_rect rect, int color)
// {
// 	int	i;
// 	int j;

// 	if (data->win == NULL)
// 		return (1);
// 	i = rect.y;
// 	while (i < rect.y + rect.height)
// 	{
// 		j = rect.x;
// 		while (j < rect.x + rect.width)
// 			my_mlx_pixel_put(data, i, j, color);
// 		++i;
// 	}
// 	return (0);
// }


int render_rect(t_data *data, t_rect rect, int color)
{
	int	i;
	int j;

	// if (data->win == NULL)
	// 	return (1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			my_mlx_pixel_put(data, i, j++, color);
		++i;
	}
	return (0);
}

int	main(void)
{
	t_data	img;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(img.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	render_rect(&img, (t_rect){5 , 5 , 50, 100}, RED_PIXEL);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_loop(img.mlx);
    return (0);
}