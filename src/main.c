/* ************************************************************************** */
/*				            */
/*				        :::      ::::::::   */
/*   main.c				             :+:      :+:    :+:   */
/*				    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*				+#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:22:05 by bgales            #+#    #+#             */
/*   Updated: 2025/06/15 15:55:08 by bgales           ###   ########.fr       */
/*				            */
/* ************************************************************************** */

#include "cub3d.h"

t_parse	*parse(char *map_path, int argc)
{
	t_parse	*parse;
	char	**cub_file;

	cub_file = NULL;
	parse = malloc(sizeof(t_parse));
	if (argc != 2)
	{
		printf("Wrong argument format");
		exit (0);
	}
	parser(&parse, cub_file, map_path);
	return (parse);
}

void	init_img(t_game *game)
{
	game->imgig.img = mlx_new_image(game->mlx,
			game->window_width, game->window_height);
	game->imgig.addr = mlx_get_data_addr(game->imgig.img,
			&game->imgig.bits_per_pixel, &game->imgig.line_length,
			&game->imgig.endian);
}

void	init_game(t_game *game)
{
	game->parse->map[game->parse->player_y][game->parse->player_x] = '0';
	game->map_ig = game->parse->map;
	game->mlx = mlx_init();
	game->window_height = GAME_HEIGHT - 100;
	game->window_width = GAME_WIDTH;
	game->window = mlx_new_window(game->mlx, game->window_width,
			game->window_height, "cub3D");
}

void	init_all(t_game *game, int argc, char **argv)
{
	ft_memset(game, 0, sizeof(t_game));
	game->parse = parse(argv[1], argc);
	init_camera_dir(game);
	init_numig(game);
	init_game(game);
	init_img(game);
	texture_init(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_all (&game, argc, argv);
	game_loop(game, game.imgig);
	mlx_put_image_to_window(game.mlx, game.window, game.imgig.img, 0, 0);
	mlx_hook(game.window, 2, 0, lock_key, &game);
	mlx_hook(game.window, 3, 0, unlock_key, &game);
	mlx_hook(game.window, 17, (1L << 17), exit_game, &game);
	mlx_loop_hook(game.mlx, key_events, &game);
	mlx_loop(game.mlx);
}
