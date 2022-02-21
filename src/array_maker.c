/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:50:37 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/21 11:52:18 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_array(t_map *map)
{
	char	*s;

	map->tab = 0;
	// write(1,"0",1);
	map->tab = malloc(sizeof(char *) * (map->y + 1));
	if (!map->tab)
		exit (0);
	// write(1,"1",1);
	map->fd = open(map->name, O_RDONLY);
	// write(1,"2",1);
	s = malloc (1);
	// write(1,"3",1);
	free (s);
	while (s)
	{
		s = get_simple(map->fd, map);
		write(1,"4",1);
		map->tab[map->yy] = ft_strdup(s);
		// printf("%s",map->tab[map->yy]);
		write(1,"5",1);
		map->yy++;
		free(s);
	}
	map->tab[map->yy] = NULL;
	close(map->fd);
	printf("\n");
	// write(1,"7",1);
	// write(1,"8",1);
}

void	map_checker(t_map *map)
{	
	int	i;

	i = 0;
	while (i < map->x)
	{
		if (map->tab[0][i] != '1' && map->tab[map->y - 1][i] != '1')
		{	
			ft_free(map);
			error_map(map);
		}
		else
			i++;
	}
	i = 1;
	while (i < map->y - 1)
	{
		if (map->tab[i][0] != '1' && map->tab[i][map->x - 1] != '1')
		{
			ft_free(map);
			error_map(map);
		}
		else
			i++;
	}
}

void	map_drawer(t_map *map)
{	
	map->yy = 0;
	while (map->yy < map->y)
	{
		map->xx = 0;
		while (map->xx < map->x)
		{
			if (map->tab[map->yy][map->xx] == '1')
				draw_wall(map);
			else if (map->tab[map->yy][map->xx] == '0')
				draw_background(map);
			else if (map->tab[map->yy][map->xx] == 'P')
				draw_player(map);
			else if (map->tab[map->yy][map->xx] == 'C')
				draw_collectible(map);
			else if (map->tab[map->yy][map->xx] == 'E')
				draw_exit(map);
			map->xx++;
		}
		map->yy++;
	}
}

/*
void map_check(t_map *map)
{
	int x;
	int y;

	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if()
		}
		y++;
	}
}
if (map->tab[0][x] == '1' && map->tab[map->y][x] == '1')
	x++;
else
{ 
	printf("the wall is incomplete");
	exit(0);
}
x = 0;
y = 1;
while (1 < y - 1)
{	
	if (map->tab[y][0] = '1' &&  map->tab[y][map->x] = '1')
		y++;
	else
		error();
}

void error_wall(void)
{
	print("the wall is incomplete be sure to surround the map with 1 like this\n");
	printf("\n %d \n",map->x);
	printf("\n %d \n",map->y);
	red();
	printf("1111\n");
	printf("1");
	green();
	printf("xx");
	red();
	printf("1\n");
	printf("1");
	green();
	printf("xx");
	red();
	printf("1\n");
	printf("1111\n");
	reset();
}
*/