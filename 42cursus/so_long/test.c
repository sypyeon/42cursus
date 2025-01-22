#include "so_long.h"

int	close_game(t_vars *game)
{
	mlx_destroy_image(game->mlx, game->img.ptr);
	mlx_destroy_image(game->mlx, game->img.ptr);
	mlx_destroy_image(game->mlx, game->img.ptr);
	mlx_destroy_image(game->mlx, game->img.ptr);
	mlx_destroy_image(game->mlx, game->img.ptr);
	mlx_destroy_image(game->mlx, game->img.ptr);
	mlx_destroy_display(game->mlx);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit (0);
	return (0);
}

int	game_keypress(int keycode, t_vars *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	return (0);
}

int	sl_player_move(int keycode, t_vars game)
{
	if (keycode == KEY_W)
		game.img.location.y -= TILE;
	else if (keycode == KEY_A)
		game.img.location.x -= TILE;
	else if (keycode == KEY_S)
		game.img.location.y += TILE;	
	else if (keycode == KEY_D)
		game.img.location.x += TILE;
	return (0);
}

void	map_size_check(t_vars *game, int fd)
{
	int		i;
	char	*total;
	char	*buf;
	char	*temp;

	total = ft_strdup("");
	while (1)
	{
		buf = get_next_line(fd);
		if (!buf)
			break;
		temp = total;
		total = ft_strjoin(total, buf);
		free(buf);
		free(temp);
		i++;
	}
	game->map.size = ft_strlen(total);
}

void	get_map(t_vars *game, int fd)
{
	int		i;
	char	**map;

	map = (char **)malloc(sizeof(char *) * game->map.size);
	if (!map)
	{
		perror("map");
		exit(errno);
	}
	i = 0;
	while (game->map.size > i)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	game->map.info = map;
}

void	struct_init(t_vars *game)
{
	game->img.ptr = 0;
	game->img.addr = 0;
	game->img.line_length = 0;
	game->location.x = 0;
	game->location.y = 0;
	game->map.x_len = 0;
	game->map.y_len = 0;
	game->map.size = 0;
	game->map.valid = 0;
	game->map.info = NULL;
}

int	main(int ac, char **av)
{	
	t_vars	game;
	int		fd;

	if (ac != 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	get_map(&game, fd);
	char	*player = "./textures/player/player.xpm";
	char	*block_tile = "./textures/block_tile.xpm";
	int		img_width = 64;
	int		img_height = 64;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1024, 768, "so_long");
	game.img.ptr = mlx_xpm_file_to_image(game.mlx, player, &img_width, &img_height);
	game.img.ptr = mlx_xpm_file_to_image(game.mlx, block_tile, &img_width, &img_height);
	game.location.x = 0;
	game.location.y = 0;

	mlx_put_image_to_window(game.mlx, game.win, game.img.ptr, game.location.x * TILE, game.location.y * TILE);

	mlx_hook(game.win, KEY_PRESS, 1L<<0, game_keypress, &game); //조작 키 및 ESC
	mlx_hook(game.win, 17, 0L, close_game, &game); //X키 클릭
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