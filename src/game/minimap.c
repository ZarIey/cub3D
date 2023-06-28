/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:54:06 by bgales            #+#    #+#             */
/*   Updated: 2023/06/20 11:45:41 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	minimap_posxy(t_game *game, int y, int x)
{
	if (x >= 0)
		game->minimap.player_x = 10;
	if (y >= 0)
		game->minimap.player_y = 10;
	if (x < 0)
		game->minimap.player_x = x + 10;
	if (y < 0)
		game->minimap.player_y = y + 10;
}

void	minimap(t_game *game, t_data img)
{
	int	y;
	int	x;
	int	i;

	y = game->numig.pos_y - 10;
	x = game->numig.pos_x - 10;
	minimap_posxy(game, y, x);
	i = 0;
	if (game->minimap.minimap_h > game->parse->map_height)
		game->minimap.minimap_h = game->parse->map_height;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	game->minimap.minimap_h = y + 20;
	game->minimap.minimap = malloc(sizeof(char *)
			* (game->minimap.minimap_h + 1));
	while (y < game->minimap.minimap_h && game->map_ig[y])
		game->minimap.minimap[i++] = ft_substr
			(game->map_ig[y++], x, game->numig.pos_x + 20);
	game->minimap.minimap[i] = NULL;
	draw_minimap(game, img);
}
