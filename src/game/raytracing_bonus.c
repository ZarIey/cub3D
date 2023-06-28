/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   raytracing_bonus.c	 :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: bgales <bgales@student.42.fr>	  +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2023/06/12 19:04:25 by bgales	#+#	#+#	 */
/*   Updated: 2023/06/27 13:18:09 by bgales	   ###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <sys/time.h>

int	color_select(int tale)
{
	int	color;

	(void)tale;
	color = create_trgb(0, 0, 0, 255);
	return (color);
}

double	time_calculator(void)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	return ((start.tv_sec * 1000) + (start.tv_usec / 1000));
}

void	draw_background(t_game *game, t_data img)
{
	int	floor_rgb;
	int	ceiling_rgb;
	int	f_draw;
	int	c_draw;

	c_draw = -1;
	f_draw = -1;
	floor_rgb = create_trgb(0, game->parse->f_rgb[0],
			(*game).parse->f_rgb[1], game->parse->f_rgb[2]);
			ceiling_rgb = create_trgb(0, game->parse->c_rgb[0],
			(*game).parse->c_rgb[1], game->parse->c_rgb[2]);
	while (++f_draw < game->window_width)
	{
		draw(img, f_draw, (int [2]){game->window_height / 2,
			game->window_height - 1}, floor_rgb);
		draw(img, ++c_draw, (int [2]){-1, game->window_height / 2},
			ceiling_rgb);
	}
}

void	game_loop(t_game game, t_data img)
{
	t_calc	n;

	n.x = -1;
	n.w = game.window_width;
	n.h = game.window_height;
	n.se_draw = malloc(sizeof(int) * 2);
	draw_background(&game, img);
	while (++n.x < n.w)
	{
		game_loop_init(game, &n);
		ray_dir_calc(game, &n);
		hit_wall(game, &n);
		last_calcul(&game, &n, img);
	}
	free(n.se_draw);
	minimap(&game, img);
}
