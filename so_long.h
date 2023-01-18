/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebensalt <ebensalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:00:20 by ebensalt          #+#    #+#             */
/*   Updated: 2022/05/30 22:44:15 by ebensalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>

typedef struct s_game
{
	int		i;
	int		j;
	int		k;
}	t_game;

typedef struct s_data
{
	char	**map;
	int		x;
	int		y;
	void	*i;
	void	*nw;
	void	*ni0;
	void	*ni1;
	void	*nic;
	void	*nie;
	void	*nip;
	int		w;
	int		h;
	int		m;
}	t_data;

void	file_check(int ac, char **av);
char	**map_read(char **av);
char	*get_next_line(int fd);
char	**ft_my_split(char const *s, char c);
char	*ft_my_strjoin(char const *s1, char const *s2);
char	*ft_my_strdup(const char *s1);
void	map_dem(t_data *data);
int		ft_my_strlen(const char *s);
void	map_check(t_data *data);
void	game(t_data *data);
void	ft_exit(int e, int key);
void	ft_my_swap(char *a, char *b);
int		end_game(t_data *data);
void	ft_count(t_data *data, int key);
void	map_check2(t_data *data);
int		ft_my_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_my_strrchr(const char *s, int c);
void	ft_move1(t_data *data, t_game *l, int key);
void	ft_draw1(t_data *data, int i, int j);
char	*map_read1(char	*map_part, char *map_line, int fd);
#endif
