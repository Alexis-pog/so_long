/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_file2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:02:44 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/22 10:24:27 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_img(t_map *map)
{
	map->background = mlx_xpm_file_to_image(map->mlx,
			"./assets/xpm/background.xpm", &map->x_img, &map->x_img);
	map->wall = mlx_xpm_file_to_image(map->mlx,
			"./assets/xpm/wall.xpm", &map->x_img, &map->x_img);
	map->exit = mlx_xpm_file_to_image(map->mlx,
			"./assets/xpm/door_closed.xpm", &map->x_img, &map->x_img);
	map->collectible = mlx_xpm_file_to_image(map->mlx,
			"./assets/xpm/collectible.xpm", &map->x_img, &map->x_img);
	map->player = mlx_xpm_file_to_image(map->mlx,
			"./assets/xpm/hero.xpm", &map->x_img, &map->x_img);
}

int	ft_strlen_modif(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\n')
		i++;
	return (i);
}

char	*ft_strdup_modif(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	if (!(char *)s1)
		return (NULL);
	s2 = malloc(sizeof(char) * (ft_strlen_modif((char *)s1) + 1));
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
