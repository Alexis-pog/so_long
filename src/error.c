/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:18:18 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/22 10:24:05 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
