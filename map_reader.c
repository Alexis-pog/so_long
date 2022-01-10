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

int get_y_x(char c);
{
	
}

char *get_simple(int fd)
{
	char buffer[2];
	static t_map map;

	map.r = NULL;
	if (fd < 0 || fd > FOPEN_MAX)
		return(NULL);
	map.n = read(fd, buffer, 1);
	map.x = 0;
	map.y = 0;
	if (buffer[0] != '\n' && map.y < 1)
	{
		map.x++;
		printf("%d",map.x);
	}
	if (buffer[0] == '\n')
	{	
		map.y++;
		printf("%d",map.y);
	}
	
	if (map.r)
	{
		free(map.r);
		map.r = NULL;
	}
	if (map.n > 0)
	{
		buffer[map.n] = '\0';
		map.r = ft_strjoin(map.r, buffer);
		return (map.r);
	}
	if (map.n == 0)
		return (map.r);
	if (map.n < 0)
		return (NULL);
	return (0);
}


int main()
{
	int fd;
	char *s;
	
	fd = open("test.ber", O_RDONLY);
	/*
	s = get_simple(fd);
	printf("%s",s);
	free(s);
	*/
	/*
	s = get_next_line(fd);
	printf("%s",s);
	free(s);
	*/
	
	s = get_simple(fd);
	printf("%s",s);
	free(s);
	
	while (s)
	{
		s = get_simple(fd);
		printf("%s",s);
		free(s);
	}
	close(fd);
}