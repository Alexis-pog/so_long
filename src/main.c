/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:00:06 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/18 13:59:25 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		map.mlx = mlx_init();
		if (!map.mlx)
			error(&map);
		map.name = argv[1];
		verif_map_name(&map);
		make_data(&map);
		// printf("%d\n",map.x);
		// printf("%d\n",map.y);
		// printf("%d\n",map.flag);
		// printf("%d\n",map.flag2);
		// printf("%d\n",map.flag3);
		// printf("%d %d\n",map.count, map.x * map.y);
		if (map.x * map.y != map.count
			|| map.flag > 1 || map.flag2 < 1 || map.flag3 < 1)
		{
			printf("why");
			error_map(&map);
		}
		make_array(&map);
		map_checker(&map);
		map.mlx_win = mlx_new_window(map.mlx, map.x_img * map.x,
				map.y_img * map.y, "SO_LONG");
		if (!map.mlx_win)
			error(&map);
		mlx_hook(map.mlx_win, 17, 0, close_win, &map);
		mlx_hook(map.mlx_win, 2, 1L << 0, key_press, &map);
		map_drawer(&map);
		mlx_loop(map.mlx);
	}
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

void verif_map_name(t_map *map)
{
	int i;

	i = 0;
	while(map->name[i])
		i++;
	if (map->name[i - 1] != 'r' && map->name[i - 2] != 'e' && map->name[i - 4] != 'b' && map->name[i - 4] != '.')
	{
		printf("%c\n",map->name[i - 1]);
		printf("%c\n",map->name[i - 2]);
		printf("%c\n",map->name[i - 3]);
		printf("%c\n",map->name[i - 4]);
		printf("the name format is wrong it must be .ber");
		exit(0);
	}
}