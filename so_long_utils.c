/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebensalt <ebensalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:52:28 by ebensalt          #+#    #+#             */
/*   Updated: 2022/06/06 11:54:54 by ebensalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include "ft_printf.h"

void	ft_exit(int e, int key)
{
	if (e == 1)
		perror("error\n");
	if (e == 2)
		write(2, "error\n: map incorrect\n", 23);
	if (e == 0 && key == 53)
		ft_printf("YOU EXIT THE GAME\n");
	if (e == 0 && key == 0)
		ft_printf("YOU WON THE GAME\n");
	exit(e);
}

void	map_check(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	if (data->x >= data->y)
		ft_exit(2, 3);
	while (data->map[++i] != NULL)
	{
		if (ft_my_strlen(data->map[i]) != data->y)
			ft_exit(2, 3);
		if (data->map[i][0] != '1' || data->map[i][data->y - 1] != '1')
			ft_exit(2, 3);
		j = 0;
		while (data->map[i][j] != 0)
		{
			if (data->map[0][j] != '1' || data->map[data->x - 1][j] != '1')
				ft_exit(2, 3);
			if ((data->map[i][j] != '1' && data->map[i][j] != '0')
				&& (data->map[i][j] != 'C' && data->map[i][j] != 'P')
				&& data->map[i][j] != 'E')
				ft_exit(2, 3);
			j++;
		}
	}
	map_check2(data);
}

void	map_dem(t_data *data)
{
	data->x = 0;
	while (data->map[data->x] != NULL)
	{
		data->y = 0;
		while (data->map[data->x][data->y] != 0)
			data->y++;
		data->x++;
	}
}

char	**map_read(char **av)
{
	int		fd;
	char	*map_part;
	char	*map_line;
	char	**map;
	int		i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_exit(1, 3);
	map_part = get_next_line(fd);
	if (map_part == NULL || ft_my_strncmp(map_part, "\n", 1) == 0)
		ft_exit(2, 3);
	map_line = ft_my_strdup(map_part);
	map_line = map_read1(map_part, map_line, fd);
	if (ft_my_strncmp(ft_my_strrchr(map_line, '\n'), "\n", 2) == 0)
		ft_exit(2, 3);
	close(fd);
	map = ft_my_split(map_line, '\n');
	free(map_line);
	return (map);
}

void	file_check(int ac, char **av)
{
	int	i;

	if (ac != 2)
		ft_exit(1, 3);
	i = ft_strlen(av[1]);
	if ((av[1][i - 4] != '.' || av[1][i - 3] != 'b')
		|| (av[1][i - 2] != 'e' || av[1][i - 1] != 'r'))
		ft_exit(1, 3);
}
