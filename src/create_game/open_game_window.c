/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_game_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:58:56 by jemustaj          #+#    #+#             */
/*   Updated: 2025/10/25 19:48:22 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	open_game_window(t_matrix *monkey)
{
	int	w_y;
	int	w_x;

	w_y = monkey->map_y * TILE_SIZE;
	w_x = monkey->map_x * TILE_SIZE;
	monkey->mlx = mlx_init();
	monkey->window = mlx_new_window(monkey->mlx, w_x, w_y, "so_long");
}


void	init_img(t_matrix *monkey)
{
	monkey->wall = load_img(monkey, WALL_PATH);
	monkey->floor = load_img(monkey, FLOOR_PATH);
	monkey->exit = load_img(monkey, EXIT_CLOSED_PATH);
	monkey->collectable = load_img(monkey, COLLECTABLE_PATH);
	monkey->player = load_img(monkey, PLAYER_PATH);
}

void	*load_img(t_matrix *monkey, char *path)
{
	int	img_y;
	int	img_x;
	void	*img;

	img_y = TILE_SIZE;
	img_x = TILE_SIZE;
	img = mlx_xpm_file_to_image(monkey->mlx, path, &img_x, &img_y);
	return (img);
}
