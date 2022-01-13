/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:00:06 by acoquele          #+#    #+#             */
/*   Updated: 2022/01/13 17:41:08 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main()
{
	// char *path_xpm;
	void	*mlx_win;
	t_data	img;
	t_map	map;

	make_data(&img,&map);
	if (map.x * map.y != (map.count + map.x))
        return (printf("map format wrong"));
	img.img = mlx_new_image(img.mlx, 1920, 1080);
	mlx_win = mlx_new_window(img.mlx, img.x * map.x, img.y * map.y, "Hello world!");
	// mlx_xpm_file_to_image(img.mlx, "./assets/xpm/background.xpm", &img.x, &img.y);
	img.background = mlx_xpm_file_to_image(img.mlx, "./assets/xpm/background.xpm", &img.x, &img.x);
	mlx_put_image_to_window(img.mlx, mlx_win, img.background , 0, 0);
	img.background = mlx_xpm_file_to_image(img.mlx, "./assets/xpm/wall.xpm", &img.x, &img.x);
	mlx_put_image_to_window(img.mlx, mlx_win, img.background , 0, 0);
	mlx_loop(img.mlx);
	close(map.fd);
}