/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:43:25 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/21 10:13:31 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	specific_val_reset(t_map *map)
{
	map->y = 0;
	map->x = 0;
	map->count = 0;
	map->x_img = 64;
	map->y_img = 64;
}

void	inv_size(t_map *map)
{
	map->n = 5;
	printf("map size not valid\n");
	exit(0);
}

void	reset_map_value(t_map *map)
{
	map->xx = 0;
	map->yy = 0;
	map->s = 0;
	map->fd = 0;
	map->flag3 = 0;
	map->flag2 = 0;
	map->flag = 0;
	map->e_x_val = 0;
	map->e_y_val = 0;
	map->p_y_val = 0;
	map->p_x_val = 0;
	map->col_val = 0;
	map->move_player = 1;
	map->n = 0;
}

void	make_data(t_map *map)
{
	reset_map_value(map);
	specific_val_reset(map);
	map->fd = open(map->name, O_RDONLY);
	if (!map->fd)
	{
		printf("please lauch the file again");
		exit(0);
	}
	map->s = malloc(1);
	if (!map->s)
		exit(0);
	free(map->s);
	while (map->s)
	{
		map->s = get_simple(map->fd, map);
		if (map->s)
			map->y++;
		free(map->s);
	}
	if (map->x > 41 || map->y > 20)
		inv_size(map);
	map->x--;
	close(map->fd);
}
/*
void	make_array(t_map *map)
{
	char t_str[map->x];
	int y;

	map->x = 0;
	y = 0;
	map->fd = open("test.ber", O_RDONLY);
	map->tab = malloc(sizeof(char *) * (map->y + 1));
	if(!map->tab)
		exit(0);
	while(y < map->y)
	{
		while(t_str[map->x])
			t_str[map->x++] = *get_simple(map->fd, map);
		map->tab[y++] = ft_strdup(t_str);
		map->x = 0;
	}
}
*/