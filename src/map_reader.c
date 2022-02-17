/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:58:09 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/17 13:58:35 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	area_hight(t_map *map, char *buf)
{
	if (buf[0] != '\n' && buf[0] != '\0' && buf[0] != ' ')
		map->count++;
	else if (buf[0] == '0' || buf[0] == 'E' || buf[0] == 'P')
		map->count++;
	else if (buf[0] == '1' || buf[0] == 'C')
		map->count++;
	if (buf[0] == 'P')
		map->flag++;
	if (buf[0] == 'E')
		map->flag2++;
	if (buf[0] == 'C')
		map->flag3++;
	if (map->y == 0)
		map->x++;
}

char	*get_simple(int fd, t_map *map)
{
	char	buf[2];
	char	*line;
	int		n;

	line = NULL;
	while (1)
	{
		n = read(fd, buf, 1);
		buf[1] = '\0';
		line = ft_strjoin(line, buf);
		if (n == -1)
			return (NULL);
		if (n == 0)
		{
			if (n == 0 && buf[0] == 0)
			{
				free(line);
				return (NULL);
			}
			return (line);
		}
		area_hight(map, buf);
		if (buf[0] == '\n')
			return (line);
	}
	if (n == 0)
		return (NULL);
	return (0);
}
/*
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
		if (s)
			map.y++;
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
	make_array(&map);
	// write(1,"pussy",5);
	map.yy = 0;
	write(1,"\n",1);
	while (map.tab[map.yy])
	{
		// write(1,map.tab[map.yy],ft_strlen(map.tab[map.yy]));
		printf("%s",map.tab[map.yy]);
		map.yy++;
	}
	// printf("\n%s\n",map.tab[0]);
	print_array(&map);
	map_maker_modif(&map);
}
*/
