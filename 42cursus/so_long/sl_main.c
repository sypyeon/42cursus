/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:34:24 by sipyeon           #+#    #+#             */
/*   Updated: 2025/02/14 11:30:26 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_loop(t_vars *game)
{
	int	i;

	i = 0;
	while (i < game->map.y_len)
	{
		draw_map(game, game->map.info[i], i);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	game;

	if (ac != 2)
		return (write(2, "Error (wrong input)\n", 21));
	ft_bzero(&game, sizeof(t_vars));
	map_size_check(&game, av[1]);
	get_map(&game, av[1]);
	check_map_validity(&game, game.map.info);
	ft_printf("Minimum move count of this map is %d!!!\n", game.min_move);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.x_len * TILE,
			game.map.y_len * TILE, "so_long");
	mlx_hook(game.win, KEY_PRESS, 1, sl_keybind, &game);
	mlx_hook(game.win, ON_DESTROY, 0, close_game, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
