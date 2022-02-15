/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:40:27 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/15 13:15:47 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


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

void collectible(t_map *map)
{
	if (map->tab[map->move_y_p][map->move_x_p] == 'C')
		{
			if (map->col_val != 0)
				map->col_val--;
			if(map->col_val == 0)
				draw_new_door(map);
			map->tab[map->move_y_p][map->move_x_p] = '0';
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
		if (wall_collision_counter(map, keycode) == 1)
			printf("you move your player %d time(s)", map->move_player++);
	}
	printf("%d\n", keycode);
	// printf("%d",map->y);
	if (keycode == 53)
		ESC(map);
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