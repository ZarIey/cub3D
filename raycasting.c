/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:16:58 by ctardy            #+#    #+#             */
/*   Updated: 2023/03/14 15:37:24 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

#define screen_width 1024
#define screen_height 720

int map_ig[24][24] =
{
  {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
  {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
  {4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
  {4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
  {4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
  {4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
  {6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
  {6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
  {4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
};

void game_loop(t_game *game, t_data img, double pos_x, double pos_y, double dir_x, double dir_y, double plane_x, double plane_y)
{

	printf("LA BOUCLE \n");
	(void)plane_x;
	(void)game;
	(void)img;
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
// ------------------------------------------------------------------------------------------------------------------------------
   		//texturing calculations
    	int texNum = map_ig[map_x][map_y] - 1; //1 subtracted from it so that texture 0 can be used!

    	//calculate value of wall_x
    	double wall_x; //where exactly the wall was hit
    	if (side == 0)
			wall_x = game->numig.pos_y + perp_wall_dist * ray_dir_y;
    	else
			wall_x = game->numig.pos_x + perp_wall_dist * ray_dir_x;
    	wall_x -= floor((wall_x));

      //x coordinate on the texture
    	game->texig.tex_x = (int)(wall_x * (double)(game->texig.texture_width));
    	if(side == 0 && ray_dir_x > 0)
			game->texig.tex_x = game->texig.texture_width - game->texig.tex_x - 1;
    	if(side == 1 && ray_dir_y < 0)
			game->texig.tex_x = game->texig.texture_width - game->texig.tex_x - 1;

    // How much to increase the texture coordinate per screen pixel
    	double step = 1.0 * game->texig.texture_height / line_height;
    // Starting texture coordinate
		double texPos = (draw_start - h / 2 + line_height / 2) * step;
    	int color;
		int y = draw_start;
		for(; y < draw_end; y++)
    	{
		// Cast the texture coordinate to integer, and mask with (game->texig.texture_height - 1) in case of overflow
    		game->texig.tex_y = (int)texPos & (game->texig.texture_height - 1);
        	texPos += step;
        	color = game->texig.texture[texNum][game->texig.texture_height * game->texig.tex_y + game->texig.tex_x];
        //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			//printf("--- valeur de color : %d\n", color);
        	if (side == 1)
			{
				color = (color >> 1) & 8355711;
        	//	game->texig.buffer[y][x] = color;
				//exit(0);
			}
		}
		draw(game, game->imgig, x, draw_start, draw_end, color);
		// while (game->texig.buffer[y][x])
		// {
		// 	while (game->texig.buffer[y] < game->window_height)
		// 		my_mlx_pixel_put(&img, x, draw_start++, game->texig.buffer[y][x]);
		// }

		//exit(0);
	}
			//for(int y = 0; y < h; y++) for(int x = 0; x < w; x++) buffer[y][x] = 0;
		
		// for(int y = 0; y < h; y++)
		// {
		// 	for(int x = 0; x < w; x++)
		// 	{
		// 		game->texig.buffer[y][x] = 0;
		// 	}
		// }
		//exit(0);
	//siuu ?
}

int main (int argc, char **argv)
{

	(void)argc;
	(void)argv;
	t_game	game;
	ft_memset(&game, 0, sizeof(t_game));

	game.numig.pos_x = 18, game.numig.pos_y = 18;  //x and y start position
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

	game.texig.texture_width = 64;
	game.texig.texture_height = 64;

	game.window_height = 720;
	game.window_width = 1024;
	malloc_texture(&game);
	//exit(0);
	//game.texig.buffer[0][2] = 21;
  for(int x = 0; x < game.texig.texture_width; x++) {
  for(int y = 0; y < game.texig.texture_height; y++)
  {
	//printf("game.texig.texture_width : %d\n", game.texig.texture_width);
    int xorcolor = (x * 256 / game.texig.texture_width) ^ (y * 256 / game.texig.texture_height);
    //int xcolor = x * 256 / game.texig.texture_width;
    int ycolor = y * 256 / game.texig.texture_height;
    int xycolor = y * 128 / game.texig.texture_height + x * 128 / game.texig.texture_width;
    game.texig.texture[0][game.texig.texture_width * y + x] = 65536 * 254 * (x != y && x != game.texig.texture_width - y); //flat red texture with black cross
	game.texig.texture[1][game.texig.texture_width * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
    game.texig.texture[2][game.texig.texture_width * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
    game.texig.texture[3][game.texig.texture_width * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
    game.texig.texture[4][game.texig.texture_width * y + x] = 256 * xorcolor; //xor green
    game.texig.texture[5][game.texig.texture_width * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
    game.texig.texture[6][game.texig.texture_width * y + x] = 65536 * ycolor; //red gradient
    game.texig.texture[7][game.texig.texture_width * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
  }
  }
	game_loop(&game, game.imgig, game.numig.pos_x, game.numig.pos_y, game.numig.dir_x, game.numig.dir_y, game.numig.plane_x, game.numig.plane_y);
	//printf("valeur de buffer[x][y] :%d\n", game.texig.buffer[0][2]);
	mlx_put_image_to_window(game.mlx, game.window, game.imgig.img, 0, 0); // redraw();
	//exit(0);
	mlx_hook(game.window, 17, (1L << 17), exit_game, &game);
 	mlx_hook(game.window, 2, (1L << 0), key_press_hook, &game); //readKeys();
	free_texture(&game);
	// system ("leaks cub3d");
	mlx_loop(game.mlx);
}



