/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:18:37 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/21 19:11:57 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_map *map)
{
	while (map->y >= 0)
		free(map->tab[map->y--]);
	free(map->tab);
}

int	close_win(t_map *map)
{
	ft_free(map);
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit(0);
}

void	esc(t_map *map)
{
	close_win(map);
	exit(0);
}
