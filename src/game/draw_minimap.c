/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:43:45 by bgales            #+#    #+#             */
/*   Updated: 2023/06/27 13:30:09 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_border(t_data img)
{
	int	x;

	x = -1;
	while (++x < 200)
	{
		if (x < 1)
			draw(img, x, (int [2]){0,
				200}, 0);
		else if (x < 190)
			draw(img, x, (int [2]){0,
				195}, 13158600);
		else
			draw(img, x, (int [2]){0,
				195}, 0);
	}
	x = -1;
	while (++x < 200)
		draw(img, x, (int [2]){190, 200}, 0);
}

void	draw_walls(t_data img, int x, int y)
{
	int	draw_x;
	int	draw_y;
	int	i;
	int	cubesize;

	cubesize = 10;
	draw_x = (x * 190) / 20;
	draw_y = (y * 190) / 20;
	i = draw_x;
	while (i++ < draw_x + cubesize && draw_x + cubesize < 200
		&& draw_y + cubesize < 200)
		draw(img, i, (int [2]){draw_y, draw_y + 10}, 16711680);
}

void	draw_player(t_game *game, t_data img)
{
	int	draw_x;
	int	draw_y;
	int	i;

	draw_x = (game->minimap.player_x - 1) * 10;
	draw_y = (game->minimap.player_y - 1) * 11;
	i = draw_x;
	while (i++ < draw_x + 5)
		draw(img, i, (int [2]){draw_y - 2, draw_y + 5}, 0);
}

void	draw_minimap(t_game *game, t_data img)
{
	int	y;
	int	x;

	x = -1;
	y = -1;
	draw_border(img);
	while (game->minimap.minimap[++y])
	{
		while (game->minimap.minimap[y][++x])
			if (game->minimap.minimap[y][x] == '1')
				draw_walls(img, x, y);
		x = -1;
	}
	free_char_array(game->minimap.minimap);
	draw_player(game, img);
}
