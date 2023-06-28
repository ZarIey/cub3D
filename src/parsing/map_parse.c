/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:32:00 by bgales            #+#    #+#             */
/*   Updated: 2023/06/12 15:32:40 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	is_surrounded(char **map, int line, int index, t_parse **p)
{
	if (line == 0 || ft_strlen(map[line - 1]) < index)
		print_free_exit("Error\nAn element must be surrounded by walls.\n", p);
	if (ft_strlen(map[line + 1]) < index)
		print_free_exit("Error\nAn element must be surrounded by walls.\n", p);
	if (!in_set("10NEWS", map[line + 1][index]))
		print_free_exit("Error\nAn element must be surrounded by walls.\n", p);
	if (!in_set("10NEWS", map[line - 1][index]))
		print_free_exit("Error\nAn element must be surrounded by walls.\n", p);
	if (!in_set("10NEWS", map[line][index - 1]))
		print_free_exit("Error\nAn element must be surrounded by walls.\n", p);
	if (!in_set("10NEWS", map[line][index + 1]))
		print_free_exit("Error\nAn element must be surrounded by walls.\n", p);
}

void	is_attached(char **map, int line, int index, t_parse **parse)
{
	while (map[line][index])
	{
		if (line != 0)
			if (ft_strlen(map[line - 1]) > index)
				if (in_set("10NEWS", map[line - 1][index]))
					break ;
		if (map[line + 1] != NULL)
			if (ft_strlen(map[line + 1]) > index)
				if (in_set("10NEWS", map[line + 1][index]))
					break ;
		if (in_set("10NEWS", map[line][index - 1]))
			break ;
		index++;
	}
	if (!map[line][index])
		print_free_exit("Error\nMap must be of one block\n", parse);
}

void	room_parse(char **map, t_parse **parse)
{
	int	line;
	int	index;

	line = -1;
	index = -1;
	while (map[++line])
	{
		while (map[line][++index])
			if (map[line][index] == '0')
				is_surrounded(map, line, index, parse);
		index = -1;
	}
}

void	wall_parse(char **map, t_parse **parse)
{
	int	line;
	int	index;

	line = -1;
	index = 0;
	while (map[++line])
	{
		while (map[line][index])
		{
			if (map[line][index] == '1')
			{
				is_attached(map, line, index, parse);
				index += iter_walls(&map[line][index]);
				index += iter_space(&map[line][index]);
			}
			else
				index++;
		}
		index = 0;
	}
}

void	map_parser(char **map, t_parse **parse)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map[++i])
	{
		j += iter_space(&map[i][j]);
		if (map[i][j] != '1')
			print_free_exit("Error\nWrong map format.\n", parse);
		while (in_set("10NEWS ", map[i][j++]))
		{
			if (!map[i][j] || map[i][j] == '\n')
			{
				if (map[i][j - 1] != '1' && map[i][j - 1] != ' ')
					print_free_exit("Error\nWrong map format.\n", parse);
				break ;
			}
			if (!in_set("10NEWS ", map[i][j]))
				print_free_exit("Error\nWrong map format.\n", parse);
		}
		j = 0;
	}
	room_parse(map, parse);
	wall_parse(map, parse);
}
