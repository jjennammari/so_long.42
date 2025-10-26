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
	ft_putstr_fd("Args OK\n", 1);
	init_struct_variables(&monkey);
	get_matrix(&monkey, av[1]);
	ft_putstr_fd("Parsing works\n", 1);
	flood_fill(&monkey, monkey.p_pos_y, monkey.p_pos_x);
	validate_map_accessability(&monkey);
	ft_putstr_fd("Map is valid\n", 1);
	open_game_window(&monkey);
	ft_putstr_fd("Window opens OK\n", 1);
	init_img(&monkey);
	render_img(&monkey);
	ft_putstr_fd("Render OK\n", 1);
	key_movements(&monkey);
	ft_putstr_fd("Key movements work\n", 1);
	mlx_hook(monkey.window, 17, 0, handle_end, &monkey);
	ft_putstr_fd("2: Key movements work\n", 1);
	mlx_loop(monkey.mlx);
	ft_putstr_fd("Loop ok\n", 1);
	free_matrix(&monkey);
	return (0);
}
