/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:46:22 by bgales            #+#    #+#             */
/*   Updated: 2023/06/23 20:58:29 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

enum e_keycode
{
	A_KEY,
	S_KEY,
	D_KEY,
	W_KEY = 13,
	SPACE = 49,
	ECHAP = 53,
	ARROW_LEFT = 123,
	ARROW_RIGHT,
	ARROW_DOWN,
	ARROW_UP
};

typedef struct s_keys{
	int	a;
	int	d;
	int	w;
	int	s;
	int	up;
	int	down;
	int	left;
	int	right;
}	t_keys;

typedef struct s_player{
	float	x;
	float	y;
	float	pdx;
	float	pdy;
	float	pa;
	char	orientation;
}	t_player;

typedef struct s_map
{
	char	**map;
}	t_mapstr;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}	t_data;

typedef struct t_num
{
	double	time;
	double	old_time;
	double	frame_time;
	double	plane_x;
	double	plane_y;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	move_speed;
	double	rot_speed;
	double	start;
}	t_num;

typedef struct s_tex
{
	t_data	no;
	t_data	so;
	t_data	we;
	t_data	ea;
	int		tex_x;
	int		tex_y;
	int		texture_width;
	int		texture_height;
}	t_tex;

typedef struct s_parse
{
	char		**map;
	char		**ressources;
	int			map_width;
	int			map_height;
	int			player_x;
	int			player_y;
	int			c_rgb[3];
	int			f_rgb[3];
	char		*ceiling;
	char		*floor;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
}	t_parse;

typedef struct s_minimap
{
	char	**minimap;
	int		player_x;
	int		player_y;
	int		minimap_w;
	int		minimap_h;
}	t_minimap;

typedef struct s_game
{
	void		*mlx;
	void		*window;

	char		**map_ig;
	void		*minimap_img;
	int			window_height;
	int			window_width;
	t_num		numig;
	t_data		imgig;
	t_tex		texig;
	t_parse		*parse;
	t_keys		keys;
	t_minimap	minimap;
}	t_game;

typedef struct s_calc
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		*se_draw;
	int		color;
	int		x;
	int		w;
	int		h;
	double	wall_x;
	double	step;
	double	tex_pos;
}	t_calc;

#endif
