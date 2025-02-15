/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:41:55 by sipyeon           #+#    #+#             */
/*   Updated: 2025/02/15 15:12:51 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_draw_player(t_vars *game, int *w, int *h)
{
	if (game->player_face == DOWN)
		game->img.ptr = mlx_xpm_file_to_image(game->mlx,
				"./textures/player/player_down.xpm", w, h);
	else if (game->player_face == UP)
		game->img.ptr = mlx_xpm_file_to_image(game->mlx,
				"./textures/player/player_up.xpm", w, h);
	else if (game->player_face == LEFT)
		game->img.ptr = mlx_xpm_file_to_image(game->mlx,
				"./textures/player/player_left.xpm", w, h);
	else if (game->player_face == RIGHT)
		game->img.ptr = mlx_xpm_file_to_image(game->mlx,
				"./textures/player/player_right.xpm", w, h);
	game->location.player = game->img.ptr;
}

void	sl_draw_tile(t_vars *game, char texture)
{
	int	w;
	int	h;

	if (texture == WALL)
		game->img.ptr = mlx_xpm_file_to_image(game->mlx, \
				"./textures/wall.xpm", &w, &h);
	else if (texture == COLLECT)
		game->img.ptr = mlx_xpm_file_to_image(game->mlx, \
				"./textures/collectible.xpm", &w, &h);
	else if (texture == EXIT)
		game->img.ptr = mlx_xpm_file_to_image(game->mlx, \
				"./textures/exit.xpm", &w, &h);
	else if (texture == ROAD)
		game->img.ptr = mlx_xpm_file_to_image(game->mlx, \
				"./textures/road.xpm", &w, &h);
	else if (texture == PLAYER)
		sl_draw_player(game, &w, &h);
}

void	draw_map(t_vars *game, char *line, int l)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == PLAYER)
		{
			game->location.x = i;
			game->location.y = l;
		}
		if (game->img.ptr)
			mlx_destroy_image(game->mlx, game->img.ptr);
		sl_draw_tile(game, line[i]);
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.ptr, i * TILE, l * TILE);
		i++;
	}
}
