/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:00:06 by acoquele          #+#    #+#             */
/*   Updated: 2022/01/07 17:48:50 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		x_axis;
	int		y_axis;
	int		endian;
}				t_data;

int	main(void)
{
	char *path_xpm;
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	img.x_axis = 32;
	img.y_axis = 32;
	path_xpm = "./assets/full_tile.png";
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_png_file_to_image(mlx, path_xpm, &img.x_axis, &img.y_axis);
	mlx_put_image_to_window(mlx, mlx_win, &img.img , 0, 0);
	mlx_loop(mlx);
}