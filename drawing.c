/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:36:26 by ctardy            #+#    #+#             */
/*   Updated: 2023/03/02 13:25:32 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw(t_data img, int x, int draw_start, int draw_end, int color)
{
//	printf("Value de start %d et end %d de color %d\n", draw_start, draw_end, color);
	while (draw_start < draw_end)
	{
		my_mlx_pixel_put(&img, x, draw_start++, color);
	}
}



