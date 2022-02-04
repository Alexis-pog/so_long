/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:58:09 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/04 15:14:29 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


char *strjoin_modif(char *str, char buffer)
{
	int index;
	char *new;
	index = 0;

	while(str && str[index])
		index++;
	new = malloc(index + 2);
	index = 0;
	while(str && str[index])
	{
		new[index] = str[index];
		index++;
	}
	if (str)
		free(str);
	new[index++] = buffer;
	new[index] = '\0';
	return (new);
}

char *get_simple(int fd, t_map *map)
{
	int ret;
	char *line;
	char buf[1];

	ret = 1;
	line = 0;
	//printf("\n%d\n", map->count);
	while((ret && buf[0] != '\n') || buf[0] != '\0')
	{
		ret = read(fd, buf, 1);
		if (!ret || ret == -1)
			return (line);
		line = strjoin_modif(line, buf[0]);
		if (buf[0] == '\n' && map->flag == 0)
			map->y++;
		if (map->y == 0 && map->flag == 0)
			map->x++;
		if (buf[0] != '\n' && buf[0] != '\0' && map->flag == 0)
		map->count++;
	}
	return (line);
}

int main()
{
	int fd;
	char *s;
	t_map map;
	ft_memset(&map, 0, sizeof(t_map));
	fd = open("test.ber", O_RDONLY);
	s = malloc(1);
	// printf("%s",s);
	free(s);
	while (s)
	{
		s = get_simple(fd, &map);
		printf("%s",s);
		free(s);
	}
	
	printf(" %d ",map.y);
	printf(" %d ",map.x);
	printf(" %d ",map.count);
	printf(" %d ",map.x * map.y);
	if (map.x * map.y != (map.count))
        return (printf("map format wrong"));
	close(fd);
	map.flag++;
	use_data(&map);
	write(1,"pussy",5);
	map.yy = 0;
	write(1,"\n",1);
	while (map.tab[map.yy])
	{
		write(1,map.tab[map.yy],ft_strlen(map.tab[map.yy]));
		//printf("\n%s",map.tab[map.yy]);
		map.yy++;
	}
	printf("\n%s\n",map.tab[0]);
	print_array(&map);
}

