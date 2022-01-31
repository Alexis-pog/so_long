#include "so_long.h"

void ft_free(char **ptr)
{
	free(&ptr);
	*ptr = NULL;
}

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
		if (buf[0] == '\n')
			map->y++;
		if (map->y == 0)
			map->x++;
		if (buf[0] != '\n' && buf[0] != '\0')
		map->count++;
	}
	return (line);
}

// int main()
// {
// 	int fd;
// 	char *s;
// 	t_map map;
// 	ft_memset(&map, 0, sizeof(t_map));
// 	fd = open("test.ber", O_RDONLY);
// 	s = malloc(1);
// 	// printf("%s",s);
// 	free(s);
// 	while (s)
// 	{
// 		s = get_simple(fd, &map);
// 		printf("%s",s);
// 		free(s);
// 	}
	
// 	printf(" %d ",map.y);
// 	printf(" %d ",map.x);
// 	printf(" %d ",map.count);
// 	printf(" %d ",map.x * map.y);
// 	if (map.x * map.y != (map.count))
//         return (printf("map format wrong"));
// 	close(fd);
// 	// printf("%d",map.x);
// 	use_data(&map);
// }

