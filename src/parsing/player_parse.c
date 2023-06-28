/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:09:56 by bgales            #+#    #+#             */
/*   Updated: 2023/06/12 20:37:06 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	p_parse_norm(char **map, t_parse **parse)
{
	int	i;

	i = -1;
	while (map[++i])
		if (in_set("NEWS", map[i][0]) || in_set("NEWS",
			map[i][ft_strlen(map[i])]))
			print_free_exit("Error\nPlayer's on the edge of the map.\n", parse);
	return ;
}

void	player_parser(char **map, t_parse **parse)
{
	int	i;
	int	j;
	int	player_count;

	i = -1;
	j = -1;
	player_count = 0;
	p_parse_norm(map, parse);
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (in_set("NEWS", map[i][j]) && player_count++ != -1)
			{
				is_surrounded(map, i, j, parse);
				(*parse)->player_x = j;
				(*parse)->player_y = i;
			}
		}
		j = 0;
	}
	if (player_count != 1)
		print_free_exit("Error\nOne player is expected.\n", parse);
}
