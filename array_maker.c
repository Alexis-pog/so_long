/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:50:37 by acoquele          #+#    #+#             */
/*   Updated: 2022/01/28 13:54:20 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	use_data(t_map *map)
{
	char t_str[map->x];
	int y;

	map->x = 0;
	y = 0;
	map->fd = open("test.ber", O_RDONLY);
	map->tab = malloc(sizeof(char *) * (map->y + 1));
	printf("hello");
    
    if(!map->tab)
    {
		printf("this this exit");
        exit(0);
    }
    while(y < map->y)
	{
		while(t_str[map->x])
			{
            t_str[map->x++] = *get_simple(map->fd, map);
            printf("%c", map->tab[y][map->x]);
            }
		map->tab[y++] = ft_strdup(t_str);
		map->x = 0;
	}
}