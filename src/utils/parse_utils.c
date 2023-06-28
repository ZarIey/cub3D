/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:30:27 by bgales            #+#    #+#             */
/*   Updated: 2023/06/08 23:06:02 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	null_all(t_parse **parse)
{
	(*parse)->north = NULL;
	(*parse)->south = NULL;
	(*parse)->east = NULL;
	(*parse)->west = NULL;
	(*parse)->ceiling = NULL;
	(*parse)->floor = NULL;
	(*parse)->ressources = NULL;
	(*parse)->map = NULL;
}

int	in_set(char *set, char c)
{
	int	i;

	i = -1;
	while (set[++i])
	{
		if (set[i] == c)
			return (1);
	}
	return (0);
}

void	is_cub(char *map_path, t_parse **parse)
{
	if (map_path[ft_strlen(map_path) - 4] != '.'
		|| map_path[ft_strlen(map_path) - 3] != 'c'
		|| map_path[ft_strlen(map_path) - 2] != 'u'
		|| map_path[ft_strlen(map_path) - 1] != 'b')
		print_free_exit("Error\nMap must be to \".cub\" format\n", parse);
}

char	**del_empty_lines(char **file)
{
	int		i;
	int		j;
	int		c;
	char	**ret;

	i = -1;
	ret = malloc(sizeof(char *) * (coolsize(file) + 1) + (j = 0) + (c = 0));
	while (file[++i] && c < coolsize(file))
	{
		j += iter_whitespace(file[i]);
		if (file[i][j] && (file[i][j] == '\0' || file[i][j] == '\n') && c <= 6)
			j = 0;
		else
		{
			if (c < 6)
				ret[c] = ft_substr(file[i], j, ft_strlen(file[i]));
			else
					ret[c] = ft_substr(file[i], 0, ft_strlen(file[i]));
			c++;
			j = 0;
		}
	}
	ret[c] = NULL;
	free_char_array(file);
	return (ret);
}
