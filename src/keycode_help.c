/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:17:00 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/22 10:13:51 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_chr_new_place(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->background, map->x_img * map->psxp, map->y_img * map->psyp);
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->background, map->x_img * map->move_x_p,
		map->y_img * map->move_y_p);
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->player, map->x_img * map->move_x_p,
		map->y_img * map->move_y_p);
	map->psxp = map->move_x_p;
	map->psyp = map->move_y_p;
}

void	draw_same_door(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->exit, map->x_img * map->e_x_val, map->y_img * map->e_y_val);
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->player, map->x_img * map->move_x_p,
		map->y_img * map->move_y_p);
}

void	draw_new_door(t_map *map)
{
	map->exit = mlx_xpm_file_to_image(map->mlx,
			"./assets/xpm/door_closed2.xpm", &map->x_img, &map->x_img);
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->exit, map->x_img * map->e_x_val, map->y_img * map->e_y_val);
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
