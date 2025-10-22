/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 04:41:10 by jemustaj          #+#    #+#             */
/*   Updated: 2025/10/22 04:43:40 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_is_rectangular(t_matrix *arena, char *line)
{
	int	x;

	if (!line)
		return (1);
	x = ft_strlen(line);
	if (arena->map_width != x)
		return (0);
	return (1);
}

void	count_gamepieces(t_matrix *arena, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			arena->collect_counter++;
		else if (line[i] == 'E')
			arena->exit_counter++;
		else if (line[i] == 'P')
			arena->player_counter++;
		i++;
	}
}

void	check_gamepiece_amount(t_matrix *arena)
{
	if (arena->player_counter < 1 || arena->player_counter > 1)
		// TODO: error handling
	if (arena->collect_counter < 1)
		// TODO: error handling
	if (arena->exit_counter < 1 || arena->exit_counter > 1)
		// TODO: error handling
}

int	check_map_enclosed(t_matrix *arena)
{
	int	y;
	int	x;

	x = 0;
	while (x < arena->map_width)
	{
		if ((arena->map[0][x] != '1') || (arena->map[arena->map_hight - 1][x] != '1'))
		{
			ft_putstr_fd("Error: map is not enclosed with walls", 1);
			return (1);
		}
		x++;
	}
	y = 0;
	while (y < arena->map_hight)
	{
		if ((arena->map[y][0] != '1') || (arena->map[y][arena->map_width - 1] != '1'))
		{
			ft_putstr_fd("Error: map is not enclosed with walls", 1);
			return (1);
		}
		y++;
	}
	return (0);
}
