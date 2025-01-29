/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:41:55 by sipyeon           #+#    #+#             */
/*   Updated: 2025/01/28 17:17:37 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_draw_tile(t_vars *game, char texture)
{
	int	w;
	int	h;

	if (texture == '1') // '1'일 경우 벽
		game->img.ptr = mlx_xpm_file_to_image(game->mlx, \
				"./textures/wall.xpm", &w, &h);
	else if (texture == 'C') // 'C'일 경우 콜렉터블
		game->img.ptr = mlx_xpm_file_to_image(game->mlx, \
				"./textures/collectible.xpm", &w, &h);
	else if (texture == 'E') // 'E'일 경우 출구
		game->img.ptr = mlx_xpm_file_to_image(game->mlx, \
				"./textures/exit.xpm", &w, &h);
	else if (texture == '0') // '0'일 경우 빈공간
		game->img.ptr = mlx_xpm_file_to_image(game->mlx, \
				"./textures/road.xpm", &w, &h);
	else if (texture == 'P') // 'P'인 경우 플레이어
	{
		if (game->player_face == DOWN)
			game->img.ptr = mlx_xpm_file_to_image(game->mlx, 
				"./textures/player/player_down.xpm", &w, &h);
		else if (game->player_face == UP)
			game->img.ptr = mlx_xpm_file_to_image(game->mlx, 
				"./textures/player/player_up.xpm", &w, &h);
		else if (game->player_face == LEFT)
			game->img.ptr = mlx_xpm_file_to_image(game->mlx, 
				"./textures/player/player_left.xpm", &w, &h);
		else if (game->player_face == RIGHT)
			game->img.ptr = mlx_xpm_file_to_image(game->mlx, 
				"./textures/player/player_right.xpm", &w, &h);
		game->location.player = game->img.ptr; // 플레이어 위치에 대한 이미지 포인터도 저장해줌
	}
}

void	draw_map(t_vars *game, char *line, int l)
{
	int	i;

	i = 0;

	while (line[i])
	{
		if (line[i] == 'P') // 'P'일 경우 플레이어
		{
			game->location.x = i; // 플레이어의 x좌표
			game->location.y = l; // 플레이어의 y좌표 (64픽셀로 그림 그리기 때문) -> 가장 오른쪽 하단 꼭짓점이 좌표가 됨
		}
		if(game->img.ptr)
			mlx_destroy_image(game->mlx, game->img.ptr);
		sl_draw_tile(game, line[i]);
		mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, i * TILE, l * TILE); // 해당 위치의 이미지 저장값을 출력
		i++;
	}
}
