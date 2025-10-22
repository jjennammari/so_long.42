/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 04:40:40 by jemustaj          #+#    #+#             */
/*   Updated: 2025/10/22 04:40:42 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_matrix *arena, int y, int x)
{
	if (y < 0 || x < 0 || y >= arena->map_hight || x >= arena->map_width)
		return ;
	if (arena->map_copy[y][x] == 1 || arena->map_copy[y][x] == 'F')
		return ;
	arena->map_temp[y][x] = 'F';
	flood_fill(arena->map_temp, y - 1, x);
	flood_fill(arena->map_temp, y + 1, x);
	flood_fill(arena->map_temp, y, x - 1);
	flood_fill(arena->map_temp, y, x + 1);
}
