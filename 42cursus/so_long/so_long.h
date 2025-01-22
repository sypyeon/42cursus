/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:17:36 by sipyeon           #+#    #+#             */
/*   Updated: 2025/01/22 23:04:15 by sipyeon          ###   ########.fr       */
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

typedef struct s_param{
	int		x;
	int		y;
}				t_param;

typedef struct	s_img {
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_map{
	char	**info;
	int		x_len;
	int		y_len;
	int		size;
	int		valid;
}				t_map;

typedef struct	s_vars {
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

int				create_trgb(unsigned char t, unsigned char r, 
							unsigned char g, unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);

#endif
