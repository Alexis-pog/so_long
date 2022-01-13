#include "so_long.h"

void ft_free(char **ptr)
{
	free(&ptr);
	*ptr = NULL;
}


char *get_simple(int fd, t_map *map)
{
	char buffer[2];

	map->r = NULL;
	if (fd < 0 || fd > FOPEN_MAX)
		return(NULL);
	map->n = read(fd, buffer, 1);
	if (buffer[0] == '\n' || buffer[0] == '\0')
		map->y++;
	if (map->r)
		free(map->r);
	if (map->n > 0)
	{
		buffer[map->n] = '\0';
		map->r = ft_strjoin(map->r, buffer);
		if (buffer[0] != '\n')
			map->count++;
	}
	if (map->y == 0)
		map->x++;
	if(map->n == 0)
		return (map->r);
	if (map->n < 0 || buffer[0] == ' ')
		return (NULL);
	return (map->r);
}
/*
int main()
{
	int fd;
	char *s;
	t_map map;
	fd = open("test2.ber", O_RDONLY);
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
	printf(" %d ",map.x + map.count);
	if (map.x * map.y != (map.count + map.x))
        return (printf("map format wrong"));
	// printf("%d",map.x);
	get_x_y(&map);
	
	close(fd);
}
*/
