/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:43:25 by acoquele          #+#    #+#             */
/*   Updated: 2022/01/31 16:57:55 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void make_map(t_map *map)
{
	map->x = 0;
	map->y = 0;
	map->tab = 0;
	map->count = 0;
}

void    make_data(t_data *img, t_map *map)
{
	img->x = 64;
	img->y = 64;
	img->mlx = mlx_init();
	map->fd = open(map->name, O_RDONLY);
	make_map(map);
	//printf("%s",map->name);
	map->s = malloc(1);
	free(map->s);
	while(map->s)
	{ 
		map->s = get_simple(map->fd, map);
		printf("%s",map->s);
		free(map->s);
	}
	close(map->fd);
}



// void	use_data(t_map *map)
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