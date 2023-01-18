/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebensalt <ebensalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 02:36:12 by ebensalt          #+#    #+#             */
/*   Updated: 2022/05/27 10:18:40 by ebensalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count(unsigned long n)
{
	int	a;

	a = 0;
	while (n / 16 > 0)
	{
		a++;
		n = n / 16;
	}
	return (a + 1);
}

int	ft_puthexap(unsigned long unbr, char *base16)
{
	int	i;

	i = count(unbr);
	if ((unbr / 16) >= 16)
	{
		ft_puthexap((unbr / 16), base16);
		ft_putchar_fd(base16[unbr % 16], 1);
	}
	else
	{
		if (unbr / 16 > 0)
		{
			ft_putchar_fd(base16[unbr / 16], 1);
			ft_putchar_fd(base16[unbr % 16], 1);
		}
		else
			ft_putchar_fd(base16[unbr % 16], 1);
	}
	return (i);
}
