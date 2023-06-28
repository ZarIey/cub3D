/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:32:44 by bgales            #+#    #+#             */
/*   Updated: 2023/06/27 16:31:31 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_north_south(char *str, t_parse **parse)
{
	int		i;
	int		j;
	int		fd;
	char	*tmp;

	i = 1;
	fd = 0;
	if (str[i++] != 'O')
		print_free_exit("Error\nWrong texture format.\n", parse);
	i += iter_whitespace(&str[i]);
	j = iter_no_spaceornl(&str[i]);
	tmp = ft_substr(&str[i], 0, j);
	i += j;
	i += iter_whitespace(&str[i]) + 1;
	if (str[i] != '\0')
		free (tmp);
	if (str[i] != '\0')
		print_free_exit("Error\nTexture couldnt be loaded.\n", parse);
	if (open(tmp, O_RDONLY) < 0)
		free (tmp);
	if (open(tmp, O_RDONLY) < 0)
		print_free_exit("Error\nTexture couldnt be loaded.\n", parse);
	free(tmp);
	close(fd);
}

void	parse_east(char *str, t_parse **parse)
{
	int		i;
	int		j;
	int		fd;
	char	*tmp;

	i = 1;
	fd = 0;
	if (str[i++] != 'A')
		print_free_exit("Error\nWrong texture format.\n", parse);
	i += iter_whitespace(&str[i]);
	j = iter_no_spaceornl(&str[i]);
	tmp = ft_substr(&str[i], 0, j);
	i += j;
	i += iter_whitespace(&str[i]) + 1;
	if (str[i] != '\0')
		free (tmp);
	if (str[i] != '\0')
		print_free_exit("Error\nTexture couldnt be loaded.\n", parse);
	if (open(tmp, O_RDONLY) < 0)
		free (tmp);
	if (open(tmp, O_RDONLY) < 0)
		print_free_exit("Error\nTexture couldnt be loaded.\n", parse);
	free(tmp);
	close(fd);
}

void	parse_west(char *str, t_parse **parse)
{
	int		i;
	int		j;
	int		fd;
	char	*tmp;

	i = 1;
	fd = 0;
	if (str[i++] != 'E')
		print_free_exit("Error\nWrong texture format.\n", parse);
	i += iter_whitespace(&str[i]);
	j = iter_no_spaceornl(&str[i]);
	tmp = ft_substr(&str[i], 0, j);
	i += j;
	i += iter_whitespace(&str[i]) + 1;
	if (str[i] != '\0')
		free (tmp);
	if (str[i] != '\0')
		print_free_exit("Error\nTexture couldnt be loaded.\n", parse);
	if (open(tmp, O_RDONLY) < 0)
		free (tmp);
	if (open(tmp, O_RDONLY) < 0)
		print_free_exit("Error\nTexture couldnt be loaded.\n", parse);
	free (tmp);
	close(fd);
}

void	parse_texture(t_parse **parse)
{
	parse_north_south((*parse)->north, parse);
	parse_north_south((*parse)->south, parse);
	parse_east((*parse)->east, parse);
	parse_west((*parse)->west, parse);
}
