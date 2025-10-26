/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:02:53 by jemustaj          #+#    #+#             */
/*   Updated: 2025/10/26 17:13:30 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	search_characters(t_matrix *monkey)
{
	int	y;
	int	x;

	y = 0;
	while (monkey->map[y])
	{
		x = 0;
		while (monkey->map[y][x])
		{
			if (check_correct(monkey->map[y][x]))
			{
				ft_putstr_fd("Error: invalid character in map\n", 1);
				free_matrix(monkey);
				exit(1);
			}
			x++;
		}
		y++;
	}
}

int	check_correct(char c)
{
	if ((c == '0') || (c == '1') || (c == 'C') || (c == 'E') || (c == 'P'))
		return (0);
	return (1);
}
