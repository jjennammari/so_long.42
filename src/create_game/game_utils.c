/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 01:45:09 by jemustaj          #+#    #+#             */
/*   Updated: 2025/10/26 01:46:02 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	define_exit(t_matrix *monkey)
{
	if (monkey->c_counter == 0)
		end_game(monkey, "YaYY, Monkey can finally Climb !!\n");
	ft_putstr_fd("Keep collecting\n", 1);
}

void	update_exit_status(t_matrix *monkey, int new_y, int new_x)
{
	monkey->c_counter--;
	monkey->map[new_y][new_x] = '0';
	if (monkey->c_counter > 0 || monkey->exit_ready)
		return ;
	monkey->exit_ready = true;
	if (monkey->exit)
		mlx_destroy_image(monkey->mlx, monkey->exit);
	monkey->exit = mlx_xpm_file_to_image(monkey->mlx,
			EXIT_OPEN_PATH, &(int){TILE_SIZE}, &(int){TILE_SIZE});
	if (!monkey->exit)
		end_game(monkey, "Error: creating exit open\n");
	render_tile(monkey, monkey->e_pos_y, monkey->e_pos_x);
}
