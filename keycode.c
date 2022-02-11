/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:40:27 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/11 16:21:00 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_free(t_map *map)
{
	while (map->y > 0)
		free(map->tab[map->y--]);
	free(map->tab);
}

int close_win(t_map *map)
{
	mlx_destroy_window(map->mlx, map->mlx_win);
	ft_free(map);
	exit(0);
}

int  key_press (int keycode, t_map *map)
{
	
	printf("%d\n", keycode);
	// printf("%d",map->y);
	if (keycode == 53)
	{
		close_win(map);
		exit (0);
	}
	
	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2 )
	{
		if (keycode == 13 && !(map->tab[map->move_y_p - 1][map->move_x_p] == '1'))
			move_new_place(map, keycode);
		if (keycode == 1 && !(map->tab[map->move_y_p + 1][map->move_x_p] == '1'))
			move_new_place(map, keycode);
		if (keycode == 2 && !(map->tab[map->move_y_p][map->move_x_p + 1] == '1'))
			move_new_place(map, keycode);
		if (keycode == 0 && !(map->tab[map->move_y_p][map->move_x_p - 1] == '1'))
			move_new_place(map, keycode);
		
		map->background = mlx_xpm_file_to_image(map->mlx, "./assets/xpm/background.xpm", &map->x_img, &map->x_img);
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->background , map->x_img * map->xx, map->y_img *map->yy);
		map->background = mlx_xpm_file_to_image(map->mlx, "./assets/xpm/background.xpm", &map->x_img, &map->x_img);
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->background , map->x_img * map->move_x_p, map->y_img * map->move_y_p);
		map->background = mlx_xpm_file_to_image(map->mlx, "./assets/xpm/hero.xpm", &map->x_img, &map->x_img);
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->background , map->x_img * map->move_x_p, map->y_img * map->move_y_p);
		map->xx = map->move_x_p;
		map->yy = map->move_y_p;
	}
	
	// printf("%d", map->count);
	return (0);
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
