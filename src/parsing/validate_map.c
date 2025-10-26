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

#include "../../so_long.h"

int	map_is_rectangular(t_matrix *monkey, char *line)
{
	int	x;

	if (!line)
		return (1);
	x = ft_strlen(line);
	if (monkey->map_x != x)
		return (0);
	return (1);
}

void	check_gamepiece_amount(t_matrix *monkey)
{
	if (monkey->p_amount != 1)
	{
		ft_putstr_fd("Error: incorrect amount of players\n", 1);
		if (monkey->map || monkey->map_cpy)
			free_matrix(monkey);
		exit(1);
	}
	if (monkey->c_amount < 1)
	{
		ft_putstr_fd("Error: no collectables\n", 1);
			free_matrix(monkey);
		exit(1);
	}
	if (monkey->e_amount != 1)
	{
		ft_putstr_fd("Error: incorrect amount of exits\n", 1);
			free_matrix(monkey);
		exit(1);
	}
}

int	check_map_enclosed(t_matrix *monkey)
{
	int	y;
	int	x;

	x = 0;
	while (x < monkey->map_x)
	{
		if ((monkey->map[0][x] != '1') ||
			(monkey->map[monkey->map_y - 1][x] != '1'))
			return (1);
		x++;
	}
	y = 0;
	while (y < monkey->map_y)
	{
		if ((monkey->map[y][0] != '1') ||
			(monkey->map[y][monkey->map_x - 1] != '1'))
			return (1);
		y++;
	}
	return (0);
}

void	flood_fill(t_matrix *monkey, int y, int x)
{
	if (y < 0 || x < 0 || y >= monkey->map_y || x >= monkey->map_x)
		return ;
	if (monkey->map_cpy[y][x] == '1' || monkey->map_cpy[y][x] == 'F')
		return ;
	if (monkey->map_cpy[y][x] == 'E')
		monkey->e_counter++;
	if (monkey->map_cpy[y][x] == 'P')
		monkey->p_counter++;
	if (monkey->map_cpy[y][x] == 'C')
		monkey->c_counter++;
	monkey->map_cpy[y][x] = 'F';
	flood_fill(monkey, y - 1, x);
	flood_fill(monkey, y + 1, x);
	flood_fill(monkey, y, x - 1);
	flood_fill(monkey, y, x + 1);
}

void	validate_map_accessability(t_matrix *monkey)
{
	if (monkey->e_amount != monkey->e_counter)
	{
		ft_putstr_fd("Error: exit is not accessable\n", 1);
		free_matrix(monkey);
		exit(1);
	}
	if (monkey->p_amount != monkey->p_counter)
	{
		ft_putstr_fd("Error: player is not accessable\n", 1);
		free_matrix(monkey);
		exit(1);
	}
	if (monkey->c_amount != monkey->c_counter)
	{
		ft_putstr_fd("Error: all collectables are not accessable\n", 1);
		free_matrix(monkey);
		exit(1);
	}
}
