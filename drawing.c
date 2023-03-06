/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:36:26 by ctardy            #+#    #+#             */
/*   Updated: 2023/03/06 20:36:26 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


// void	write_color_in_buffer(t_play *p, int x, int h)
// {
// 	int			y;
// 	y = 0;
// 	while (y < p->drawstart)
// 		p->buffer[y++][x] = p->texture->ceil;
// 	while (y < p->drawend + 1)
// 	{
// 		p->texy = (int)p->texpos & (TEXHEIGHT - 1);
// 		p->texpos += p->step;
// 		if (p->side > 0 && p->stepy > 0)
// 			p->color = get_data_color(p->texx, p->texy, p->text[0]);
// 		if (p->side > 0 && p->stepy <= 0)
// 			p->color = get_data_color(p->texx, p->texy, p->text[1]);
// 		if (p->side == 0 && p->stepx > 0)
// 			p->color = get_data_color(p->texx, p->texy, p->text[2]);
// 		if (p->side == 0 && p->stepx <= 0)
// 			p->color = get_data_color(p->texx, p->texy, p->text[3]);
// 		p->buffer[y++][x] = p->color;
// 	}
// 	while (y < h)
// 		p->buffer[y++][x] = p->texture->floor;
// }


void draw(t_game *game, t_data img, int x, int draw_start, int draw_end, int color)
{
	(void)(game);
//	printf("Value de start %d et end %d de color %d\n", draw_start, draw_end, color);
	while (draw_start < draw_end)
	{
		my_mlx_pixel_put(&img, x, draw_start++, color);
	}
}

// void draw(t_data img, t_game *game)
// {
// //	printf("valeur de game->window_width %d et game->window_height %d\n", game->window_width, game->window_height);
// 	int x = 0;
// 	int y = 0;
// 	while (x < game->window_height)
// 	{
// 		while (y < game->window_width)
// 		{
// 			my_mlx_pixel_put(&img, y, x, game->texig.buffer[x][y]);
// 			y++;
// 			//printf("Valeur de x %d et y %d\n", x, y);
// 		}
// 		//exit(0);
// 		y = 0;
// 		x++;
// 	}
// }

