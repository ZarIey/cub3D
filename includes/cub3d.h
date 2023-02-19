#ifndef CUB_H
# define CUB_H

# include <fcntl.h>
# include <errno.h>
# include <unistd.h>

#include "./minilibx/mlx.h"
#include "./libft/libft.h"

typedef struct s_map
{
	char **map;
} 	t_map;


typedef struct s_game
{
	void		*mlx;
	void		*window;

	int window_height;
	int window_width;

}	t_game ;





#endif