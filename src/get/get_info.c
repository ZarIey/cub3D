/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:24:42 by bgales            #+#    #+#             */
/*   Updated: 2023/06/08 23:14:34 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**get_file(char *map_path, t_parse **parse)
{
	int		fd;
	char	**ret;
	int		i;

	is_cub(map_path, parse);
	ret = malloc(sizeof(char *) * (brut_file_size(map_path) + 1));
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		print_free_exit("Error\nMap file was not found.\n", parse);
	i = 0;
	while (1)
	{
		ret[i] = get_next_line(fd);
		if (!ret[i])
			break ;
		i++;
	}
	close(fd);
	ret = del_empty_lines(ret);
	i = 0;
	while (ret[i])
		i++;
	if (i <= 6)
		print_free_exit("Error\nMap file is incomplete.\n", parse);
	return (ret);
}

char	**get_map(char **cub_file)
{
	int		i;
	int		j;
	char	**ret;

	i = 6;
	j = 0;
	while (cub_file[i])
	{
		i++;
		j++;
	}
	ret = malloc(sizeof(char *) * (j + 1));
	i = 6;
	j = 0;
	while (cub_file[i])
		ret[j++] = ft_strdup(cub_file[i++]);
	ret[j] = NULL;
	return (ret);
}

char	**get_ressources(char **cub_file, t_parse **parse)
{
	int		i;
	int		j;
	char	**ret;

	ret = malloc(sizeof(char *) * 7);
	i = -1;
	j = 0;
	while (++i < 6)
	{
		j += iter_whitespace(cub_file[i]);
		ret[i] = ft_substr(cub_file[i], j, ft_strlen(cub_file[i]));
		j = 0;
	}
	j += iter_whitespace(cub_file[i]);
	if (cub_file[i][j] != '1')
	{
		free_char_array(cub_file);
		print_free_exit("Error\n map file uncorrectly formated.\n", parse);
	}
	ret[i] = NULL;
	return (ret);
}
