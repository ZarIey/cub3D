/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:04:22 by bgales            #+#    #+#             */
/*   Updated: 2023/06/27 18:26:36 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	lock_key(int key, t_game *game)
{
	if (key == 13 || key == 126)
		game->keys.up = 1;
	else if (key == 1 || key == 125)
		game->keys.down = 1;
	else if (key == D_KEY)
		game->keys.d = 1;
	else if (key == A_KEY)
		game->keys.a = 1;
	else if (key == 123)
		game->keys.right = 1;
	else if (key == 124)
		game->keys.left = 1;
	return (0);
}

int	unlock_key(int key, t_game *game)
{
	if (key == 53)
		print_free_exit("Thanks for playing\n", &game->parse);
	if (key == 13 || key == 126)
		game->keys.up = 0;
	else if (key == 1 || key == 125)
		game->keys.down = 0;
	else if (key == A_KEY)
		game->keys.a = 0;
	else if (key == D_KEY)
		game->keys.d = 0;
	else if (key == 124)
		game->keys.left = 0;
	else if (key == 123)
		game->keys.right = 0;
	return (0);
}

int	key_events(t_game *game)
{
	if (game->keys.up || game->keys.down || game->keys.a
		|| game->keys.d || game->keys.left || game->keys.right)
	{
		if (game->keys.up)
			up_down(game, 'U');
		else if (game->keys.down)
			up_down(game, 'D');
		if (game->keys.a)
			right_left(game, 'R');
		else if (game->keys.d)
			right_left(game, 'L');
		if (game->keys.right)
			rotate_right(game);
		else if (game->keys.left)
			rotate_left(game);
		key_press_hook(game);
	}
	return (0);
}
