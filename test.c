/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:24:08 by acoquele          #+#    #+#             */
/*   Updated: 2022/01/12 11:22:15 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_x_y(t_map *map)
{
	char tab[map->y][map->x];
	int x;
	int y;

	y = 0;
	x = 0;
	printf("\n");
	
	while(y < map->y)
	{
		x = 0;
		while(x < map->x)
		{	
			tab[y][x] = 'h';
			printf("%c",tab[y][x]);
			x++;
			if (x == map->x)
				printf("\n");
		}
		y++;
	}	
}
