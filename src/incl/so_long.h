/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorneli <marvin@codam.nl>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:19:41 by jcorneli          #+#    #+#             */
/*   Updated: 2021/10/15 23:38:58 by jcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PROJECT "so_long"
# define RESOLUTION_X 800
# define RESOLUTION_Y 600

# define STEP 40
# define PC_FILE "walk1.xpm"
# defube

# define KEY_RELEASE_MASK 1
# define BUTTON_PRESS_MASK 2
# define POINTER_MOTION_MASK 6
# define STRUCTURE_NOTIFY_MASK 17

# define KEY_RELEASE 3
# define BUTTON_PRESS 4
# define MOTION_NOTIFY 6
# define DESTROY_NOTIFY 17

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

# ifdef __linux__

typedef enum e_key
{
	A = 97,
	D = 100,
	S = 115,
	W = 119,
	M = 109,
	N = 110,
	P = 112,
	J = 106,
	K = 107,
	L = 108,
	Z = 122,
	F1 = 65470,
	F2 = 65471,
	PLUS = 61,
	MIN = 45,
	DOWN = 65364,
	UP = 65362,
	LEFT = 65361,
	RIGHT = 65363,
	B_SPACE = 65288,
	ESC = 65307
}			t_key;

# else

typedef enum e_key
{
	A = 0,
	D = 2,
	S = 1,
	W = 13,
	M = 46,
	N = 45,
	P = 35,
	J = 38,
	K = 40,
	L = 37,
	Z = 6,
	F1 = 122,
	F2 = 120,
	PLUS = 24,
	MIN = 27,
	DOWN = 125,
	UP = 126,
	LEFT = 123,
	RIGHT = 124,
	B_SPACE = 51,
	ESC = 53
}			t_key;

# endif

typedef struct s_resolution
{
	int	x;
	int	y;
}			t_resolution;

typedef struct s_position
{
	int	x;
	int	y;
}			t_position;

typedef struct s_size
{
	int x;
	int y;
}			t_size;

typedef struct s_grid
{
	int	x;
	int	y;
}			t_grid;

typedef struct s_img_data
{
	void	*img_ptr;
	char	*img_address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img_data;

typedef enum e_sprite_type
{
	PLAYER1,
	ENEMY1,
	WALL1,
	FLOOR1
}		t_sprite_type;

typedef struct s_sprite
{
	t_sprite_type	type;
	t_img_data		image;
	t_size			size;
	char			*file;
	struct s_sprite	*next;
}			t_sprite;

typedef struct s_scene
{
	t_resolution	res;
	t_position		player;
	t_grid			grid;
	t_sprite 		map;
	t_sprite		pc;
	t_sprite 		npc;
}		t_scene;

typedef struct s_mlx
{
	void					*mlx_ptr;
	void					*mlx_window;
	t_scene					scene;
	t_img_data				background;
}		t_mlx;

#endif
