/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:43:25 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/16 17:11:52 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void specific_val_reset(t_map *map)
{
	map->y = 0;
	map->x = 0;
	map->count = 0;
}

void too_big()
{
	red();
	printf("map too big\n");
	reset();
	exit(0);
}
void reset_map_value(t_map *map)
{
	map->xx = 0;
	map->yy = 0;
	map->s = 0;
	map->fd = 0;
	map->flag2 = 0;
	map->flag = 0;
	map->e_x_val = 0;
	map->e_y_val = 0;
	map->p_y_val = 0;
	map->p_x_val = 0;
	map->col_val = 0;
	map->move_player = 1;
}

void    make_data(t_map *map)
{
	map->x_img = 64;
	map->y_img = 64;
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
	while(map->s)
	{ 
		map->s = get_simple(map->fd, map);
		// printf("%s",map->s);
		if (map->s)
			map->y++;
		free(map->s);
	}
	if (!map->x || !map->y)
	{
		printf("this is an error");
		exit(0);
	}
	if (map->x > 41 || map->y > 20)
		too_big();
	map->x--;
	close(map->fd);
}




// void	make_array(t_map *map)
// {
// 	char t_str[map->x];
// 	int y;

// 	map->x = 0;
// 	y = 0;
// 	map->fd = open("test.ber", O_RDONLY);
// 	map->tab = malloc(sizeof(char *) * (map->y + 1));
// 	if(!map->tab)
// 		exit(0);
// 	while(y < map->y)
// 	{
// 		while(t_str[map->x])
// 			t_str[map->x++] = *get_simple(map->fd, map);
// 		map->tab[y++] = ft_strdup(t_str);
// 		map->x = 0;
// 	}
// }