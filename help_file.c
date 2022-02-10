/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:08:43 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/09 17:15:18 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void    *ft_memset(void *str, int c, int n)
{
    int    count;

    count = -1;
    while (++count < n)
    {
        *(unsigned char *)(str + count) = (unsigned char)c;
    }
    return (str);
}

void reset_map_value(t_map *map)
{
	map->xx = 0;
	map->yy = 0;
	map->s = 0;
	map->fd = 0;
}