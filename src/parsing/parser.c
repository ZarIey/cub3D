/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:20:59 by bgales            #+#    #+#             */
/*   Updated: 2023/06/23 20:03:58 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parser(t_parse **parse, char **cub_file, char *map_path)
{
	null_all(parse);
	cub_file = get_file(map_path, parse);
	(*parse)->map = get_map(cub_file);
	get_xy(parse);
	(*parse)->ressources = get_ressources(cub_file, parse);
	free_char_array(cub_file);
	ressource_parse(parse);
	map_parser((*parse)->map, parse);
	player_parser((*parse)->map, parse);
}
