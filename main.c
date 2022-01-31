/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:00:06 by acoquele          #+#    #+#             */
/*   Updated: 2022/01/31 16:02:54 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	// char *path_xpm;
	// void	*x;
	void	*mlx_win;
	t_data	img;
	t_map	map;
	if (argc == 2)
	{
		map.name = argv[1];
		make_data(&img,&map);
		if (map.x * map.y != map.count)
			return (printf("map format wrong"));
		use_data(&map);
		img.img = mlx_new_image(img.mlx, 1920, 1080);
		mlx_win = mlx_new_window(img.mlx, img.x * map.x, img.y * map.y, "SO_LONG");
		// mlx_xpm_file_to_image(img.mlx, "./assets/xpm/background.xpm", &img.x, &img.y);
		img.background = mlx_xpm_file_to_image(img.mlx, "./assets/xpm/background.xpm", &img.x, &img.x);
		mlx_put_image_to_window(img.mlx, mlx_win, img.background , 0, 0);
		img.background = mlx_xpm_file_to_image(img.mlx, "./assets/xpm/wall.xpm", &img.x, &img.x);
		mlx_put_image_to_window(img.mlx, mlx_win, img.background , 0, 0);
		mlx_loop(img.mlx);
	}
}