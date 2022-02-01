/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:00:06 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/01 15:04:17 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	// char *path_xpm;
	// void	*x;
	void	*mlx_win;
	t_map	map;
	if (argc == 2)
	{
		map.name = argv[1];
		make_data(&map);
		if (map.x * map.y != map.count)
			return (printf("map format wrong"));
		use_data(&map);
		map.img = mlx_new_image(map.mlx, 1920, 1080);
		mlx_win = mlx_new_window(map.mlx, map.x_img * map.x, map.y_img * map.y, "SO_LONG");
		// mlx_xpm_file_to_image(img.mlx, "./assets/xpm/background.xpm", &img.x, &img.y);
		map.background = mlx_xpm_file_to_image(map.mlx, "./assets/xpm/background.xpm", &map.x_img, &map.x_img);
		mlx_put_image_to_window(map.mlx, mlx_win, map.background , 0, 0);
		map.background = mlx_xpm_file_to_image(map.mlx, "./assets/xpm/wall.xpm", &map.x_img, &map.x_img);
		mlx_put_image_to_window(map.mlx, mlx_win, map.background , 0, 0);
		mlx_hook(map.mlx_win, 17, 0, close_win,&map);
		mlx_loop(map.mlx);
	}
}