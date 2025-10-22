/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 04:41:03 by jemustaj          #+#    #+#             */
/*   Updated: 2025/10/22 04:41:04 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_matrix	arena;
	int	y;

	ft_putstr_fd("Starting program\n", 1);
	ft_putstr_fd("Checking args\n", 1);
	check_args(av[1], ac);
	ft_putstr_fd("Args OK\n", 1);
	init_matrix(&arena);
	get_matrix(&arena, av[1]);
	y = 0;
	while (arena.map[y])
	{
		printf("%s", arena.map[y]);
		y++;
	}
	ft_putstr_fd("Parsing works", 1);
//	flood_fill(&arena, arena.player.y, arena.player.x);
	return (0);
}
