/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:52:31 by ctardy            #+#    #+#             */
/*   Updated: 2023/06/08 22:13:53 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

/*
#include <stdio.h>
#include <ctype.h>
int	main()
{
	int	test = '1';
	int	test2 = 'a';
	int	test3 = ' ';

	printf("%d\n%d\n%d\n", ft_isdigit(test), ft_isdigit(test2), ft_isdigit(test3));
	printf("%d\n%d\n%d\n", isdigit(test), isdigit(test2), isdigit(test3));
}*/
