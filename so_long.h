/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:06:37 by acoquele          #+#    #+#             */
/*   Updated: 2022/01/31 14:25:13 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./mlx/mlx.h"
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
	int x;
	int y;
	int n;
	int count;
	char *r;
	char *s;
	int fd;
	char **tab;
	char *name;
} t_map;

typedef struct	s_data {
	void	*img;
	void	*mlx;
	void	*mlx_win;
	void	*background;
	char	*addr;
	int		x;
	int		y;
	int		endian;
}	t_data;

char    *get_simple(int fd, t_map *map);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(const char *s1);
int 	ft_strlen(char *c);
char 	**get_x_y(t_map *map);
void    make_data(t_data *img, t_map *map);
int 	ft_strlen(char *c);
int		map_checker(t_map *map);
void	use_data(t_map *map);
void    *ft_memset(void *str, int c, int n);
#endif