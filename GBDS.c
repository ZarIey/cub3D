int key_press_hook(int keycode, void *params)
{
	t_game *game = (t_game *)params;
	//(void)num;
    game->numig.frame_time = (game->numig.time - game->numig.old_time) / 1000.0; //frame_time is the time this frame has taken, in seconds
    //speed modifiers
    	game->numig.move_speed = game->numig.frame_time * 5.0; //the constant value is in squares/second
    	game->numig.rot_speed = game->numig.frame_time * 3.0; //the constant value is in radians/second
		
   	mlx_clear_window(game->mlx, game->window); // cls();
	printf("vec %f %f\n", game->numig.plane_x, game->numig.plane_y);
	printf("pos play %f %f\n", game->numig.pos_x, game->numig.pos_y);
    if (keycode == 13)
    {
		printf("Pressed W\n");
     	if(game->map_ig[(int)(game->numig.pos_x + game->numig.dir_x * game->numig.move_speed)][(int)game->numig.pos_y] == 0)
			game->numig.pos_x += game->numig.dir_x * game->numig.move_speed;
      	if(game->map_ig[(int)game->numig.pos_x][(int)(game->numig.pos_y + game->numig.dir_y * game->numig.move_speed)] == 0)
			game->numig.pos_y += game->numig.dir_y * game->numig.move_speed;
		printf ("Valeur de map %d\n", map_ig[(int)(game->numig.pos_x + game->numig.dir_x * game->numig.move_speed)][(int)game->numig.pos_y]);
   	}
    //move backwards if no wall behind you
    if (keycode == 1)
    {
		printf("Pressed S\n");
      	if(map_ig[(int)(game->numig.pos_x - game->numig.dir_x * game->numig.move_speed)][(int)game->numig.pos_y] == 0)
			game->numig.pos_x -= game->numig.dir_x * game->numig.move_speed;
      	if(map_ig[(int)game->numig.pos_x][(int)(game->numig.pos_y - game->numig.dir_y * game->numig.move_speed)] == 0)
			game->numig.pos_y -= game->numig.dir_y * game->numig.move_speed;
	}

    //rotate to the right
    if (keycode == 2)
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
    if (keycode == 0)
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
	//game_loop(*game, game->imgig, pos_x, pos_y, dir_x, dir_y, plane_x, plane_y);
	mlx_put_image_to_window(game->mlx, game->window, game->imgig.img, 0, 0); // redraw();
	return 0;
}