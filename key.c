/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:34:10 by ctardy            #+#    #+#             */
/*   Updated: 2023/03/06 21:32:02 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int map_ig2[24][24] =
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
		
	game->numig.move_speed = 0.12;
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
		printf("Pressed W\n");
     	if(map_ig2[(int)(game->numig.pos_x + game->numig.dir_x * game->numig.move_speed)][(int)game->numig.pos_y] == 0)
			game->numig.pos_x += game->numig.dir_x * game->numig.move_speed;
      	if(map_ig2[(int)game->numig.pos_x][(int)(game->numig.pos_y + game->numig.dir_y * game->numig.move_speed)] == 0)
			game->numig.pos_y += game->numig.dir_y * game->numig.move_speed;
   	}

	// noalexan

    //move backwards if no wall behind you
    if (keycode == 1)
    {
		printf("Pressed S\n");
      	if(map_ig2[(int)(game->numig.pos_x - game->numig.dir_x * game->numig.move_speed)][(int)game->numig.pos_y] == 0)
			game->numig.pos_x -= game->numig.dir_x * game->numig.move_speed;
      	if(map_ig2[(int)game->numig.pos_x][(int)(game->numig.pos_y - game->numig.dir_y * game->numig.move_speed)] == 0)
			game->numig.pos_y -= game->numig.dir_y * game->numig.move_speed;
	}

	if (keycode == 2)
    {
		printf("Pressed D\n");
		//exit(0);
     	if(map_ig2[(int)(game->numig.pos_x + game->numig.plane_x * game->numig.move_speed)][(int)game->numig.pos_y] == 0)
			game->numig.pos_x += game->numig.plane_x * game->numig.move_speed;
      	if(map_ig2[(int)game->numig.pos_x][(int)(game->numig.pos_y + game->numig.plane_y * game->numig.move_speed)] == 0)
			game->numig.pos_y += game->numig.plane_y * game->numig.move_speed;
   	}

	if (keycode == 0)
    {
		printf("Pressed A\n");
		//exit(0);
     	if(map_ig2[(int)(game->numig.pos_x -0.3 + game->numig.plane_x * game->numig.move_speed)][(int)game->numig.pos_y] == 0)
			game->numig.pos_x -= game->numig.plane_x * game->numig.move_speed;
      	if(map_ig2[(int)game->numig.pos_x][(int)(game->numig.pos_y -0.3 + game->numig.plane_y * game->numig.move_speed)] == 0)
			game->numig.pos_y -= game->numig.plane_y * game->numig.move_speed;
   	}

    //rotate to the right
    if (keycode == 124)
    {
		printf("Pressed cam droite\n");
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
		printf("Pressed cam gauche\n");
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
	game_loop(game, game->imgig, game->numig.pos_x, game->numig.pos_y, game->numig.dir_x, game->numig.dir_y, game->numig.plane_x, game->numig.plane_y);
	mlx_put_image_to_window(game->mlx, game->window, game->imgig.img, 0, 0); // redraw();
		//for(int y = 0; y < h; y++) for(int x = 0; x < w; x++) buffer[y][x] = 0;
		
		// for(int y = 0; y < h; y++)
		// {
		// 	for(int x = 0; x < w; x++)
		// 	{
		// 		game->texig.buffer[y][x] = 0;
		// 	}
		// }
	return 0;
}