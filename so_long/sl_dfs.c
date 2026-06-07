/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_dfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:00:09 by sipyeon           #+#    #+#             */
/*   Updated: 2025/02/21 18:06:08 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	**sl_visited_init(t_vars *game)
{
	int	**visited;
	int	i;

	i = 0;
	visited = (int **)ft_calloc(sizeof(int *), game->map.y_len + 2);
	if (!visited)
		return (0);
	while (i < game->map.y_len)
	{
		visited[i] = (int *)ft_calloc(sizeof(int), (game->map.x_len + 2));
		if (!visited[i])
			exit(errno);
		i++;
	}
	return (visited);
}

void	sl_collectible_dfs(t_vars *game, t_check *route, int y, int x)
{
	const int	dx[4] = {0, 0, 1, -1};
	const int	dy[4] = {1, -1, 0, 0};
	int			ny;
	int			nx;
	int			i;

	route->visited[y][x] = 1;
	if (game->map.info[y][x] == 'C')
		route->valid_collect += 1;
	if (game->map.info[y][x] == 'E')
		route->valid_path += 1;
	i = 0;
	while (i < 4)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		i++;
		if (game->map.info[ny][nx] != WALL && game->map.info[ny][nx] != EXIT
			&& route->visited[ny][nx] == 0)
			sl_collectible_dfs(game, route, ny, nx);
	}
}

void	sl_exit_dfs(t_vars *game, t_check *route, int y, int x)
{
	const int	dx[4] = {0, 0, 1, -1};
	const int	dy[4] = {1, -1, 0, 0};
	int			ny;
	int			nx;
	int			i;

	route->visited[y][x] = 1;
	if (game->map.info[y][x] == 'E')
	{
		route->valid_path = 1;
		return ;
	}
	i = 0;
	while (i < 4)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		i++;
		if (game->map.info[ny][nx] != WALL && route->visited[ny][nx] == 0)
			sl_exit_dfs(game, route, ny, nx);
	}
}
