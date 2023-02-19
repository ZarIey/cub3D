/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:49:49 by ctardy            #+#    #+#             */
/*   Updated: 2023/02/19 18:05:41 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int map_reader(char **argv, int flag)
{
	int		fd;
	char	*inter;
	int		count;
	
	count = 0;
	fd = open(argv[1], O_RDONLY);
	while("oh yeah")
	{
		inter = get_next_line(fd);
		if (!flag)
			count++;	
		if (!inter)
			break ;
		free(inter);
	}
	close (fd);
	return (count);
}