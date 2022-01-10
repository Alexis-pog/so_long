/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: workplace <workplace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:06:37 by acoquele          #+#    #+#             */
/*   Updated: 2022/01/10 12:27:54 by workplace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./mlx/mlx.h"
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
    int x;
    int y;
    int n;
    char *r;
} t_map;


#endif