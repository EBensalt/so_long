/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebensalt <ebensalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:22:29 by ebensalt          #+#    #+#             */
/*   Updated: 2022/06/07 19:28:26 by ebensalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

void	ft_move(t_data *data, int key)
{
	t_game	l;

	l.i = 0;
	ft_count(data, key);
	while (data->map[l.i] != NULL)
	{
		l.j = 0;
		ft_move1(data, &l, key);
		l.k = end_game(data);
		l.i++;
	}
}

void	ft_draw(t_data *data)
{
	int	i;
	int	j;

	data->nw = mlx_new_window(data->i, data->y * 50, data->x * 50, "so_long");
	if (data->nw == NULL)
		ft_exit(1, 3);
	data->ni0 = mlx_xpm_file_to_image(data->i,
			"images/0.xpm", &data->w, &data->h);
	data->ni1 = mlx_xpm_file_to_image(data->i,
			"images/1.xpm", &data->w, &data->h);
	data->nic = mlx_xpm_file_to_image(data->i,
			"images/C.xpm", &data->w, &data->h);
	data->nie = mlx_xpm_file_to_image(data->i,
			"images/E.xpm", &data->w, &data->h);
	data->nip = mlx_xpm_file_to_image(data->i,
			"images/P.xpm", &data->w, &data->h);
	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		ft_draw1(data, i, j);
		i++;
	}
}

int	ft_key(int key, t_data *data)
{
	(void)data;
	if (key == 53)
		ft_exit(0, key);
	if (key == 0 || key == 2 || key == 13 || key == 1)
	{
		mlx_destroy_window(data->i, data->nw);
		ft_move(data, key);
		game(data);
	}
	return (0);
}

int	ft_cross(t_data *data)
{
	(void)data;
	ft_printf("YOU EXIT THE GAME\n");
	exit(0);
}

void	game(t_data *data)
{
	ft_draw(data);
	mlx_key_hook(data->nw, ft_key, data);
	mlx_hook(data->nw, 17, 0, ft_cross, data);
}
