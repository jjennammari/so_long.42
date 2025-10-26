/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 19:32:30 by jemustaj          #+#    #+#             */
/*   Updated: 2025/10/25 19:49:41 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	render_img(t_matrix *monkey)
{
	int	y;
	int	x;

	mlx_clear_window(monkey->mlx, monkey->window);
	y = 0;
	while (y < monkey->map_y)
	{
		x = 0;
		while (x < monkey->map_x)
		{
			render_tile(monkey, y, x);
			x++;
		}
		y++;
	}
}

void	render_tile(t_matrix *monkey, int y, int x)
{
	if (monkey->map[y][x] == '0')
		put_img_to_window(monkey, monkey->floor, y, x);
	else if (monkey->map[y][x] == '1')
		put_img_to_window(monkey, monkey->wall, y, x);
	else if (monkey->map[y][x] == 'P')
		put_img_to_window(monkey, monkey->player, y, x);
	else if (monkey->map[y][x] == 'C')
		put_img_to_window(monkey, monkey->collectable, y, x);
	else if (monkey->map[y][x] == 'E')
		put_img_to_window(monkey, monkey->exit, y, x);
}

void	put_img_to_window(t_matrix *monkey, void *img, int y, int x)
{
	mlx_put_image_to_window(monkey->mlx, monkey->window, img, x * TILE_SIZE, y * TILE_SIZE);
}
