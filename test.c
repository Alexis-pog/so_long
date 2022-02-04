/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:24:08 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/04 15:29:20 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void map_maker_modif(t_map *map)
{	
	map->yy = 0;
	write(1,"hello",5);
	while(map->yy < map->y)
		{
		map->xx = 0;
		map->count = 0;
		
		while(map->xx < map->x)
		{
			if (map->tab[map->yy][map->xx] == '1')
			{
				printf("X");
			}
			else if (map->tab[map->yy][map->xx] == '0')
			{
				printf("O");	
			}
			else if (map->tab[map->yy][map->xx] == '\n')
			{
				printf("\n");				
			}
			else if (map->tab[map->yy][map->xx] == 'E')
			{
				printf("G");
			}
			else if (map->tab[map->yy][map->xx] == 'P')
			{
				printf("D");
			}
			else if (map->tab[map->yy][map->xx] == 'C')
			{
				printf("E");
			}
			map->xx++;
			map->count++;
		}
		map->yy++;
	}
}


void print_array(t_map *map)
{
	printf("\n 3 time printing the array \n");
	map->yy = 0;
	map->xx = 0;
	int i = 1;
	write(1,"\n",1);
	while (map->tab[map->yy])
	{
		printf("%s : %d\n",map->tab[map->yy], i++);
		map->yy++;
	}
}