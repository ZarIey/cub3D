#ifndef CUB_H
# define CUB_H

# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <math.h>
#include <stdio.h>

#include "./minilibx/mlx.h"
#include "./libft/libft.h"

typedef struct s_map
{
	char **map;
} 	t_mapstr;

typedef struct s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct t_num
{
	double *time;
	double *old_time;
	double *plane_x;
	double *plane_y;
	double *pos_x;
	double *pos_y;
	double *dir_x;
	double *dir_y;

}	t_num;

typedef struct s_game
{
	void		*mlx;
	void		*window;

	t_mapstr	mapstr;
	int			window_height;
	int			window_width;

	int flag;

}	t_game ;

// parsing

int map_reader(t_game *game, char **argv, int flag);


// color

int	create_trgb(int t, int r, int g, int b);

// drawing

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw(t_data img, int x, int draw_start, int draw_end, int color);

#endif