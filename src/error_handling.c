/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 04:40:13 by jemustaj          #+#    #+#             */
/*   Updated: 2025/10/22 04:40:15 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_fd(t_matrix *arena, int fd)
{
	ft_putstr_fd("Error: failed to open the map file\n", 1);
	close(fd);
	exit(1);
}

void	error_malloc(t_matrix *arena, int fd)
{
	ft_putstr_fd("Error: malloc failed\n", 1);
	if (arena->map)
		free_matrix(arena);
	if (arena->map_copy)
		free_matrix(arena);
	close(fd);
	exit(1);
}

void	error_map_walls(t_matrix *arena, int fd)
{
	ft_putstr_fd("Error: map is not enclosed with walls\n", 1);
	free_matrix(arena);
	close(fd);
	exit(1);
}

void	free_matrix(t_matrix arena)
{
	int	y;

	y = 0;
	if (arena->map)
	{
		while (arena->map[y])
			free(arena->map[y++]);
		free(arena->map);
		arena->map = NULL;
	}
	y = 0;
	if (arena->map_copy)
	{
		while (arena->map_copy[y])
			free(arena->map_copy[y++]);
		free(arena->map_copy);
		arena->map_copy = NULL;
	}
}
