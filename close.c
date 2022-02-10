/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:40:27 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/10 11:44:17 by acoquele         ###   ########.fr       */
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

int  key_press (int keycode, t_map *map)
{
	
	printf("%d\n", keycode);
	if (keycode == 53)
	{
		close_win(map);
		exit (0);
	}
	// printf("%d", map->count);
	return (0);
}

