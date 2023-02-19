/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 08:31:56 by ctardy            #+#    #+#             */
/*   Updated: 2022/03/16 10:33:33 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include "./minilibx/mlx.h"
# include "./libft/libft.h"

typedef struct s_map
{
	char	**map;
}	t_map_init;

typedef struct s_player
{
	int			horizontal;
	int			vertical;
	t_map_init	map;
}	t_player;

typedef struct s_errors
{
	int	col;
	int	play;
	int	ex;

}	t_errors;

typedef struct s_so_long
{
	t_map_init	map_init;
	t_player	player;
	t_errors	map_err;

	void		*mlx;
	void		*window;

	void		*floor_img;
	void		*wall_img;
	void		*player_img;
	void		*collect_img;
	void		*exit_img;

	int			collectible;
	int			total_collect;

	int			steps;

	char		*path_floor;
	char		*path_wall;
	char		*path_player;
	char		*path_collectible;
	char		*path_exit;

	int			width;
	int			height;
	int			i;
	int			j;

}	t_so_long;

void	up_w(t_so_long *game);
void	left_a(t_so_long *game);
void	down_s(t_so_long *game);
void	right_d(t_so_long *game);
int		player_move(int keycode, t_so_long *game);

int		total_collectible(t_so_long *game);
int		exit_game(void);

int		count_line_map(char **argv);
void	map_reader(t_so_long *game, char **argv);
void	put_floor_map(t_so_long *game);
void	put_stuff_on_map(t_so_long *game);

void	put_floor(t_so_long *path, int x, int y);
void	put_wall(t_so_long *game, int x, int y);
void	put_collectible(t_so_long *game, int x, int y);
void	put_player(t_so_long *game, int x, int y);
void	put_exit(t_so_long *game, int x, int y);

void	set_collectible(t_so_long *game, int w, int h);
void	set_player(t_so_long *game, int w, int h);

void	image_creator(t_so_long *game);

int		wall_error_l(t_so_long *game);
int		wall_error_r(t_so_long *game);
int		check_tiles(t_so_long *game);
int		check_mandatory(t_so_long *game);
int		is_it_square(t_so_long *game);
void	errors(t_so_long *game);

void	update_map(int x, int y, t_so_long *path);
void	current_field(int x, int y, t_so_long *path);

void	nbr_collect(t_so_long *game);
void	check_collect(t_so_long *game);

void	ber_verif(char *argv);
void	fd_verif(char *str);

#endif