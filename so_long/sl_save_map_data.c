/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_save_map_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:37:29 by sipyeon           #+#    #+#             */
/*   Updated: 2025/02/15 18:21:03 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}

void	get_map(t_vars *game, char *map_info)
{
	int	i;
	int	fd;

	fd = open(map_info, O_RDONLY);
	game->map.info = (char **)ft_calloc(sizeof(char *), game->map.y_len + 1);
	if (!game->map.info)
		exit(errno);
	game->map.info[0] = get_next_line(fd);
	game->map.x_len = ft_strlen(game->map.info[0]) - 1;
	game->map.info[0][game->map.x_len] = '\0';
	i = 1;
	while (i < game->map.y_len)
	{
		game->map.info[i] = get_next_line(fd);
		if (!game->map.info[i])
			break ;
		game->map.info[i][game->map.x_len] = '\0';
		i++;
	}
	get_next_line(fd);
	close(fd);
	game->map.valid = 1;
}

void	map_size_check(t_vars *game, char *map_name)
{
	char	*temp;
	char	*buf;
	int		fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit(write(2, "Map data not found.\n", 21));
	while (1)
	{
		buf = get_next_line(fd);
		if (!buf)
			break ;
		if (ft_strrchr(buf, '\n'))
			buf[ft_strlen(buf) - 1] = '\0';
		if (!game->map.flat)
			game->map.flat = ft_strdup("");
		temp = game->map.flat;
		game->map.flat = ft_strjoin(game->map.flat, buf);
		free(temp);
		free(buf);
		game->map.y_len += 1;
	}
	close(fd);
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

void	sl_texture_check(t_vars *game, char *texture)
{
	int		i;
	int		check;

	i = 0;
	while (game->map.flat[i])
	{
		check = 0;
		while (texture[check])
		{
			if (game->map.flat[i] == texture[check])
				break ;
			check++;
		}
		if (check == 5)
		{
			free(game->map.flat);
			free_map(game->map.info);
			exit(write(2, "Invalid map (invalid texture)\n", 31));
		}
		i++;
	}
}
