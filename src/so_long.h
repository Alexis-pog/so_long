/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:06:37 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/22 10:26:06 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
// # include "../wraloc/wraloc.h"

typedef struct s_map
{
	int		x;
	int		y;
	int		x_img;
	int		y_img;
	int		xx;
	int		yy;
	int		n;
	int		count;
	int		flag;
	int		flag2;
	int		flag3;
	int		move_x_p;
	int		move_y_p;
	int		p_x_val;
	int		p_y_val;
	int		psyp;
	int		psxp;
	int		e_x_val;
	int		e_y_val;
	int		col_val;
	int		move_player;
	char	*s;
	int		fd;
	char	**tab;
	char	*name;
	void	*img;
	void	*mlx;
	void	*mlx_win;
	void	*background;
	void	*player;
	void	*collectible;
	void	*exit;
	void	*wall;
}	t_map;

/* parser (get data) */
char	*get_simple(int fd, t_map *map);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_strrchr(const char *s, int c);
int		ft_strlen_modif(char *c);
int		ft_strlen(char *c);
void	*ft_memset(void *str, int c, int n);
void	make_data(t_map *map);
void	make_array(t_map *map);
void	map_maker_modif(t_map *map);
void	specific_val_reset(t_map *map);
void	verif_map_name(t_map *map);

/* change value */
void	reset_map_value(t_map *map);
void	ft_free(t_map *map);

/*draw the map and move player */
int		wall_collision_counter(t_map *map, int keycode);
void	move_new_place(t_map *map, int keycode);
void	map_drawer(t_map *map);
void	draw_exit(t_map *map);
void	draw_collectible(t_map *map);
void	draw_player(t_map *map);
void	draw_background(t_map *map);
void	draw_wall(t_map *map);
void	wall_collision(t_map *map, int keycode);
void	print_chr_new_place(t_map *map);
void	draw_same_door(t_map *map);
void	draw_new_door(t_map *map);
void	collectible(t_map *map);
void	map_checker(t_map *map);
void	area_hight(t_map *map, char *buf);
void	set_img(t_map *map);
char	*ft_strdup_modif(const char *s1);
void	make_thing(t_map *map);

/* keypress */
void	esc(t_map *map);
int		key_press(int keycode, t_map *map);
void	keyhook(t_map *map);

/* error */
void	error(t_map *map);
void	error_map(t_map *map);
void	inv_size(t_map *map);
int		close_win(t_map *map);
void	error_close(t_map *map);
#endif