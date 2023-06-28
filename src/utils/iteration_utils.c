/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:23:26 by bgales            #+#    #+#             */
/*   Updated: 2023/04/20 11:48:46 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	iter_walls(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] == '1')
		i++;
	return (i);
}

int	iter_space(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

int	iter_no_spaceornl(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] != ' ' && str[i] != '	'
			&& str[i] != '\v' && str[i] != '\n'))
		i++;
	return (i);
}

int	iter_whitespace(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i] && (str[i] == ' ' || str[i] == '	' || str[i] == '\v'))
		;
	return (i);
}

int	iter_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}
