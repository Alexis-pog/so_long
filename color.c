/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:19:18 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/14 16:19:20 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void red () {
  printf("\033[1;31m");
}

void reset () {
  printf("\033[0m");
}

void green() {
  printf("\033[1;32m");
}