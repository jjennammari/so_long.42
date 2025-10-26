/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 01:44:42 by jemustaj          #+#    #+#             */
/*   Updated: 2025/10/26 01:44:59 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	handle_end(t_matrix *monkey)
{
	end_game(monkey, NULL);
	return (0);
}

void	end_game(t_matrix *monkey, char *message)
{
	if (message)
		ft_printf("%s\n", message);
	if (monkey->map || monkey->map_cpy)
		free_matrix(monkey);
	destroy_game(monkey);
	exit(1);
}

void	destroy_game(t_matrix *monkey)
{
	if (monkey->wall)
		mlx_destroy_image(monkey->mlx, monkey->wall);
	if (monkey->floor)
		mlx_destroy_image(monkey->mlx, monkey->floor);
	if (monkey->player)
		mlx_destroy_image(monkey->mlx, monkey->player);
	if (monkey->collectable)
		mlx_destroy_image(monkey->mlx, monkey->collectable);
	if (monkey->exit)
		mlx_destroy_image(monkey->mlx, monkey->exit);
	if (monkey->mlx)
	{
		mlx_destroy_display(monkey->mlx);
		free(monkey->mlx);
	}
}
