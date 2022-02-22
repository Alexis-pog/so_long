/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:00:06 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/22 10:27:10 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		map.mlx = mlx_init();
		if (map.mlx != 0)
		{
			map.name = argv[1];
			verif_map_name(&map);
			make_data(&map);
			if (map.x * map.y != map.count
				|| map.flag > 1 || map.flag2 < 1 || map.flag3 < 1)
				error_map(&map);
			make_thing(&map);
			map.mlx_win = mlx_new_window(map.mlx, 64 * map.x,
					64 * map.y, "SO_LONG");
			if (!map.mlx_win)
				error(&map);
			map_drawer(&map);
			keyhook(&map);
			mlx_loop(map.mlx);
		}
		return (0);
	}
	return (0);
}

void	keyhook(t_map *map)
{
	mlx_hook(map->mlx_win, 17, 0, close_win, map);
	mlx_hook(map->mlx_win, 2, 1L << 0, key_press, map);
}

void	make_thing(t_map *map)
{
	make_array(map);
	map_checker(map);
}
