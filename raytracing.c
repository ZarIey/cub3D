/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:16:58 by ctardy            #+#    #+#             */
/*   Updated: 2023/02/20 17:20:11 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

#include <stdio.h>


int v_abs(int value)
{
	if (value >= 0)
		return (value);
	else
		return (value *= -1);
}

double delta_dist_init(double d, double r)
{
	if (!r)
		d = 1e30;
	else if (r)
		d = v_abs(1 / r);
	return (d);
}

int main (int argc, char **argv)
{
	(void)argc;
	t_game game;
	ft_memset(&game, 0, sizeof(t_game));

	int count_lines;
	count_lines = map_reader(&game, argv, 0);
	map_reader(&game, argv, count_lines);

	double player_x = 22, player_y = 12;  //x and y start position
	double dir_x = -1, dir_y = 0; //initial direction vector
	double plane_x = 0, plane_y = 0.66; //the 2d raycaster version of camera plane
	// double time = 0; //time of current frame
	// double old_time = 0; //time of previous frame

	
	game.mlx = mlx_init();

	game.window_height = count_lines;
	game.window_width = 24;
	game.window = mlx_new_window(game.mlx, (1080), (924), "cub3D");

	int w = game.window_width;
	double ww = (double)w;
	// while (1)
	// {
   		for(int x = 0; x < w; x++)
    	{
			//calculate ray position and direction
			double camera_x = 2 * x / ww - 1; //x-coordinate in camera space
			double ray_dir_x = dir_x + plane_y * camera_x;
			double ray_dir_y = dir_y + plane_y * camera_x;
			printf("%f %f %f %f %f %f\n ", camera_x, ray_dir_x, ray_dir_y, player_x, player_y, plane_x);
      //which box of the map we're in
   			int map_x = (int)player_x;
    		int map_y = (int)player_y;

      //length of ray from current position to next x or y-side
    		double side_dist_x;
    		double side_dist_y;

       //length of ray from one x or y-side to next x or y-side
		// TRY LATER WITH MATH.H INFINITY
			double delta_dist_x = delta_dist_init(0, ray_dir_x);
			double delta_dist_y = delta_dist_init(0, ray_dir_y);
		}

    double perp_wall_dist;

      //what direction to step in x or y-direction (either +1 or -1)
    int step_x;
    int step_y;

    int hit = 0; //was there a wall hit?
    int side; //was a NS or a EW wall hit?

	// system("leaks cub3D");
	// exit(0);
//	mlx_loop(game.mlx);

}
