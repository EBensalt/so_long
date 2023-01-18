/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebensalt <ebensalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:19:15 by ebensalt          #+#    #+#             */
/*   Updated: 2022/05/26 04:11:42 by ebensalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_my_strdup(const char *s1)
{
	int		a;
	char	*b;

	a = 0;
	while (s1[a] != '\0')
		a++;
	b = malloc(a + 1 * sizeof(char));
	if (b == NULL)
		return (0);
	a = 0;
	while (s1[a] != '\0')
	{
		b[a] = s1[a];
		a++;
	}
	b[a] = '\0';
	return (b);
}
