/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:24:08 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/03 13:19:34 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void map_maker_modif(t_map *map)
{	
	map->yy = 0;
	while(map->yy < map->y)
		{
		map->xx = 0;
		map->count = 0;
		printf("hello");
		while(map->xx < map->x)
		{
			if (map->tab[map->yy][map->xx] == '1')
			{
				printf("X");
				
			}
			if (map->tab[map->yy][map->xx] == '0')
			{
				printf("O");	
			}
			if (map->tab[map->yy][map->xx] == '\n')
			{
				printf("\n");				
			}
			if (map->tab[map->yy][map->xx] == 'E')
			{
				printf("G");
			}
			if (map->tab[map->yy][map->xx] == 'P')
			{
				printf("D");
			}
			if (map->tab[map->yy][map->xx] == 'C')
			{
				printf("E");
			}
			map->xx++;
			map->count++;
		}
		map->yy++;
		map->count2++;
	}
}
