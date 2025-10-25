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
	int	y;

	ft_putstr_fd("Starting program\n", 1);
	check_args(av[1], ac);
	ft_putstr_fd("Args OK\n", 1);
	init_struct_variables(&monkey);
	get_matrix(&monkey, av[1]);
	y = 0;
	while (monkey.map[y])
	{
		printf("%s", monkey.map[y]);
		y++;
	}
	ft_putstr_fd("Parsing works", 1);
	flood_fill(&monkey, monkey.p_pos_y, monkey.p_pos_x);
	validate_map_accessability(&monkey);
	ft_putstr_fd("Map is valid\n", 1);
	return (0);
}
