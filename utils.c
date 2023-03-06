/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:43:34 by ctardy            #+#    #+#             */
/*   Updated: 2023/03/06 21:26:01 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

double v_abs(double value)
{
	if (value >= 0)
		return (value);
	else
		return (value *= -1);
}

double delta_dist_init(double d, double r)
{
	if (!r)
		d = INFINITY;
	else if (r)
		d = v_abs(1 / r);
	return (d);
}

int	color_select(int tale)
{
	int new_color;
	if (tale == 1)
		return new_color = create_trgb(0, 255, 0, 0); //red
	if (tale == 2)
		return new_color = create_trgb(0, 0, 255, 0); //green
	if (tale == 3)
		return new_color = create_trgb(0, 0, 0, 255); //blue
	if (tale == 4)
		return new_color = create_trgb(0, 0, 0, 255); //white
    return new_color = create_trgb(0, 255, 255, 0); //yellow
}

 double    time_calculator(void)
 {
	struct timeval  start;
	gettimeofday(&start, NULL);
	return ((start.tv_sec * 1000) + (start.tv_usec / 1000));
}

int malloc_texture(t_game *game)
{
	int i = 0;
	//game->texig.buffer = malloc(720 * 1024 * sizeof(int)); // y-coordinate first because it works per scanline
	game->texig.buffer = malloc(sizeof(int *) * game->window_height);
	// exit(0);
//	printf("%d\n", game->window_height);
	while (i < game->window_height)
	{
		game->texig.buffer[i] = malloc(sizeof(game->window_width));
//		printf("%d\n", i);
		i++;	
	}
	//printf("valeur de buffer[x][y] :%d\n", game->texig.buffer[0][0]);
	for (int i = 0; i < 8; i++) {
		game->texig.texture[i] = malloc(sizeof(64 * 64));
	}
	return 0;
}

int free_texture(t_game *game)
{
	int i;
	for (i = 0; i < 8; i++)
	{
  		free(game->texig.texture[i]);
	}
	return (0);
}


int exit_game(void)
{
	exit(0);
}