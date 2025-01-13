#include "./mlx/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int x = 1;
	int y = 1;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 250, 250, 0x00FF0000);
	int color = 0x00000000;
	while (x < 500 && y < 500)
	{
		my_mlx_pixel_put(&img, 0, y, color);
		my_mlx_pixel_put(&img, 499, x, color);
		my_mlx_pixel_put(&img, x, 499, color);
		my_mlx_pixel_put(&img, x, 0, color);
		color += 1;
		x++;
		y++;
	}
	x = 100;
	y = 300;
	int z = 0;
	while (x < 200 && y < 400)
	{
		my_mlx_pixel_put(&img, x, 400, 0x00FF0000);
		my_mlx_pixel_put(&img, (300 + z) / 2, y, 0x00FF0000);
		my_mlx_pixel_put(&img, (300 - z) / 2, y, 0x00FF0000);
		x++;
		y++;
		z++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
