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

#include "../../so_long.h"

void	error_fd(int fd)
{
	ft_putstr_fd("Error: failed to open the map file\n", 1);
	close(fd);
	exit(1);
}

void	error_malloc(t_matrix *monkey, int fd)
{
	ft_putstr_fd("Error: malloc failed\n", 1);
	if (monkey->map)
		free_matrix(monkey);
	if (monkey->map_cpy)
		free_matrix(monkey);
	close(fd);
	exit(1);
}

void	error_map_walls(t_matrix *monkey, int fd)
{
	ft_putstr_fd("Error: map is not enclosed with walls\n", 1);
	free_matrix(monkey);
	close(fd);
	exit(1);
}

void	free_matrix(t_matrix *monkey)
{
	int	y;

	y = 0;
	if (monkey->map)
	{
		while (y < monkey->map_y)
			free(monkey->map[y++]);
		free(monkey->map);
		monkey->map = NULL;
	}
	y = 0;
	if (monkey->map_cpy)
	{
		while (y < monkey->map_y)
			free(monkey->map_cpy[y++]);
		free(monkey->map_cpy);
		monkey->map_cpy = NULL;
	}
}
