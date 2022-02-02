/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:40:27 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/02 14:35:59 by acoquele         ###   ########.fr       */
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
	// free(map);
	exit(0);
}

void key_press (t_map *map)
{
	int keycode;

	keycode = 0;
	map->count = 0;
	if (keycode == 53)
		exit(0);
}

