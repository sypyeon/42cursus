/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_save_map_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:37:29 by sipyeon           #+#    #+#             */
/*   Updated: 2025/02/14 10:53:02 by sipyeon          ###   ########.fr       */
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
			break;
		game->map.info[i][game->map.x_len] = '\0';
		i++;
	}
	get_next_line(fd);
	close(fd);
}

void	map_size_check(t_vars *game, char *map_name)
{
	int		i;
	char	*temp;
	char	*buf;
	int		fd;

	fd = open(map_name, O_RDONLY);
	i = 0;
	game->map.flat = ft_strdup("");
	while (1)
	{
		buf = get_next_line(fd);
		if (!buf)
			break;
		if (ft_strchr(buf, '\n'))
			buf[ft_strlen(buf) - 1] = '\0';
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
