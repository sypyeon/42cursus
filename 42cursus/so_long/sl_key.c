/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:40:01 by sipyeon           #+#    #+#             */
/*   Updated: 2025/02/15 14:26:19 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_vars *game)
{
	mlx_destroy_image(game->mlx, game->img.ptr);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free_map(game->map.info);
	free(game->mlx);
	exit (0);
	return (0);
}

void	sl_player_move(t_vars *game, int x_move, int y_move)
{
	int		x;
	int		y;
	char	**map;

	x = game->map.p_x;
	y = game->map.p_y;
	map = game->map.info;
	if (map[y + y_move][x + x_move] != '1')
	{
		if (map[y + y_move][x + x_move] == 'C')
			game->map.c_count--;
		if (map[y + y_move][x + x_move] == 'E' && game->map.c_count == 0)
		{
			ft_printf("%d\n", game->move_count + 1);
			close_game(game);
		}
		else if (map[y + y_move][x + x_move] == 'E' && game->map.c_count != 0)
			return ;
		map[y + y_move][x + x_move] = 'P';
		map[y][x] = '0';
		game->map.p_x += x_move;
		game->map.p_y += y_move;
		game->move_count += 1;
		ft_printf("%d\n", game->move_count);
	}
}

int	sl_keybind(int keycode, t_vars *game)
{
	if (keycode == KEY_W)
	{
		sl_player_move(game, 0, -1);
		game->player_face = UP;
	}
	else if (keycode == KEY_A)
	{
		sl_player_move(game, -1, 0);
		game->player_face = LEFT;
	}
	else if (keycode == KEY_S)
	{
		sl_player_move(game, 0, 1);
		game->player_face = DOWN;
	}
	else if (keycode == KEY_D)
	{
		sl_player_move(game, 1, 0);
		game->player_face = RIGHT;
	}
	else if (keycode == KEY_ESC)
		close_game(game);
	return (0);
}
