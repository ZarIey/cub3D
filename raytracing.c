/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:16:58 by ctardy            #+#    #+#             */
/*   Updated: 2023/02/28 17:01:56 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

#include <stdio.h>
#include <sys/time.h>

int map_ig[24][24] =
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

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

void game_loop(t_game game, t_data img, double pos_x, double pos_y, double dir_x, double dir_y, double plane_x, double plane_y)
{

	printf("LA BOUCLE \n");
	(void)plane_x;
	(void)game;
	int w = 1024;
	int h = 720;

	// while (1)
	// {
   		for(int x = 0; x < w; x++)
    	{
			//calculate ray position and direction
			double camera_x = 2 * x / (double)w - 1; //x-coordinate in camera space
			double ray_dir_x = dir_x + plane_x * camera_x;
			double ray_dir_y = dir_y + plane_y * camera_x;
      //which box of the map we're in
   			int map_x = (int)pos_x;
    		int map_y = (int)pos_y;

      //length of ray from current position to next x or y-side
    		double side_dist_x;
    		double side_dist_y;

       //length of ray from one x or y-side to next x or y-side
		// TRY LATER WITH MATH.H INFINITY
			double delta_dist_x = delta_dist_init(0, ray_dir_x);
			double delta_dist_y = delta_dist_init(0, ray_dir_y);
			double perp_wall_dist;

      //what direction to step in x or y-direction (either +1 or -1)
		    int step_x;
    		int step_y;

		    int hit = 0; //was there a wall hit?
    		int side; //was a NS or a EW wall hit?

      //calculate step and initial sideDist
		    if (ray_dir_x < 0)
			{
				step_x = -1;
				side_dist_x = (pos_x - map_x) * delta_dist_x;
			}
			else
			{
				step_x = 1;
				side_dist_x = (map_x + 1.0 - pos_x) * delta_dist_x;
			}
			if (ray_dir_y < 0)
			{
				step_y = -1;
				side_dist_y = (pos_y - map_y) * delta_dist_y;
      		}
			else
			{
				step_y = 1;
				side_dist_y = (map_y + 1.0 - pos_y) * delta_dist_y;
			}

			//perform DDA
			while (hit == 0)
      		{
        	//jump to next map square, either in x-direction, or in y-direction
        		if (side_dist_x < side_dist_y)
        		{
          			side_dist_x += delta_dist_x;
          			map_x += step_x;
          			side = 0;
       			}
        		else
        		{
          			side_dist_y += delta_dist_y;
          			map_y += step_y;
          			side = 1;
        		}

        //Check if ray has hit a wall
        		if (map_ig[map_x][map_y] > 0)
					hit = 1;
      		}
			
      //Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
      		if (side == 0)
				perp_wall_dist = (side_dist_x - delta_dist_x);
      		else
				perp_wall_dist = (side_dist_y - delta_dist_y);
			
      //Calculate height of line to draw on screen
    		int line_height = (int)(h / perp_wall_dist);

      //calculate lowest and highest pixel to fill in current stripe
    		int draw_start = -line_height / 2 + h / 2;
    		if (draw_start < 0)
				draw_start = 0;
      		int draw_end = line_height / 2 + h / 2;
    		if (draw_end >= h)
				draw_end = h - 1;
			
     	 //choose wall color
			int color;
			color = color_select(map_ig[map_x][map_y]);

      //give x and y sides different brightness
		    if (side == 1) 
				color = color / 2;

    		 //draw the pixels of the stripe as a vertical line
	  		draw(img, x, draw_start, draw_end, color);
	  		//verLine(x, draw_start, draw_end, color);
    	 }

}

int exit_game(void)
{
	exit(0);
}

int key_press_hook(int keycode, void *params)
{
	t_game *game = (t_game *)params;
	// game->nmig.start = time_calculator();
	
	game->numig.old_time = game->numig.time;
	game->numig.time = time_calculator() - game->numig.start;
	//printf("VALEUR DE START %f\n", game->numig.start);
    game->numig.frame_time = (game->numig.time - game->numig.old_time) / 1000.0; //frame_time is the time this frame has taken, in seconds

	printf("FPS %f\n", game->numig.frame_time);
	printf("---- time %f\n", game->numig.time);
	printf("old_time %f\n", game->numig.old_time);
   
    //speed modifiers
    // game->numig.move_speed = game->numig.frame_time * 5.0; //the constant value is in squares/second
	// printf("---- game->numig.move_speed : %f\n",game->numig.move_speed);
    // game->numig.rot_speed = game->numig.frame_time * 3.0; //the constant value is in radians/second
		
	game->numig.move_speed = 0.17;
	game->numig.rot_speed = 0.10;

		
	// printf("vec %f %f\n", game->numig.plane_x, game->numig.plane_y);
	// printf("pos play %f %f\n", game->numig.pos_x, game->numig.pos_y);
	// printf ("pos_x %f\n", game->numig.pos_x);
	// printf ("dir_x %f\n", game->numig.dir_x);
	// printf ("MS %f\n", game->numig.move_speed);
	// printf ("pos_y %f\n", game->numig.pos_y);

	if (keycode == 53)
		exit_game();
    if (keycode == 13)
    {
		//exit(0);
     	if(map_ig[(int)(game->numig.pos_x + game->numig.dir_x * game->numig.move_speed)][(int)game->numig.pos_y] == 0)
			game->numig.pos_x += game->numig.dir_x * game->numig.move_speed;
      	if(map_ig[(int)game->numig.pos_x][(int)(game->numig.pos_y + game->numig.dir_y * game->numig.move_speed)] == 0)
			game->numig.pos_y += game->numig.dir_y * game->numig.move_speed;
   	}

	// noalexan

    //move backwards if no wall behind you
    if (keycode == 1)
    {
		printf("Pressed S\n");
      	if(map_ig[(int)(game->numig.pos_x - game->numig.dir_x * game->numig.move_speed)][(int)game->numig.pos_y] == 0)
			game->numig.pos_x -= game->numig.dir_x * game->numig.move_speed;
      	if(map_ig[(int)game->numig.pos_x][(int)(game->numig.pos_y - game->numig.dir_y * game->numig.move_speed)] == 0)
			game->numig.pos_y -= game->numig.dir_y * game->numig.move_speed;
	}

	if (keycode == 2)
    {
		//exit(0);
     	if(map_ig[(int)(game->numig.pos_x + game->numig.plane_x * game->numig.move_speed)][(int)game->numig.pos_y] == 0)
			game->numig.pos_x += game->numig.plane_x * game->numig.move_speed;
      	if(map_ig[(int)game->numig.pos_x][(int)(game->numig.pos_y + game->numig.plane_y * game->numig.move_speed)] == 0)
			game->numig.pos_y += game->numig.plane_y * game->numig.move_speed;
   	}

	if (keycode == 0)
    {
		//exit(0);
     	if(map_ig[(int)(game->numig.pos_x + game->numig.plane_x * game->numig.move_speed)][(int)game->numig.pos_y] == 0)
			game->numig.pos_x -= game->numig.plane_x * game->numig.move_speed;
      	if(map_ig[(int)game->numig.pos_x][(int)(game->numig.pos_y + game->numig.plane_y * game->numig.move_speed)] == 0)
			game->numig.pos_y -= game->numig.plane_y * game->numig.move_speed;
   	}

    //rotate to the right
    if (keycode == 124)
    {
		printf("Pressed A\n");
      //both camera direction and camera plane must be rotated
      	double oldDir_x = game->numig.dir_x;
      	game->numig.dir_x = game->numig.dir_x * cos(-game->numig.rot_speed) - game->numig.dir_y * sin(-game->numig.rot_speed);
      	game->numig.dir_y = oldDir_x * sin(-game->numig.rot_speed) + game->numig.dir_y * cos(-game->numig.rot_speed);
      	double oldPlane_x = game->numig.plane_x;
      	game->numig.plane_x = game->numig.plane_x * cos(-game->numig.rot_speed) - game->numig.plane_y * sin(-game->numig.rot_speed);
      	game->numig.plane_y = oldPlane_x * sin(-game->numig.rot_speed) + game->numig.plane_y * cos(-game->numig.rot_speed);
		
   	}
    //rotate to the left
    if (keycode == 123)
    {
		printf("Pressed D\n");
      //both camera direction and camera plane must be rotated
      	double oldDir_x = game->numig.dir_x;
      	game->numig.dir_x = game->numig.dir_x * cos(game->numig.rot_speed) - game->numig.dir_y * sin(game->numig.rot_speed);
      	game->numig.dir_y = oldDir_x * sin(game->numig.rot_speed) + game->numig.dir_y * cos(game->numig.rot_speed);
      	double oldPlane_x = game->numig.plane_x;
      	game->numig.plane_x = game->numig.plane_x * cos(game->numig.rot_speed) - game->numig.plane_y * sin(game->numig.rot_speed);
      	game->numig.plane_y = oldPlane_x * sin(game->numig.rot_speed) + game->numig.plane_y * cos(game->numig.rot_speed);
   	}
  	mlx_clear_window(game->mlx, game->window); // cls();
	game->imgig.img = mlx_new_image(game->mlx, 1024, 720);
	game->imgig.addr = mlx_get_data_addr(game->imgig.img, &game->imgig.bits_per_pixel, &game->imgig.line_length, &game->imgig.endian);
	game_loop(*game, game->imgig, game->numig.pos_x, game->numig.pos_y, game->numig.dir_x, game->numig.dir_y, game->numig.plane_x, game->numig.plane_y);
	mlx_put_image_to_window(game->mlx, game->window, game->imgig.img, 0, 0); // redraw();
	return 0;
}

int main (int argc, char **argv)
{

	(void)argc;
	(void)argv;
	t_game	game;
	ft_memset(&game, 0, sizeof(t_game));

	game.numig.pos_x = 14, game.numig.pos_y = 14;  //x and y start position
	game.numig.dir_x = -1, game.numig.dir_y = 0; //initial direction vector
	game.numig.plane_x = 0, game.numig.plane_y = 0.66; //the 2d raycaster version of camera plane
	game.numig.time = 0; //time of current frame
	game.numig.start = time_calculator(); //time of current frame
	game.numig.old_time = 0; //time of previous frame
	game.numig.old_time = game.numig.time;
    game.numig.time = time_calculator() - game.numig.start;
	
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, 1024, 720, "cub3D");
	game.imgig.img = mlx_new_image(game.mlx, 1024, 720);
	game.imgig.addr = mlx_get_data_addr(game.imgig.img, &game.imgig.bits_per_pixel, &game.imgig.line_length, &game.imgig.endian);

	game_loop(game, game.imgig, game.numig.pos_x, game.numig.pos_y, game.numig.dir_x, game.numig.dir_y, game.numig.plane_x, game.numig.plane_y);

	mlx_put_image_to_window(game.mlx, game.window, game.imgig.img, 0, 0); // redraw();
	mlx_hook(game.window, 17, (1L << 17), exit_game, &game);
 	mlx_hook(game.window, 2, (1L << 0), key_press_hook, &game); //readKeys();
	mlx_loop(game.mlx);
}



