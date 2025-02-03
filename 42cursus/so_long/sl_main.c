#include "so_long.h"

int	game_loop(t_vars *game)
{
	int	i;

	i = -1;
	while(++i < game->map.y_len)
		draw_map(game, game->map.info[i], i);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	game;

	if (ac != 2)
		return (write(2, "Error (no input)\n", 17));
	ft_bzero(&game, sizeof(t_vars));
	map_size_check(&game, av[1]);
	get_map(&game, av[1]);
	check_map_validity(&game, game.map.info);
	
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.x_len * TILE, game.map.y_len * TILE, "so_long");

	mlx_hook(game.win, KEY_PRESS, 1L<<0, sl_keybind, &game); //조작 키 및 ESC
	mlx_hook(game.win, ON_DESTROY, 0L, close_game, &game); //X키 클릭
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
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

// int	main()
// {
	// drawing.img = mlx_new_image(mlx, 500, 500);
	// drawing.img = mlx_new_image(mlx, 500, 500);
	// int x = 1;
	// int y = 1;
	// drawing.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);
	// my_mlx_pixel_put(&drawing, 250, 250, 0x00FF0000);
	// int color = 0x0000000f;
	// while (x < 500 && y < 500) //테두리 (파란색 그라데이션)
	// {
	// 	my_mlx_pixel_put(&drawing, 0, y, color);
	// 	my_mlx_pixel_put(&drawing, 499, x, color);
	// 	my_mlx_pixel_put(&drawing, x, 499, color);
	// 	my_mlx_pixel_put(&drawing, x, 0, color);
	// 	color += 1;
	// 	x++;
	// 	y++;
	// }
	// x = 100;
	// y = 300;
	// int z = 0;
	// while (x < 200 && y < 400) //삼각형(빨간색)
	// {
	// 	my_mlx_pixel_put(&drawing, x, 400, 0x00FF0000);
	// 	my_mlx_pixel_put(&drawing, (300 + z) / 2, y, 0x00FF0000);
	// 	my_mlx_pixel_put(&drawing, (300 - z) / 2, y, 0x00FF0000);
	// 	x++;
	// 	y++;
	// 	z++;
	// }
	// mlx_put_image_to_window(mlx, mlx_win, drawing.img, 0, 0);
	// mlx_loop(mlx);
// }