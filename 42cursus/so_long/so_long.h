/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:17:36 by sipyeon           #+#    #+#             */
/*   Updated: 2025/01/25 22:31:02 by sipyeon          ###   ########.fr       */
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

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

# define ROAD			0
# define WALL			1
# define COLLECT		67
# define EXIT			69
# define PLAYER			'P'
# define TILE			64

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_param
{
	int		x;
	int		y;
}				t_param;

typedef struct	s_img
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
	int		**visited;
	int		player_count;
	int		exit_count;
	int		c_count;
}				t_map;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	map;
	t_param	location;
}				t_vars;

typedef struct s_check //맵 유효성 확인
{
	int	x;
	int	y;
	int	c_count;
	int	**visited;
}	t_check;

int				close_game(t_vars *game);
int				sl_keybind(int keycode, t_vars *game);

void			map_size_check(t_vars *game, char **map);
void			get_map(t_vars *game, char *map);
void			check_map_validity(t_vars *game, char **map);
int 			check_path_dfs(int x, int y, char **map, char find_char, int height);

void			two_d_free(char **to_free);

#endif
