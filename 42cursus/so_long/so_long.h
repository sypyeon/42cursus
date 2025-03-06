/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:17:36 by sipyeon           #+#    #+#             */
/*   Updated: 2025/03/06 19:05:16 by sipyeon          ###   ########.fr       */
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
	int		x; //X좌표
	int		y; //Y좌표
	void	*player; //다시 보니 필요 없을 수도
}	t_param;

typedef struct s_img
{
	void	*ptr; //이미지 포인터
	char	*addr; //이미지 경로(디렉토리 및 파일 이름)
	int		bpp; //뭔지 모름 도큐멘트에 있었음
	int		line_length; //모름
	int		endian; //모름
}	t_img;

typedef struct s_map
{
	char	**info; //맵을 char 2차원 배열로 저장
	char	*flat; //맵을 일자로 저장 (길이 얼만지 확인)
	int		x_len; //맵 가로길이
	int		y_len; //맵 세로길이
	int		size; //x * y
	int		valid; //유효성 플래그
	int		p_x; //플레이어 X좌표
	int		p_y; //플레이어 Y좌표
	int		player_count; //맵의 P 갯수
	int		exit_count; //맵의 E 갯수
	int		c_count; //맵의 C 갯수
}	t_map;

typedef struct s_vars //구조체 저장하고 있는 제일 큰 구조체 (모든 정보를 담고 있음)
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	map;
	t_param	location;
	int		player_face;
	int		move_count;
}	t_vars;
/**
 * int	x; //x좌표
 * int	y; //y좌표
 * int	valid_path; //출구 유효 플래그
 * int	valid_collect; //아이템 회수 유효성 플래그
 * int	**visited; //0으로 초기화한 2차원 배열 (방문할때마다 1로 초기화)
 */
typedef struct s_check 
{
	int	x; //x좌표
	int	y; //y좌표
	int	valid_path; //출구 유효 플래그
	int	valid_collect; //아이템 회수 유효성 플래그
	int	**visited; //0으로 초기화한 2차원 배열 (방문할때마다 1로 초기화)
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
