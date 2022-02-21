/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:00:06 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/21 12:46:20 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		map.mlx = mlx_init();
		printf("\n%p\n", map.mlx);
		if(map.mlx != 0)
		{
			map.name = argv[1];
			write(1,"0",1);
			verif_map_name(&map);
			write(1,"1",1);
			make_data(&map);
			write(1,"2",1);
			if (map.x * map.y != map.count
				|| map.flag > 1 || map.flag2 < 1 || map.flag3 < 1)
				error_map(&map);
			write(1,"3",1);
			make_array(&map);
			write(1,"4",1);
			map_checker(&map);
			write(1,"5",1);
			map.mlx_win = mlx_new_window(map.mlx, map.x_img * map.x,
					map.y_img * map.y, "SO_LONG");
			write(1,"6",1);
			if (!map.mlx_win)
				error(&map);
			write(1,"7",1);
			mlx_hook(map.mlx_win, 17, 0, close_win, &map);
			write(1,"8",1);
			mlx_hook(map.mlx_win, 2, 1L << 0, key_press, &map);
			write(1,"9",1);
			map_drawer(&map);
			write(1,"10",2);
			mlx_loop(map.mlx);
		}
		return(0);
	}
	return(0);
}

void	error_map(t_map *map)
{
	map->count = 0;
	printf("map wrong format\n");
	printf("Be sure to check\n\n");
	printf("that there is one player 'P'\n");
	printf("that the map is surrounded by '1'\n");
	printf("that there is at least one exit 'E'\n");
	printf("that there is at least one collectible 'C'\n");
	exit(0);
}

void	error(t_map *map)
{
	map->flag = 0;
	printf("ERROR");
	exit(0);
}
void	error_close(t_map *map)
{
	map->flag = 0;
	mlx_clear_window(map->mlx, map->mlx_win);
	mlx_destroy_window(map->mlx, map->mlx_win);
	printf("ERROR");
	exit(0);
}

void	verif_map_name(t_map *map)
{
	int	i;

	i = 0;
	while (map->name[i])
		i++;
	if (map->name[i - 1] != 'r' && map->name[i - 2] != 'e'
		&& map->name[i - 4] != 'b' && map->name[i - 4] != '.')
	{
		printf("the name format is wrong it must be .ber");
		exit(0);
	}
}
