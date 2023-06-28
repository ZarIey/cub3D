/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:42:32 by bgales            #+#    #+#             */
/*   Updated: 2023/06/25 20:07:24 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_struct(t_parse **parse)
{
	int	i;

	i = -1;
	if ((*parse)->map)
		while ((*parse)->map[++i])
			free((*parse)->map[i]);
	free ((*parse)->map);
	i = -1;
	if ((*parse)->ressources)
		while ((*parse)->ressources[++i])
			free((*parse)->ressources[i]);
	free ((*parse)->ressources);
	free((*parse)->floor);
	free((*parse)->ceiling);
	free((*parse)->north);
	free((*parse)->west);
	free((*parse)->east);
	free((*parse)->south);
	free (*parse);
}

void	free_char_array(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free (tab);
}

void	print_free_exit(char *str, t_parse **parse)
{
	if (str)
		printf("%s", str);
	free_struct(parse);
	exit (0);
}

int	exit_game(t_game *game)
{
	print_free_exit("Thanks for playing\n", &game->parse);
	return (0);
}
