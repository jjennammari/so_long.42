/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:06:47 by jemustaj          #+#    #+#             */
/*   Updated: 2025/10/22 04:43:56 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_matrix(t_matrix *arena)
{
	arena->map = NULL;
	arena->map_copy = NULL;
	arena->map_hight = 0;
	arena->map_width = 0;
	arena->player_count = 0;
	arena->collect_count = 0;
	arena->exit_count = 0;
}

void	get_matrix(t_matrix *arena, char *av)
{
	int	fd;

	count_map_size(arena, av);
	check_gamepiece_amount(arena);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		error_fd(arena, fd);
	arena->map = malloc(sizeof(char *) * (arena->map_hight + 1));
	if (!map)
		error_malloc(arena, fd);
	arena->map_copy = malloc(sizeof(char *) * (arena->map_hight + 1));
	if (!arena->map_copy)
		error_malloc(arena, fd);
	create_matrix(arena, fd);
	if (check_map_enclosed(arena))
		error_map_walls(arena, fd);
	close(fd);
}

void	count_map_variables(t_matrix *arena, char *av)
{
	char	*temp;
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		error_fd(arena, fd);
	temp = get_next_line(fd);
	arena->map_width = ft_strlen(temp); 
	while (temp)
	{
		if (!(map_is_rectangular(arena, temp)))
		{
			ft_putstr_fd("Error: map is not rectangular\n", 1);
			free(temp);
			close(fd);
			exit(1);
		}
		count_gamepieces(arena, temp);
		free(temp);
		arena->map_hight++;
		temp = get_next_line(fd);
	}
	close(fd);
}

void	create_matrix(t_matrix *arena, int fd)
{
	int	y;
	char	*line;

	y = 0;
	while (y < arena->map_width)
	{
		line = get_next_line(fd);
		arena->map[y] = line;
		arena->map_copy[y] = ft_strdup(arena->map[y]);
		y++;
	}
	// NOTE: should I free line here ? prob no cause it frees the og line ?
}
