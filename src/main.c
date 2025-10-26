/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 04:41:03 by jemustaj          #+#    #+#             */
/*   Updated: 2025/10/25 13:20:38 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	t_matrix	monkey;

	ft_putstr_fd("Starting program\n", 1);
	check_args(av[1], ac);
	init_struct_variables(&monkey);
	get_matrix(&monkey, av[1]);
	search_characters(&monkey);
	flood_fill(&monkey, monkey.p_pos_y, monkey.p_pos_x);
	validate_map_accessability(&monkey);
	open_game_window(&monkey);
	init_img(&monkey);
	render_img(&monkey);
	key_movements(&monkey);
	mlx_hook(monkey.window, 17, 0, handle_end, &monkey);
	mlx_loop(monkey.mlx);
	free_matrix(&monkey);
	return (0);
}
