/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:17:36 by sipyeon           #+#    #+#             */
/*   Updated: 2025/01/20 19:15:35 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include <stdlib.h>

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

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
# define EXIT_TILE		'E'
# define WALL_TILE		1
# define ROAD_TILE		0

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_param{
	int		x;
	int		y;
}				t_param;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_param	location;
}				t_data;

typedef struct s_map{
	int		x_len;
	int		y_len;
	int		map_size;
	int		valid;
	char	**map;
}				t_map;


typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data	img[256];
	t_map	map;
	
}				t_vars;

int				create_trgb(unsigned char t, unsigned char r, 
							unsigned char g, unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);

#endif
