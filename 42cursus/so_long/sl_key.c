/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:40:01 by sipyeon           #+#    #+#             */
/*   Updated: 2025/01/25 21:34:45 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_vars *game)
{
	mlx_destroy_image(game->mlx, game->img.ptr);
	mlx_destroy_display(game->mlx);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit (0);
	return (0);
}

int	sl_keybind(int keycode, t_vars *game)
{
	if (keycode == KEY_W)
		game->location.y -= TILE;
	else if (keycode == KEY_A)
		game->location.x -= TILE;
	else if (keycode == KEY_S)
		game->location.y += TILE;	
	else if (keycode == KEY_D)
		game->location.x += TILE;
	else if (keycode == KEY_ESC)
		close_game(game);
	return (0);
}