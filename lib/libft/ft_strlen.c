/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:05:13 by ctardy            #+#    #+#             */
/*   Updated: 2023/06/09 09:17:35 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const	char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
/*
 int main()
{
    const char *str = "kikoo les loulous";
    printf("%zu\n", ft_strlen(str));
    printf("%zu\n", strlen(str));
}
*/
