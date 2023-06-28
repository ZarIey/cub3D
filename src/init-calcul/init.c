/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:31:43 by bgales            #+#    #+#             */
/*   Updated: 2023/06/27 17:00:42 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cam_eastwest(t_game *game)
{
	if ((*game).parse->map[(*game).parse->player_y]
		[(*game).parse->player_x] == 'W')
	{
		(*game).numig.dir_x = -1;
		(*game).numig.dir_y = 0;
		(*game).numig.plane_x = 0;
		(*game).numig.plane_y = 0.66;
	}
	else if ((*game).parse->map[(*game).parse->player_y]
		[(*game).parse->player_x] == 'E')
	{
		(*game).numig.dir_x = 1;
		(*game).numig.dir_y = 0;
		(*game).numig.plane_x = 0;
		(*game).numig.plane_y = -0.66;
	}
}

void	init_camera_dir(t_game *game)
{
	if ((*game).parse->map[(*game).parse->player_y]
		[(*game).parse->player_x] == 'N')
	{
		(*game).numig.dir_x = 0;
		(*game).numig.dir_y = -1;
		(*game).numig.plane_x = -0.66;
		(*game).numig.plane_y = 0;
	}
	else if ((*game).parse->map[(*game).parse->player_y]
		[(*game).parse->player_x] == 'S')
	{
		(*game).numig.dir_x = 0;
		(*game).numig.dir_y = 1;
		(*game).numig.plane_x = 0.66;
		(*game).numig.plane_y = 0;
	}
	else
		init_cam_eastwest(game);
}

void	init_keys(t_game *game)
{
	game->keys.a = 0;
	game->keys.d = 0;
	game->keys.w = 0;
	game->keys.s = 0;
	game->keys.up = 0;
	game->keys.down = 0;
	game->keys.left = 0;
	game->keys.right = 0;
}

void	init_numig(t_game *game)
{
	game->numig.time = 0;
	game->numig.start = time_calculator();
	game->numig.old_time = 0;
	game->numig.old_time = game->numig.time;
	game->numig.time = time_calculator() - game->numig.start;
	game->numig.pos_x = game->parse->player_x + 0.5;
	game->numig.pos_y = game->parse->player_y + 0.5;
	init_keys(game);
}

void	game_loop_init(t_game game, t_calc *n)
{
	n->camera_x = 2 * n->x / (double)n->w - 1;
	n->ray_dir_x = game.numig.dir_x - game.numig.plane_x * n->camera_x;
	n->ray_dir_y = game.numig.dir_y - game.numig.plane_y * n->camera_x;
	n->map_x = game.numig.pos_x;
	n->map_y = game.numig.pos_y;
	n->side_dist_x = 0.0;
	n->side_dist_y = 0.0;
	n->delta_dist_x = delta_dist_init(0, n->ray_dir_x);
	n->delta_dist_y = delta_dist_init(0, n->ray_dir_y);
	n->step_x = 0.0;
	n->step_y = 0.0;
	n->hit = 0;
	n->side = 0;
	n->wall_x = 0.0;
	n->step = 0.0;
}
