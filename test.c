/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:24:08 by acoquele          #+#    #+#             */
/*   Updated: 2022/01/31 15:35:20 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	use_data(t_map *map)
// {
// 	char t_str[map->x];
// 	int y;

// 	printf("hello");
// 	map->x = 0;
// 	y = 0;
// 	map->fd = open("test.ber", O_RDONLY);
// 	map->tab = malloc(sizeof(char *) * (map->y));
// 	if(!map->tab)
// 		exit(0);
// 	while(y < map->y)
// 	{
// 		// printf("%d",y);
// 		while(t_str[map->x])
// 		{
// 			t_str[map->x++] = *get_simple(map->fd, map);
// 		}
// 		map->tab[y++] = ft_strdup(t_str);
// 		printf("%s", map->tab[y]);
// 		map->x = 0;
// 	}
// }

// char *strjoin_modif(char *str, char buffer)
// {
// 	int index;
// 	char *new;
// 	index = 0;

// 	while(str && str[index])
// 		index++;
// 	new = malloc(index + 2);
// 	index = 0;
// 	while(str && str[index])
// 	{
// 		new[index] = str[index];
// 		index++;
// 	}
// 	if (str)
// 		free(str);
// 	new[index++] = buffer;
// 	new[index] = '\0';
// 	return (new);
// }

// char *get_simple_2(int fd, t_map *map)
// {
// 	int ret;
// 	char *line;
// 	char buf[1];

// 	ret = 1;
// 	line = 0;
// 	while((ret && buf[0] != '\n') || buf[0] != '\0')
// 	{
// 		ret = read(fd, buf, 1);
// 		if (!ret || ret == -1)
// 			return (line);
// 		line = strjoin_modif(line, buf[0]);
// 		if (buf[0] == '\n')
// 			map->y++;
// 		if (map->y == 0)
// 			map->x++;
// 		if (buf[0] != '\n')
// 		map->count++;
// 	}
// 	return (line);
// }

// int main()
// {
// 	t_map map;

// 	map.x = 0;
// 	map.y = 0;
// 	map.count = 0;
// 	int fd = open("test.ber", O_RDONLY);
// 	char *line;
// 	while ((line = get_simple_2(fd, &map)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = NULL;
// 	}
// 	printf("\n%d\n%d\n%d\n",map.y, map.x, map.count);
// 	return (0);
// }

// void hello_there(t_map *map)
// {
//     int fd;
//     fd = open(map->name, O_RDONLY);
//     printf("%d",fd);
// }

// int main(int argc, char **argv)
// {
//     t_map map;

//     if (argc == 2)
//     {    
//         map.name = argv[1];
//         hello_there(&map);   
//     }
//     return (0);
// }
