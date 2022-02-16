/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:00:06 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/16 13:45:47 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	// char *path_xpm;
	// void	*x;
	// void	*mlx_win;
	t_map	map;
	if (argc == 2)
	{
		map.mlx = mlx_init();
		if (!map.mlx)
			error();
		map.name = argv[1];
		make_data(&map);
		if (map.x * map.y != map.count || map.flag > 1 || map.flag2 < 1 || map.flag3 < 1)
			error_map();
		make_array(&map);
		map_checker(&map);
		map.mlx_win = mlx_new_window(map.mlx, map.x_img * map.x, map.y_img * map.y, "SO_LONG");
		if(!map.mlx_win)
			error();
		mlx_hook(map.mlx_win, 17, 0, close_win,&map);
		mlx_hook(map.mlx_win, 2, 1L << 0, key_press,&map);
		map_drawer(&map);
		mlx_loop(map.mlx);
	}
}

void error_map()
{
	printf("map wrong format\n");
	red();
	printf("Be sure to check\n");
	reset();
	printf("that there is one player 'P'\n");
	printf("that the map is surrounded by '1'\n");
	printf("that there is at least one exit 'E'\n");
	printf("that there is at least one collectible 'C'\n");
	exit(0);
}

void error()
{
	printf("ERROR");
	exit(0);
}