// ------------------------------------------------------------------------------------------------------------------------------
   		//texturing calculations
    	int texNum = map_ig[map_x][map_y] - 1; //1 subtracted from it so that texture 0 can be used!

    	//calculate value of wall_x
    	double wall_x; //where exactly the wall was hit
    	if (side == 0) wall_x = game->numig.pos_y + perp_wall_dist * ray_dir_y;
    	else           wall_x = game->numig.pos_x + perp_wall_dist * ray_dir_x;
    	wall_x -= floor((wall_x));

      //x coordinate on the texture
    	game->texig.tex_x = (int)(wall_x * (double)(game->texig.texture_width));
    	if(side == 0 && ray_dir_x > 0) game->texig.tex_x = game->texig.texture_width - game->texig.tex_x - 1;
    	if(side == 1 && ray_dir_y < 0) game->texig.tex_x = game->texig.texture_width - game->texig.tex_x - 1;

    // How much to increase the texture coordinate per screen pixel
    	double step = 1.0 * game->texig.texture_height / line_height;
    // Starting texture coordinate
		double texPos = (draw_start - h / 2 + line_height / 2) * step;
    	for(int y = draw_start; y < draw_end; y++)
    	{
		// Cast the texture coordinate to integer, and mask with (game->texig.texture_height - 1) in case of overflow
    		game->texig.tex_y = (int)texPos & (game->texig.texture_height - 1);
        	texPos += step;
        	int color = game->texig.texture[texNum][game->texig.texture_height * game->texig.tex_y + game->texig.tex_x];
        //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
        	if(side == 1)
			{
				color = (color >> 1) & 8355711;
        		game->texig.buffer[y][x] = color;
				//exit(0);
				//printf("valeur de buffer[x][y] :%d\n", game->texig.buffer[x][y]);
			}
		}
		draw(game->imgig, game);
		//exit(0);
		//for(int y = 0; y < h; y++) for(int x = 0; x < w; x++) buffer[y][x] = 0;
		
		// for(int y = 0; y < h; y++)
		// {
		// 	for(int x = 0; x < w; x++)
		// 	{
		// 		game->texig.buffer[y][x] = 0;
		// 	}
		// }
	}
	//siuu ?
}