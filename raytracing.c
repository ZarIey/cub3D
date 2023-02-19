/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:16:58 by ctardy            #+#    #+#             */
/*   Updated: 2023/02/19 17:48:36 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int main ()
{
	t_game game;

	ft_memset(&game, 0, sizeof(t_game));
	
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, (game.window_width * 128), (game.window_height * 128), "cub3D");
	mlx_loop(game.mlx);
	//worldmap(24, 24);

	// double player_x = 22, player_y = 12;  //x and y start position
	// double dir_x = -1, dir_y = 0; //initial direction vector
	// double plane_x = 0, plane_y = 0.66; //the 2d raycaster version of camera plane

	// double time = 0; //time of current frame
	// double old_time = 0; //time of previous frame

}
