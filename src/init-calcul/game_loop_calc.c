/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   game_loop_calc.c	   :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: bgales <bgales@student.42.fr>	  +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2023/06/12 18:45:51 by bgales	#+#	#+#	 */
/*   Updated: 2023/06/25 21:42:41 by bgales	   ###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include "cub3d.h"

double	v_abs(double value)
{
	if (value >= 0)
		return (value);
	else
		return (value *= -1);
}

double	delta_dist_init(double d, double r)
{
	if (!r)
		d = INFINITY;
	else if (r)
		d = v_abs(1 / r);
	return (d);
}

void	ray_dir_calc(t_game game, t_calc *n)
{
	if (n->ray_dir_x < 0)
	{
		n->step_x = -1;
		n->side_dist_x = (game.numig.pos_x - n->map_x)
			* n->delta_dist_x;
	}
	else
	{
		n->step_x = 1;
		n->side_dist_x = (n->map_x + 1.0
				- game.numig.pos_x) * n->delta_dist_x;
	}
	if (n->ray_dir_y < 0)
	{
		n->step_y = -1;
		n->side_dist_y = (game.numig.pos_y - n->map_y) * n->delta_dist_y;
	}
	else
	{
		n->step_y = 1;
		n->side_dist_y = (n->map_y + 1.0
				- game.numig.pos_y) * n->delta_dist_y;
	}
}

void	hit_wall(t_game game, t_calc *n)
{
	while (n->hit == 0)
	{
		if (n->side_dist_x < n->side_dist_y)
		{
			n->side_dist_x += n->delta_dist_x;
			n->map_x += n->step_x;
			n->side = 0;
		}
		else
		{
			n->side_dist_y += n->delta_dist_y;
			n->map_y += n->step_y;
			n->side = 1;
		}
		n->map_y += 0.5;
		n->map_x += 0.5;
		if (game.map_ig[n->map_y][n->map_x] > '0')
			n->hit = 1;
	}
}

void	last_calcul(t_game *game, t_calc *n, t_data img)
{
	double	step;

	if (n->side == 0)
		n->perp_wall_dist = (n->side_dist_x - n->delta_dist_x);
	else
		n->perp_wall_dist = (n->side_dist_y - (n->delta_dist_y));
	n->line_height = (int)(n->h / n->perp_wall_dist);
	n->se_draw[0] = -n->line_height / 2 + n->h / 2;
	n->se_draw[1] = n->line_height / 2 + n->h / 2;
	step = (double)(1.0 * (double)game->texig.texture_height
			/ (double)n->line_height);
	n->wall_x = game->numig.pos_x + (n->perp_wall_dist
			* n->ray_dir_x);
	if (n->side == 0)
		n->wall_x = game->numig.pos_y
			+ (n->perp_wall_dist * n->ray_dir_y);
	n->wall_x -= floor((n->wall_x));
	game->texig.tex_x = (int)(n->wall_x * (game->texig.texture_width) - 1);
	last_calc_norm(game, n, img, step);
}
