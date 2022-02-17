/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:17:00 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/17 11:29:09 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_chr_new_place(t_map *map)
{
	map->background = mlx_xpm_file_to_image(map->mlx,
			"./assets/xpm/background.xpm", &map->x_img, &map->x_img);
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->background, map->x_img * map->xx, map->y_img * map->yy);
	map->background = mlx_xpm_file_to_image(map->mlx,
			"./assets/xpm/background.xpm", &map->x_img, &map->x_img);
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->background, map->x_img * map->move_x_p,
		map->y_img * map->move_y_p);
	map->background = mlx_xpm_file_to_image(map->mlx,
			"./assets/xpm/hero.xpm", &map->x_img, &map->x_img);
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->background, map->x_img * map->move_x_p,
		map->y_img * map->move_y_p);
	map->xx = map->move_x_p;
	map->yy = map->move_y_p;
}

void	draw_same_door(t_map *map)
{
	map->background = mlx_xpm_file_to_image(map->mlx,
			"./assets/xpm/door_closed.xpm", &map->x_img, &map->x_img);
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->background, map->x_img * map->e_x_val, map->y_img * map->e_y_val);
	map->background = mlx_xpm_file_to_image(map->mlx,
			"./assets/xpm/hero.xpm", &map->x_img, &map->x_img);
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->background, map->x_img * map->move_x_p,
		map->y_img * map->move_y_p);
}

void	draw_new_door(t_map *map)
{
	map->background = mlx_xpm_file_to_image(map->mlx,
			"./assets/xpm/door_closed2.xpm", &map->x_img, &map->x_img);
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->background, map->x_img * map->e_x_val, map->y_img * map->e_y_val);
}

void	wall_collision(t_map *map, int keycode)
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

int	wall_collision_counter(t_map *map, int keycode)
{
	if (keycode == 13 && !(map->tab[map->move_y_p - 1][map->move_x_p] == '1'))
		return (1);
	if (keycode == 1 && !(map->tab[map->move_y_p + 1][map->move_x_p] == '1'))
		return (1);
	if (keycode == 2 && !(map->tab[map->move_y_p][map->move_x_p + 1] == '1'))
		return (1);
	if (keycode == 0 && !(map->tab[map->move_y_p][map->move_x_p - 1] == '1'))
		return (1);
	return (0);
}
