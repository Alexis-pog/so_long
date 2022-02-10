/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:00:06 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/10 11:39:53 by acoquele         ###   ########.fr       */
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
		map.name = argv[1];
		make_data(&map);
		if (map.x * map.y != map.count)
			return (printf("map format wrong"));
		use_data(&map);
		// printf("2%d", map.x);
		// printf("2%d", map.y);
		map.img = mlx_new_image(map.mlx, 1920, 1080);
		map.mlx_win = mlx_new_window(map.mlx, map.x_img * map.x, map.y_img * map.y, "SO_LONG");
		mlx_hook(map.mlx_win, 17, 0, close_win,&map);
		mlx_hook(map.mlx_win, 2, 1L << 0, key_press,&map);
		map_drawer(&map);
		mlx_loop(map.mlx);
	}
}