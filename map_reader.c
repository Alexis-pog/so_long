#include "so_long.h"
/*
void ft_free(char **ptr)
{
	free(&ptr);
	*ptr = NULL;
}
*/
int ft_strlen(char *c)
{
	int i;

	i = 0;
	while(c[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	if (!(char *)s1)
		return (NULL);
	s2 = malloc(sizeof(char) * (ft_strlen((char *)s1) + 1));
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*main_str;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (!s1)
		return (ft_strdup(s2));
	main_str = malloc(sizeof(char)
			* (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (!main_str)
		return (NULL);
	while (s1 && s1[i])
	{
		main_str[i] = s1[i];
		i++;
	}
	while (s2 && s2[i2])
		main_str[i++] = s2[i2++];
	main_str[i] = '\0';
	return (main_str);
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
	{
		free(map->r);
		map->r = NULL;
	}
	if (map->n > 0)
	{
		buffer[map->n] = '\0';
		map->r = ft_strjoin(map->r, buffer);
		map->x++;
		return (map->r);
	}
	if (map->n == 0)
		return (map->r);
	if (map->n < 0)
		return (NULL);
	return (0);
}

int main()
{
	int fd;
	char *s;
	t_map map;
	fd = open("test.ber", O_RDONLY);
	s = get_simple(fd, &map);
	printf("%s",s);
	free(s);
	while (s)
	{
		s = get_simple(fd, &map);
		printf("%s",s);
		free(s);
	}
	map.x = map.x/map.y;
	// printf("%d",map.x);
	printf("\n");
	printf(" %d ",map.y);
	printf(" %d ",map.x);
	printf("\n");
	get_x_y(&map);
	
	close(fd);
}

