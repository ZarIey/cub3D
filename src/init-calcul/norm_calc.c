/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:37:44 by bgales            #+#    #+#             */
/*   Updated: 2023/06/27 18:26:52 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	last_calc_norm(t_game *game, t_calc *n, t_data img, double step)
{
	double	tex_pos;

	tex_pos = 0;
		game->texig.tex_x = game->texig.texture_height - game->texig.tex_x - 1;
	if ((n->side == 0 && n->ray_dir_x > 0)
		|| (n->side == 1 && n->ray_dir_y < 0))
		game->texig.tex_x = game->texig.texture_width - game->texig.tex_x - 1;
	if (n->se_draw[0] < 0)
	{
		tex_pos += step * -n->se_draw[0];
		n->se_draw[0] = 0;
	}
	if (n->se_draw[1] >= game->window_height)
		n->se_draw[1] = game->window_height - 1;
	while (n->se_draw[0] < n->se_draw[1])
	{
		game->texig.tex_y = (int)tex_pos & (game->texig.texture_height - 1);
		tex_pos += step;
		n->color = test_texture(game, n);
		my_mlx_pixel_put(&img, n->x, n->se_draw[0], n->color);
		n->se_draw[0]++;
	}
}
