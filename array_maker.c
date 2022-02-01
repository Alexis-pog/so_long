/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:50:37 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/01 11:34:45 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	use_data(t_map *map)
{
	printf("\n");
	reset_map_value(map);
	map->tab = malloc(sizeof(char *) * (map->y + 1));
    if(!map->tab)
        exit(0);
	map->fd = open(map->name, O_RDONLY);
    map->s = malloc(1);
    free(map->s);
	while (map->s)
	{
		map->s = get_simple(map->fd, map);
		map->tab[map->yy] = ft_strdup(map->s);
		printf("%s",map->tab[map->yy]);
		map->yy++;
		free(map->s);
	}
	close(map->fd);
}

/*
void map_drawer(t_map *map, t_data *img)
{
	int y;
	int x;

	
}
*/






// void map_check(t_map *map)
// {
// 	int x;
// 	int y;

// 	while (y < map->y)
// 	{
// 		x = 0;
// 		while (x < map->x)
// 		{
// 			if()
// 		}
// 		y++;
// 	}
// }
//if (map->tab[0][x] == '1' && map->tab[map->y][x] == '1')
//	x++;
//else
//{ 
//	printf("the wall is incomplete");
// 	exit(0);
//}
//x = 0;
//y = 1;
// while (1 < y - 1)
// {	
// 	if (map->tab[y][0] = '1' &&  map->tab[y][map->x] = '1')
// 		y++;
// 	else
// 		error();
// }

// void error_wall(void)
// {
// 	print("the wall is incomplete be sure to surround the map with 1 like this\n");
// 	printf("\n %d \n",map->x);
// 	printf("\n %d \n",map->y);
// 	red();
// 	printf("1111\n");
// 	printf("1");
// 	green();
// 	printf("xx");
// 	red();
// 	printf("1\n");
// 	printf("1");
// 	green();
// 	printf("xx");
// 	red();
// 	printf("1\n");
// 	printf("1111\n");
// 	reset();
// }

