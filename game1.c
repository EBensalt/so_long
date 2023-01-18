/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebensalt <ebensalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:21:47 by ebensalt          #+#    #+#             */
/*   Updated: 2022/05/30 22:43:59 by ebensalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move2(t_data *data, int i, int j, int key)
{
	char	c;

	c = '0';
	if ((data->map[i][j] == 'P' && key == 0)
		&& (data->map[i][j - 1] == 'C'))
		ft_my_swap(&data->map[i][j - 1], &c);
	if ((data->map[i][j] == 'P' && key == 0)
		&& data->map[i][j - 1] == '0')
		ft_my_swap(&data->map[i][j], &data->map[i][j - 1]);
	if ((data->map[i][j] == 'P' && key == 2)
		&& data->map[i][j + 1] == 'C')
		ft_my_swap(&data->map[i][j + 1], &c);
	if ((data->map[i][j] == 'P' && key == 13)
		&& data->map[i - 1][j] == 'C')
		ft_my_swap(&data->map[i - 1][j], &c);
	if ((data->map[i][j] == 'P' && key == 13)
		&& data->map[i - 1][j] == '0')
		ft_my_swap(&data->map[i][j], &data->map[i - 1][j]);
	if ((data->map[i][j] == 'P' && key == 1)
		&& data->map[i + 1][j] == 'C')
		ft_my_swap(&data->map[i + 1][j], &c);
}

void	ft_move3(t_data *data, int i, int j, int key)
{
	if ((data->map[i][j] == 'P' && key == 0)
		&& data->map[i][j - 1] == 'E')
		ft_exit(0, 0);
	if ((data->map[i][j] == 'P' && key == 2)
		&& data->map[i][j + 1] == 'E')
		ft_exit(0, 0);
	if ((data->map[i][j] == 'P' && key == 13)
		&& data->map[i - 1][j] == 'E')
		ft_exit(0, 0);
	if ((data->map[i][j] == 'P' && key == 1)
		&& data->map[i + 1][j] == 'E')
		ft_exit(0, 0);
}

void	ft_move1(t_data *data, t_game *l, int key)
{
	while (data->map[l->i][l->j] != 0)
	{
		if (l->k == 0)
			ft_move3(data, l->i, l->j, key);
		ft_move2(data, l->i, l->j, key);
		if ((data->map[l->i][l->j] == 'P' && key == 2)
			&& data->map[l->i][l->j + 1] == '0')
		{
			ft_my_swap(&data->map[l->i][l->j], &data->map[l->i][l->j + 1]);
			break ;
		}
		ft_move2(data, l->i, l->j, key);
		if ((data->map[l->i][l->j] == 'P' && key == 1)
			&& data->map[l->i + 1][l->j] == '0')
		{
			ft_my_swap(&data->map[l->i][l->j], &data->map[l->i + 1][l->j]);
			l->i++;
		}
		l->j++;
	}
}

void	ft_draw1(t_data *data, int i, int j)
{
	while (data->map[i][j] != 0)
	{
		if (data->map[i][j] == '0')
			mlx_put_image_to_window(data->i,
				data->nw, data->ni0, j * 50, i * 50);
		if (data->map[i][j] == '1')
			mlx_put_image_to_window(data->i,
				data->nw, data->ni1, j * 50, i * 50);
		if (data->map[i][j] == 'C')
			mlx_put_image_to_window(data->i,
				data->nw, data->nic, j * 50, i * 50);
		if (data->map[i][j] == 'E')
			mlx_put_image_to_window(data->i,
				data->nw, data->nie, j * 50, i * 50);
		if (data->map[i][j] == 'P')
			mlx_put_image_to_window(data->i,
				data->nw, data->nip, j * 50, i * 50);
		j++;
	}
}

char	*map_read1(char	*map_part, char *map_line, int fd)
{
	while (map_part != NULL)
	{
		free(map_part);
		map_part = get_next_line(fd);
		if (map_part != NULL && ft_my_strncmp(map_part, "\n", 1) == 0)
			ft_exit(2, 3);
		if (map_part != NULL)
			map_line = ft_my_strjoin(map_line, map_part);
	}
	return (map_line);
}
