/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebensalt <ebensalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:39:43 by ebensalt          #+#    #+#             */
/*   Updated: 2022/05/30 20:52:27 by ebensalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check(t_data *data, char c)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != 0)
		{
			if (data->map[i][j] == c)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	map_check2(t_data *data)
{
	if (check(data, '0') == 1 || check(data, '1') == 1
		|| check(data, 'C') == 1 || check(data, 'P') == 1
		|| check(data, 'E') == 1)
		ft_exit(2, 3);
}
