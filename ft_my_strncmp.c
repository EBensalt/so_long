/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_strncmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebensalt <ebensalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:19:46 by ebensalt          #+#    #+#             */
/*   Updated: 2022/06/06 11:53:46 by ebensalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_my_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			a;
	unsigned char	*b;
	unsigned char	*c;
	size_t			d;

	b = (unsigned char *)s1;
	c = (unsigned char *)s2;
	a = 0;
	d = 0;
	if (!s1)
		return (0);
	while (b[d] || c[d])
		d++;
	while (a < n && a < d)
	{
		if (b[a] > c[a])
			return (b[a] - c[a]);
		if (b[a] < c[a])
			return (b[a] - c[a]);
		a++;
	}
	return (0);
}
