/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebensalt <ebensalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:25:27 by ebensalt          #+#    #+#             */
/*   Updated: 2022/06/06 10:22:40 by ebensalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

void	ft_count2(t_data *data, int i, int j, int key)
{
	while (data->map[i][j] != 0)
	{
		if ((data->map[i][j] == 'P' && key == 0)
			&& (data->map[i][j - 1] != '1' && data->map[i][j - 1] != 'E'))
			ft_printf("%d\n", ++data->m);
		if ((data->map[i][j] == 'P' && key == 2)
			&& (data->map[i][j + 1] != '1' && data->map[i][j + 1] != 'E'))
		{
			ft_printf("%d\n", ++data->m);
			break ;
		}
		if ((data->map[i][j] == 'P' && key == 13)
			&& (data->map[i - 1][j] != '1' && data->map[i - 1][j] != 'E'))
			ft_printf("%d\n", ++data->m);
		if ((data->map[i][j] == 'P' && key == 1)
			&& (data->map[i + 1][j] != '1' && data->map[i + 1][j] != 'E'))
		{
			ft_printf("%d\n", ++data->m);
			i++;
		}
		j++;
	}
}

void	ft_count(t_data *data, int key)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		ft_count2(data, i, j, key);
		i++;
	}
}
