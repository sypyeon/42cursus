#include "so_long.h"

int	mlx_close(int keycode, t_vars *game)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(game->mlx, game->img.img);
		mlx_destroy_display(game->mlx);
		mlx_destroy_window(game->mlx, game->win);
		free(game->mlx);
		exit (0);
	}
	return (0);
}

int	mlx_red_x(t_vars *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->img.img);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit (0);
	return (0);
}

int	sl_player_move(int keycode, t_vars game)
{
	if (keycode == 'd')
		game.img[PLAYER].location.x++;
	else if (keycode == 's')
		game.img[PLAYER].location.y++;
	if (keycode == 'a')
		game.img[PLAYER].location.x--;
	if (keycode == 'w')
		game.img[PLAYER].location.y--;
	return (0);
}

int	main(void)
{
	t_vars	game;

	char	*player = "./img_src/textures/player/player.xpm";
	char	*block_tile = "./img_src/textures/block_tile.xpm";
	int		img_width = 64;
	int		img_height = 64;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1024, 768, "so_long");
	game.img[PLAYER].img = mlx_xpm_file_to_image(game.mlx, player, &img_width, &img_height);
	game.img[WALL_TILE].img = mlx_xpm_file_to_image(game.mlx, block_tile, &img_width, &img_height);
	game.img[PLAYER].location.x = 1;
	game.img[PLAYER].location.y = 1;

	mlx_put_image_to_window(game.mlx, game.win, game.img[PLAYER].img, game.img[PLAYER].location.x, game.img[PLAYER].location.y);

	mlx_hook(game.win, X_EVENT_KEY_PRESS, 1L<<0, mlx_close, &game);
	mlx_hook(game.win, 17, 0L, mlx_red_x, &game);
	mlx_loop(game.mlx);
	return (0);
}

mlx_put

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