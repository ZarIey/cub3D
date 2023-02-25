/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:16:58 by ctardy            #+#    #+#             */
/*   Updated: 2023/02/25 19:58:46 by ctardy           ###   ########.fr       */
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
		return new_color = create_trgb(255, 255, 255, 255); //white
    return new_color = create_trgb(0, 255, 255, 0); //yellow
}

 long    time_calculator(void)
 {
	struct timeval  start;
	gettimeofday(&start, NULL);
	return ((start.tv_sec * 1000) + (start.tv_usec / 1000));
}

void game_loop(t_game game, t_data img, double pos_x, double pos_y, double dir_x, double dir_y, double plane_x, double plane_y)
{
	(void)plane_x;
	(void)game;
	int w = 1024;
	int h = 720;
//	double ww = (double)w;
	// while (1)
	// {
   		for(int x = 0; x < w; x++)
    	{
			//calculate ray position and direction
			double camera_x = 2 * x / (double)w - 1; //x-coordinate in camera space
			double ray_dir_x = dir_x + plane_y * camera_x;
			double ray_dir_y = dir_y + plane_y * camera_x;
		//	printf("%f %f %f %f %f %f\n ", camera_x, ray_dir_x, ray_dir_y, pos_x, pos_y, plane_x);
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
    		// ColorRGB color;
			// switch(map_ig[map_x][map_y])
    		// {
			// 	case 1:  color = RGB_Red;  break; //red
        	// 	case 2:  color = RGB_Green;  break; //green
        	// 	case 3:  color = RGB_Blue;   break; //blue
        	// 	case 4:  color = RGB_White;  break; //white
        	// 	default: color = RGB_Yellow; break; //yellow
      		// }
			int color;
			color = color_select(map_ig[map_x][map_y]);

      //give x and y sides different brightness
		    if (side == 1) 
				color = color / 2;

    		 //draw the pixels of the stripe as a vertical line
	  		draw(img, x, draw_start, draw_end, color);
	  		//verLine(x, draw_start, draw_end, color);
			// (void) plane_x;
			// (void) plane_y;
			// (void) time;
			// (void) old_time;
    	 }

}

int key_press_hook(int keycode, void *params)
{
	t_num *num = (t_num *)params;
	//(void)num;
	double time = num->time;
	double old_time = num->old_time;
	double plane_x = num->plane_x;
	double plane_y = num->plane_y;
	double pos_x = num->pos_x;
	double pos_y = num->pos_y;
	double dir_x = num->dir_x;
	double dir_y = num->dir_y;

    double frame_time = (time - old_time) / 1000.0; //frame_time is the time this frame has taken, in seconds
    //speed modifiers
    	double move_speed = frame_time * 5.0; //the constant value is in squares/second
    	double rot_speed = frame_time * 3.0; //the constant value is in radians/second
		
    if (keycode == 13)
    {
     	if(map_ig[(int)(pos_x + dir_x * move_speed)][(int)pos_y] == 0) pos_x += dir_x * move_speed;
      	if(map_ig[(int)pos_x][(int)(pos_y + dir_y * move_speed)] == 0) pos_y += dir_y * move_speed;
   	}
    //move backwards if no wall behind you
    if (keycode == 1)
    {
      	if(map_ig[(int)(pos_x - dir_x * move_speed)][(int)pos_y] == 0)
			pos_x -= dir_x * move_speed;
      	if(map_ig[(int)pos_x][(int)(pos_y - dir_y * move_speed)] == 0)
			pos_y -= dir_y * move_speed;
	}

    //rotate to the right
    if (keycode == 2)
    {
      //both camera direction and camera plane must be rotated
      	double oldDir_x = dir_x;
      	dir_x = dir_x * cos(-rot_speed) - dir_y * sin(-rot_speed);
      	dir_y = oldDir_x * sin(-rot_speed) + dir_y * cos(-rot_speed);
      	double oldPlane_x = plane_x;
      	plane_x = plane_x * cos(-rot_speed) - plane_y * sin(-rot_speed);
      	plane_y = oldPlane_x * sin(-rot_speed) + plane_y * cos(-rot_speed);
   	}
    //rotate to the left
    if (keycode == 0)
    {
      //both camera direction and camera plane must be rotated
      	double oldDir_x = dir_x;
      	dir_x = dir_x * cos(rot_speed) - dir_y * sin(rot_speed);
      	dir_y = oldDir_x * sin(rot_speed) + dir_y * cos(rot_speed);
      	double oldPlane_x = plane_x;
      	plane_x = plane_x * cos(rot_speed) - plane_y * sin(rot_speed);
      	plane_y = oldPlane_x * sin(rot_speed) + plane_y * cos(rot_speed);
   	}
	return 0;
}

int main (int argc, char **argv)
{
	double pos_x = 22, pos_y = 12;  //x and y start position
	double dir_x = -1, dir_y = 0; //initial direction vector
	double plane_x = 0, plane_y = 0.66; //the 2d raycaster version of camera plane
	double time = 0; //time of current frame
	double old_time = 0; //time of previous frame
	(void)argc;
	(void)argv;
	t_game	game;
	t_data	img;
	t_num	num;
	//int count_lines;
	//char **map_ig;

	ft_memset(&game, 0, sizeof(t_game));
	//count_lines = map_reader(&game, argv, 0);
	game.mlx = mlx_init();

	//game.window_height = count_lines;
	game.window_height = 24;
	game.window_width = 24;
	game.window = mlx_new_window(game.mlx, 1024, 720, "cub3D");
	img.img = mlx_new_image(game.mlx, 1024, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	
	game_loop(game, img, pos_x, pos_y, dir_x, dir_y, plane_x, plane_y);
			
 	//    timing for input and FPS counter
	//print(1.0 / frame_time); //FPS counter
	mlx_put_image_to_window(game.mlx, game.window, img.img, 0, 0); // redraw();
  // 	mlx_clear_window(game.mlx, game.window); // cls();

	old_time = time;
    time = time_calculator();
	
	num.time = time;
	num.old_time = old_time;
	num.plane_x = plane_x;
	num.plane_y = plane_y;
	num.pos_x = pos_x;
	num.pos_y = pos_y;
	num.dir_x = dir_x;
	num.dir_y = dir_y;
	
	
 	mlx_hook(game.window, 2, 0, key_press_hook, &num); //readKeys();
	
	//move forward if no wall in front of you
	mlx_loop(game.mlx);
}



