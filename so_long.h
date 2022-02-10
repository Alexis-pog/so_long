/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:06:37 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/09 17:48:44 by acoquele         ###   ########.fr       */
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
	int x_img;
	int y_img;
	int xx;
	int yy;
	int count;
	int flag;
	char *r;
	char *s;
	int fd;
	char **tab;
	char *name;
	void *img;
	void *mlx;
	void *mlx_win;
	void *background;
	char *addr;
} 	t_map;

char    *get_simple(int fd, t_map *map);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(const char *s1);
int 	ft_strlen(char *c);
void    make_data(t_map *map);
int 	ft_strlen(char *c);
int		map_checker(t_map *map);
void	use_data(t_map *map);
void    *ft_memset(void *str, int c, int n);
void 	reset_map_value(t_map *map);
int 	close_win(t_map *map);
void 	ft_free(t_map *map);
void 	map_drawer(t_map *map);
int 	key_press(int keycode, t_map *map);
void 	map_maker_modif(t_map *map);
void 	print_array(t_map *map);
void 	specific_val_reset(t_map *map);
void 	red();
void 	reset();
void 	green();
#endif