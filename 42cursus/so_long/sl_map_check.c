/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:42:14 by sipyeon           #+#    #+#             */
/*   Updated: 2025/02/07 02:48:58 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	**sl_visited_init(t_vars *game)
{
	int	**visited;
	int	i;
	int	j;

	i = 0;
	visited = (int **)ft_calloc(sizeof(int *), game->map.y_len + 1);
	if (!visited)
		return(0);
	while (i < game->map.y_len)
	{
		visited[i] = (int *)malloc(sizeof(int) * (game->map.x_len + 1));
		if (!visited[i])
			exit(errno);
		j = 0;
		while (j < game->map.x_len)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	visited[i] = NULL;
	return (visited);
}

void	check_path_dfs(t_vars *game, t_check *route, int y, int x)
{
	const int	dx[4] = {0, 0, 1, -1}; // 네 방향 탐색
	const int	dy[4] = {1, -1, 0, 0};
	int			ny;
	int			nx;
	int			i;

	route->visited[y][x] = 1;
	if (game->map.info[y][x] == 'E')
		route->valid_path += 1;
	if (game->map.info[y][x] == 'C')
		route->valid_collect += 1;
	i = 0;
	while (i < 4)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		i++;
		if (game->map.info[ny][nx] != '1' && route->visited[ny][nx] == 0)
			check_path_dfs(game, route, ny, nx);
	}
}

void	sl_wall_check(t_vars *game, char **map, int bottom)
{
	int	i;
	int	last;

	i = 0;
	game->map.valid = 1;
	last = ft_strlen(map[0]) - 1;
	while (map[0][i] || map[bottom][i])
	{
		if (map[0][i] != '1' || map[bottom][i] != '1')
			game->map.valid = 0;
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][last] != '1')
			game->map.valid = 0;
		i++;
	}
	if (!game->map.valid)
	{
		free(game->map.flat);
		free_map(game->map.info);
		exit(write(2, "Invalid map (map not closed by wall)\n", 38));
	}
}

void	sl_texture_check(t_vars *game)
{
	int		i;
	int		check;
	char	texture[5] = "01ECP";

	i = 0;
	while (game->map.flat[i])
	{
		check = 0;
		while (texture[check])
		{
			if (game->map.flat[i] == texture[check])
				break;
			check++;
		}
		if (check == 5)
			game->map.valid = 0;
		i++;
	}
}

void	sl_err_msg(t_vars *game, t_check *route)
{
	free_map(game->map.info);
	visited_free(route->visited);
	if (!route->valid_path || game->map.c_count != route->valid_collect)
		exit(write(2, "Invalid map (no path found)\n", 29));
	if (game->map.size != (game->map.x_len * game->map.y_len))
		exit(write(2, "Invalid map (map is not rectangle)\n", 36));
	else if (game->map.player_count != 1 || game->map.exit_count != 1)
		exit(write(2, "Invalid map (no player or map)\n", 32));
	else if (game->map.c_count <= 0)
		exit(write(2, "Invalid map (no collectible)\n", 30));
}

void	check_map_validity(t_vars *game, char **map)
{
	t_check	route;
	ft_bzero(&route, sizeof(t_check));
	game->map.valid = 1;
	sl_texture_check(game);
	sl_wall_check(game, map, game->map.y_len - 1);
	map_obj_counter(game, map);
	route.visited = sl_visited_init(game);
	check_path_dfs(game, &route, game->map.p_x, game->map.p_y);
	if (game->map.size != (game->map.x_len * game->map.y_len))
		game->map.valid = 0;
	else if (!route.valid_path || game->map.c_count != route.valid_collect)
		game->map.valid = 0;
	else if (game->map.player_count != 1 || game->map.exit_count != 1)
		game->map.valid = 0;
	else if (game->map.c_count <= 0)
		game->map.valid = 0;
	free(game->map.flat);
	if (!game->map.valid)
		sl_err_msg(game, &route);
	visited_free(route.visited);
}
