/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:17:36 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/06 00:04:27 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

# define KEY_PRESS		2
# define KEY_RELEASE	3
# define ON_DESTROY		17

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

# define ROAD			'0'
# define WALL			'1'
# define COLLECT		'C'
# define EXIT			'E'
# define PLAYER			'P'
# define TILE			64

# define DOWN			0
# define UP				1
# define LEFT			2
# define RIGHT			3

typedef struct s_param
{
	int		x;
	int		y;
}				t_param;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_map
{
	char	**info;
	char	*flat;
	int		x_len;
	int		y_len;
	int		size;
	int		valid;
	int		p_x;
	int		p_y;
	int		player_count;
	int		exit_count;
	int		c_count;
}				t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	map;
	t_param	location;
	int		player_face;
	int		move_count;
}	t_vars;

typedef struct s_check
{
	int	x;
	int	y;
	int	valid_path;
	int	valid_collect;
	int	**visited;
}	t_check;

int		close_game(t_vars *game);
int		sl_keybind(int keycode, t_vars *game);

void	draw_map(t_vars *game, char *line, int l);

void	map_size_check(t_vars *game, char *map_info);
void	get_map(t_vars *game, char *map);
void	sl_texture_check(t_vars *game, char *texture);
void	sl_wall_check(t_vars *game, char **map, int bottom);
void	map_obj_counter(t_vars *game, char **map);

void	check_map_validity(t_vars *game, char **map);

int		**sl_visited_init(t_vars *game);
void	sl_collectible_dfs(t_vars *game, t_check *route, int y, int x);
void	sl_exit_dfs(t_vars *game, t_check *route, int y, int x);

void	free_map(char **to_free);
void	visited_free(int **to_free);

#endif
