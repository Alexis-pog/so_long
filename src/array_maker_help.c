/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_maker_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:58:06 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/17 11:24:21 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_wall(t_map *map)
{
	map->background = mlx_xpm_file_to_image(map->mlx,
			"./assets/xpm/background.xpm", &map->x_img, &map->x_img);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->background,
		map->x_img * map->xx, map->y_img * map->yy);
	map->background = mlx_xpm_file_to_image(map->mlx,
			"./assets/xpm/wall.xpm", &map->x_img, &map->x_img);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->background,
		map->x_img * map->xx, map->y_img * map->yy);
}

void	draw_background(t_map *map)
{
	map->background = mlx_xpm_file_to_image(map->mlx,
			"./assets/xpm/background.xpm", &map->x_img, &map->x_img);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->background,
		map->x_img * map->xx, map->y_img * map->yy);
}

void	draw_player(t_map *map)
{
	map->background = mlx_xpm_file_to_image(map->mlx,
			"./assets/xpm/background.xpm", &map->x_img, &map->x_img);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->background,
		map->x_img * map->xx, map->y_img * map->yy);
	map->background = mlx_xpm_file_to_image(map->mlx,
			"./assets/xpm/hero.xpm", &map->x_img, &map->x_img);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->background,
		map->x_img * map->xx, map->y_img * map->yy);
	map->move_x_p = map->xx;
	map->move_y_p = map->yy;
	map->p_y_val = map->yy;
	map->p_x_val = map->xx;
}

void	draw_collectible(t_map *map)
{
	map->background = mlx_xpm_file_to_image(map->mlx,
			"./assets/xpm/background.xpm", &map->x_img, &map->x_img);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->background,
		map->x_img * map->xx, map->y_img * map->yy);
	map->background = mlx_xpm_file_to_image(map->mlx,
			"./assets/xpm/collectible.xpm", &map->x_img, &map->x_img);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->background,
		map->x_img * map->xx, map->y_img * map->yy);
	map->col_val++;
}

void	draw_exit(t_map *map)
{
	map->background = mlx_xpm_file_to_image(map->mlx,
			"./assets/xpm/background.xpm", &map->x_img, &map->x_img);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->background,
		map->x_img * map->xx, map->y_img * map->yy);
	map->background = mlx_xpm_file_to_image(map->mlx,
			"./assets/xpm/door_closed.xpm", &map->x_img, &map->x_img);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->background,
		map->x_img * map->xx, map->y_img * map->yy);
	map->e_x_val = map->xx;
	map->e_y_val = map->yy;
}
