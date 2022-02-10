/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:50:37 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/09 17:26:35 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	use_data(t_map *map)
{
	char *s;
	// printf("\nsecond time the map is written\n");
	map->tab = 0;
	map->tab = malloc(sizeof(char *) * (map->y + 1));
    if(!map->tab)
        exit(0);
	map->fd = open(map->name, O_RDONLY);
    s = malloc(1);
    free(s);
	while (s)
	{
		s = get_simple(map->fd, map);
		map->tab[map->yy] = ft_strdup(s);
		// printf("%s",map->tab[map->yy]);
		map->yy++;
		free(s);
	}
	map->tab[map->yy] = NULL;
	close(map->fd);
}


void map_drawer(t_map *map)
{	
	map->yy = 0;
	while(map->yy < map->y)
	{
		map->xx = 0;
		map->count = 0;
		while(map->xx < map->x)
		{
			if (map->tab[map->yy][map->xx] == '1')
			{
				map->background = mlx_xpm_file_to_image(map->mlx, "./assets/xpm/background.xpm", &map->x_img, &map->x_img);
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->background , map->x_img * map->xx, map->y_img * map->yy);
				map->background = mlx_xpm_file_to_image(map->mlx, "./assets/xpm/wall.xpm", &map->x_img, &map->x_img);
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->background , map->x_img * map->xx, map->y_img * map->yy);
			}
			if (map->tab[map->yy][map->xx] == '0')
			{
				map->background = mlx_xpm_file_to_image(map->mlx, "./assets/xpm/background.xpm", &map->x_img, &map->x_img);
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->background , map->x_img * map->xx, map->y_img * map->yy);
			}
			if (map->tab[map->yy][map->xx] == 'P')
			{
				map->background = mlx_xpm_file_to_image(map->mlx, "./assets/xpm/background.xpm", &map->x_img, &map->x_img);
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->background , map->x_img * map->xx, map->y_img * map->yy);
				map->background = mlx_xpm_file_to_image(map->mlx, "./assets/xpm/hero.xpm", &map->x_img, &map->x_img);
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->background , map->x_img * map->xx, map->y_img * map->yy);
			}
			if (map->tab[map->yy][map->xx] == 'C')
			{
				map->background = mlx_xpm_file_to_image(map->mlx, "./assets/xpm/background.xpm", &map->x_img, &map->x_img);
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->background , map->x_img * map->xx, map->y_img * map->yy);
				map->background = mlx_xpm_file_to_image(map->mlx, "./assets/xpm/collectible.xpm", &map->x_img, &map->x_img);
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->background , map->x_img * map->xx, map->y_img * map->yy);
			}
			if (map->tab[map->yy][map->xx] == 'E')
			{
				map->background = mlx_xpm_file_to_image(map->mlx, "./assets/xpm/background.xpm", &map->x_img, &map->x_img);
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->background , map->x_img * map->xx, map->y_img * map->yy);
				map->background = mlx_xpm_file_to_image(map->mlx, "./assets/xpm/door_open.xpm", &map->x_img, &map->x_img);
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->background , map->x_img * map->xx, map->y_img * map->yy);
			}
			map->xx++;
			map->count++;
		}
		map->yy++;
	}
		
}





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

