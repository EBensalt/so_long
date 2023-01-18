/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebensalt <ebensalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:51:00 by ebensalt          #+#    #+#             */
/*   Updated: 2022/06/07 19:24:51 by ebensalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	*data;

	file_check(ac, av);
	data = malloc(sizeof(t_data));
	if (data == NULL)
		ft_exit(1, 3);
	data->map = map_read(av);
	map_dem(data);
	map_check(data);
	data->i = mlx_init();
	if (data->i == NULL)
		ft_exit(1, 3);
	data->m = 0;
	game(data);
	mlx_loop(data->i);
}
