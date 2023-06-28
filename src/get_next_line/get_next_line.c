/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:22:34 by bjm               #+#    #+#             */
/*   Updated: 2023/04/18 18:35:36 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_new_line(int fd)
{
	int			i;
	char		buffer[2];
	char		*newline;

	if (fd < 0)
		return (NULL);
	i = 1;
	newline = NULL;
	while (i > 0 && !ft_strchr(newline, '\n'))
	{
		i = read(fd, buffer, 1);
		buffer[i] = '\0';
		if (i == -1)
			return (NULL);
		newline = ft_strjoin(newline, buffer);
		if (newline[0] == 0)
		{
			free (newline);
			return (NULL);
		}
	}
	return (newline);
}

char	*ft_selectbeforenl(char *newline)
{
	int		i;
	char	*ret;

	i = 0;
	while (newline[i] != '\n')
		i++;
	ret = malloc(sizeof(char) * i + 2);
	i = 0;
	while (newline[i] != '\n')
	{
		ret[i] = newline[i];
		i++;
	}
	ret[i] = '\n';
	ret[i + 1] = '\0';
	return (ret);
}

char	*ft_selectafternl(char *s1)
{
	int		i;
	int		j;
	char	*test;

	i = 0;
	j = 0;
	while (s1[i] != '\n')
		i++;
	i++;
	test = malloc(sizeof(char) * (ft_strlen(s1) - i + 1));
	while (s1[i])
		test[j++] = s1[i++];
	test[j] = '\0';
	return (test);
}

char	*get_next_line(int fd)
{
	static char	*newline;
	char		*ret;
	char		*test;

	ret = ft_get_new_line(fd);
	test = ft_strjoin(newline, ret);
	free (ret);
	if (ft_strchr(test, '\n'))
	{
		ret = ft_selectbeforenl(test);
		newline = ft_selectafternl(test);
		free (test);
		return (ret);
	}
	ret = ft_strdup(test);
	newline = NULL;
	free (test);
	if (ret[0] == 0)
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}
