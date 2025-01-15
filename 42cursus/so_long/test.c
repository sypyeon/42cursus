#include "./mlx/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

// int	close(int keycode, t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

unsigned char	get_t(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

unsigned char	get_r(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

unsigned char	get_g(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

unsigned char	get_b(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_data	drawing;
	int x = 1;
	int y = 1;

	char	*relative_path = "./pokemon.xpm";
	int		img_width = 500;
	int		img_height = 500;

	mlx = mlx_init();
	drawing.img = mlx_new_image(mlx, 500, 500);
	img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	drawing.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&drawing, 250, 250, 0x00FF0000);
	int color = 0x0000000f;
	while (x < 500 && y < 500) //테두리 (파란색 그라데이션)
	{
		my_mlx_pixel_put(&drawing, 0, y, color);
		my_mlx_pixel_put(&drawing, 499, x, color);
		my_mlx_pixel_put(&drawing, x, 499, color);
		my_mlx_pixel_put(&drawing, x, 0, color);
		color += 1;
		x++;
		y++;
	}
	x = 100;
	y = 300;
	int z = 0;
	while (x < 200 && y < 400) //삼각형(빨간색)
	{
		my_mlx_pixel_put(&drawing, x, 400, 0x00FF0000);
		my_mlx_pixel_put(&drawing, (300 + z) / 2, y, 0x00FF0000);
		my_mlx_pixel_put(&drawing, (300 - z) / 2, y, 0x00FF0000);
		x++;
		y++;
		z++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, drawing.img, 0, 0);
	mlx_loop(mlx);
}

// int	main(void)
// {
// 	void	*img;
// 	char	*relative_path = "./pokemon.xpm";
// 	int		img_width;
// 	int		img_height;

// 	mlx = mlx_init();
// 	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
// }