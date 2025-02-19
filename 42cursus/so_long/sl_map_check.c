/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:42:14 by sipyeon           #+#    #+#             */
/*   Updated: 2025/02/19 21:34:56 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	**sl_visited_init(t_vars *game)
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

static void	sl_check_path_dfs(t_vars *game, t_check *route, int y, int x)
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
		if (game->map.info[ny][nx] != WALL && route->visited[ny][nx] == 0)
			sl_check_path_dfs(game, route, ny, nx);
	}
}

static void	sl_err_msg(t_vars *game, t_check *route)
{
	free_map(game->map.info);
	visited_free(route->visited);
	if (!route->valid_path)
		exit(write(2, "Invalid map (no path found)\n", 29));
	else if (game->map.c_count != route->valid_collect)
		exit(write(2, "Invalid map (cannot collect collectibles)\n", 43));
	else if (game->map.size != (game->map.x_len * game->map.y_len))
		exit(write(2, "Invalid map (map is not rectangle)\n", 36));
	else if (game->map.c_count <= 0)
		exit(write(2, "Invalid map (no collectible)\n", 30));
	else
		exit(write(2, "Unknown error\n", 15));
}

static void	sl_obj_validity(t_vars *game)
{
	if (game->map.player_count != 1)
	{
		free_map(game->map.info);
		exit(write(2, "Invalid player count (one player shoud exist)\n", 47));
	}
	else if (game->map.exit_count != 1)
	{
		free_map(game->map.info);
		exit(write(2, "Invalid exit count (map should have one exit)\n", 47));
	}
}

void	check_map_validity(t_vars *game, char **map)
{
	t_check	route;

	ft_bzero(&route, sizeof(t_check));
	map_obj_counter(game, map);
	sl_obj_validity(game);
	route.visited = sl_visited_init(game);
	sl_check_path_dfs(game, &route, game->map.p_y, game->map.p_x);
	if (game->map.size != (game->map.x_len * game->map.y_len))
		game->map.valid = 0;
	else if (!route.valid_path || game->map.c_count != route.valid_collect)
		game->map.valid = 0;
	else if (game->map.player_count != 1 || game->map.exit_count != 1)
		game->map.valid = 0;
	else if (game->map.c_count <= 0)
		game->map.valid = 0;
	if (!game->map.valid)
		sl_err_msg(game, &route);
	visited_free(route.visited);
}
