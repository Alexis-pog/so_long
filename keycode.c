/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:40:27 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/14 15:53:53 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_free(t_map *map)
{
	while (map->y + 1 > 0)
		free(map->tab[map->y--]);
	free(map->tab);
}

int close_win(t_map *map)
{
	ft_free(map);
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit(0);
}


/*
w : 13 126
a : 0 123
s : 1 125
d : 2 124
*/

void move_new_place(t_map *map, int keycode)
{
	if (keycode == 13)
		map->move_y_p--;
	if (keycode == 0)
		map->move_x_p--;
	if (keycode == 1)
		map->move_y_p++;
	if (keycode == 2)
		map->move_x_p++;
}

void wall_collision(t_map *map, int keycode)
{
	if (keycode == 13 && !(map->tab[map->move_y_p - 1][map->move_x_p] == '1'))
		move_new_place(map, keycode);
	if (keycode == 1 && !(map->tab[map->move_y_p + 1][map->move_x_p] == '1'))
		move_new_place(map, keycode);
	if (keycode == 2 && !(map->tab[map->move_y_p][map->move_x_p + 1] == '1'))
		move_new_place(map, keycode);
	if (keycode == 0 && !(map->tab[map->move_y_p][map->move_x_p - 1] == '1'))
		move_new_place(map, keycode);
}

void print_chr_new_place(t_map *map)
{
	map->background = mlx_xpm_file_to_image(map->mlx, "./assets/xpm/background.xpm", &map->x_img, &map->x_img);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->background , map->x_img * map->xx, map->y_img *map->yy);
	map->background = mlx_xpm_file_to_image(map->mlx, "./assets/xpm/background.xpm", &map->x_img, &map->x_img);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->background , map->x_img * map->move_x_p, map->y_img * map->move_y_p);
	map->background = mlx_xpm_file_to_image(map->mlx, "./assets/xpm/hero.xpm", &map->x_img, &map->x_img);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->background , map->x_img * map->move_x_p, map->y_img * map->move_y_p);
	map->xx = map->move_x_p;
	map->yy = map->move_y_p;
}

void draw_same_door(t_map *map)
{
	map->background = mlx_xpm_file_to_image(map->mlx, "./assets/xpm/door_closed.xpm", &map->x_img, &map->x_img);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->background , map->x_img * map->e_x_val, map->y_img *map->e_y_val);
	map->background = mlx_xpm_file_to_image(map->mlx, "./assets/xpm/hero.xpm", &map->x_img, &map->x_img);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->background , map->x_img * map->move_x_p, map->y_img * map->move_y_p);
}

void draw_new_door(t_map *map)
{
	map->background = mlx_xpm_file_to_image(map->mlx, "./assets/xpm/door_closed2.xpm", &map->x_img, &map->x_img);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->background , map->x_img * map->e_x_val, map->y_img *map->e_y_val);
}

void collectible(t_map *map)
{
	if (map->tab[map->move_y_p][map->move_x_p] == 'C')
		{
			if (map->col_val != 0)
				map->col_val--;
			if(map->col_val == 0)
				draw_new_door(map);
		}
		if (map->col_val == 0 && map->tab[map->move_y_p][map->move_x_p] == 'E')
			close_win(map);
}

int  key_press (int keycode, t_map *map)
{
	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2 )
	{
		map->background = mlx_xpm_file_to_image(map->mlx, "./assets/xpm/background.xpm", &map->x_img, &map->x_img);
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->background , map->x_img * map->p_x_val, map->y_img *map->p_y_val);
		printf("you move your player %d time(s)", map->move_player++);
	}
	printf("%d\n", keycode);
	// printf("%d",map->y);
	if (keycode == 53)
	{
		close_win(map);
		exit (0);
	}
	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2 )
	{
		wall_collision(map,keycode);
		print_chr_new_place(map);
		if (map->tab[map->e_y_val][map->e_x_val] == 'E' && map->col_val != 0)
			draw_same_door(map);
		collectible(map);
	}
	return (0);
}