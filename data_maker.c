/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:43:25 by acoquele          #+#    #+#             */
/*   Updated: 2022/01/13 17:34:57 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    make_data(t_data *img, t_map *map)
{
    img->x = 64;
    img->y = 64;
    img->mlx = mlx_init();
    map->fd = open("test.ber", O_RDONLY);
    map->s = malloc(1);
    map->x = 0;
    map->y = 0;
    free(map->s);
	while(map->s)
	{ 
		map->s = get_simple(map->fd, map);
		printf("%s",map->s);
		free(map->s);
	}
}