/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ressource_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:15:40 by bgales            #+#    #+#             */
/*   Updated: 2023/06/27 16:36:52 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	is_empty(t_parse **parse)
{
	if (!(*parse)->floor)
		print_free_exit("Error\nFloor ressource is empty.\n", parse);
	if (!(*parse)->ceiling)
		print_free_exit("Error\nCeiling ressource is empty.\n", parse);
	if (!(*parse)->north)
		print_free_exit("Error\nNorth texture is empty.\n", parse);
	if (!(*parse)->south)
		print_free_exit("Error\nSouth texture is empty.\n", parse);
	if (!(*parse)->east)
		print_free_exit("Error\nEast texture is empty.\n", parse);
	if (!(*parse)->west)
		print_free_exit("Error\nWest texture is empty.\n", parse);
}

void	get_rgb(t_parse **parse, int line)
{
	if (in_set("C", ((*parse)->ressources[line][0])) && !(*parse)->ceiling)
		(*parse)->ceiling = ft_strdup((*parse)->ressources[line]);
	if (in_set("F", ((*parse)->ressources[line][0])) && !(*parse)->floor)
		(*parse)->floor = ft_strdup((*parse)->ressources[line]);
}

void	get_texture(t_parse **parse, int line)
{
	if ((*parse)->ressources[line][0] == 'N' && in_set("O",
		((*parse)->ressources[line][1])) && !(*parse)->north)
		(*parse)->north = ft_substr((*parse)->ressources[line],
				0, ft_strlen((*parse)->ressources[line]));
	if ((*parse)->ressources[line][0] == 'S' && in_set("O",
		((*parse)->ressources[line][1])) && !(*parse)->south)
		(*parse)->south = ft_substr((*parse)->ressources[line],
				0, ft_strlen((*parse)->ressources[line]));
	if ((*parse)->ressources[line][0] == 'W' && in_set("E",
		((*parse)->ressources[line][1])) && !(*parse)->west)
		(*parse)->west = ft_substr((*parse)->ressources[line],
				0, ft_strlen((*parse)->ressources[line]));
	if ((*parse)->ressources[line][0] == 'E' && in_set("A",
		((*parse)->ressources[line][1])) && !(*parse)->east)
		(*parse)->east = ft_substr((*parse)->ressources[line],
				0, ft_strlen((*parse)->ressources[line]));
}

void	ressource_parse(t_parse **parse)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while ((*parse)->ressources[++i])
	{
		if (in_set("CF", (*parse)->ressources[i][j]))
			get_rgb(parse, i);
		else if (in_set("NSWE", (*parse)->ressources[i][j]))
			get_texture(parse, i);
		else
			print_free_exit("Error\nWrong texture format.\n", parse);
	}
	is_empty(parse);
	parse_ceiling(parse, (*parse)->ceiling);
	parse_floor(parse, (*parse)->floor);
	parse_texture(parse);
}
