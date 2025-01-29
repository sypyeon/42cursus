/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:42:14 by sipyeon           #+#    #+#             */
/*   Updated: 2025/01/28 18:43:07 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	**sl_visited_init(t_vars *game)
{
	int	**visited;
	int	i;
	int	j;

	i = -1;
	visited = (int **)malloc(sizeof(int *) * game->map.y_len);
	if (!visited)
		return(0);
	while (++i < game->map.y_len - 1)
	{
		visited[i] = (int *)malloc(sizeof(int) * (game->map.x_len + 1));
		if (!visited[i])
		{
			visited_free(visited);
			return (0);
		}
		j = -1;
		while (j < game->map.x_len)
			visited[i][++j] = 0;
	}
	return (visited);
}

void	sl_init_route(t_check *route, t_vars *game)
{
	route->x = 0;
	route->y = 0;
	route->valid_path = 0;
	route->valid_collect = 0;
	route->visited = sl_visited_init(game);
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
		route->valid_collect += 1; // 출구가 존재하므로 유효한 경로로 임시 지정
	i = -1;
	while (++i < 4)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if (game->map.info[ny][nx] != '1' && !route->visited[ny][nx]) // 새로운 좌표가 벽이 아니고 방문하지 않았을 떄 dfs 탐색
			check_path_dfs(game, route, ny, nx);
	}
}

void	map_size_check(t_vars *game, char *map_info) //맵 열어서 총 길이 확인하고 
{
	int		i;
	char	*temp;
	char	*buf;
	int		fd;

	fd = open(map_info, O_RDONLY);
	i = 0;
	game->map.flat = ft_strdup("");
	while (1)
	{
		buf = get_next_line(fd);
		if (!buf)
			break;
		temp = game->map.flat;
		game->map.flat = ft_strjoin(game->map.flat, buf);
		free(temp);
		free(buf);
		i++;
	}
	close(fd);
	game->map.y_len = i;
	game->map.size = ft_strlen(game->map.flat);
}

void	sl_wall_check(t_vars *game, char **map, int bottom)
{
	int	i;
	int	last;

	i = 0;
	last = ft_strlen(map[0]) - 1;
	while (map[0][i] || map[bottom][i])
	{
		if (map[0][i] != '1' || map[bottom][i] != '1')
			exit(write(2, "Top and bottom no walls\n", 24));
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][last] != '1')
			exit(write(2, "No walls front and end\n", 23));
		i++;
	}
	game->map.valid = 1;
}

void	map_obj_counter(t_vars *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				game->map.player_count++;
				game->map.p_x = x;
				game->map.p_y = y;
			}
			else if (map[y][x] == 'C')
				game->map.c_count += 1;
			else if (map[y][x] == 'E')
				game->map.exit_count++;
			x++;
		}
		y++;
	}
	if (game->map.player_count != 1 || game->map.exit_count != 1)
		exit(write(2, "Invalid player or exit count\n", 12));
	else if (game->map.c_count <= 0)
		exit(write(2, "Need collectibles\n", 12));
}

void	check_map_validity(t_vars *game, char **map)
{
	t_check	route;
	sl_wall_check(game, map, game->map.y_len - 1);
	map_obj_counter(game, map);
	sl_init_route(&route, game);
	check_path_dfs(game, &route, game->map.p_x, game->map.p_y);
	if (!route.valid_path || game->map.c_count != route.valid_collect)
		exit(write(2, "Invalid path\n", 14));
}

void	get_map(t_vars *game, char *map_info)
{
	int		i;
	char	**map;
	int		fd;
	char	*new_line;

	fd = open(map_info, O_RDONLY);
	map = (char **)malloc(sizeof(char *) * game->map.y_len + 1);
	if (!map)
	{
		perror("map");
		exit(errno);
	}
	i = 0;
	while (1) //맵 한줄씩 저장해서 2차원 배열에 넣어두기
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			break;
		new_line = ft_strrchr(map[i], '\n');
		if (new_line)
			*new_line = '\0';
		i++;
	}
	game->map.x_len = ft_strlen(map[0]);
	game->map.info = map;
	close(fd);
}
