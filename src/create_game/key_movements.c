/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_movements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 01:34:58 by jemustaj          #+#    #+#             */
/*   Updated: 2025/10/26 01:37:33 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	key_movements(t_matrix *monkey)
{
	mlx_hook(monkey->window, 2, 1L << 0, key_press, &monkey);
	mlx_hook(monkey->window, 3, 1L << 1, key_release, &monkey);
}

int	key_press(int keycode, t_matrix *monkey)
{
	if (monkey->key_pressed)
		return (0);
	monkey->key_pressed = 1;
	if (keycode == KEY_ESC)
		end_game(monkey, NULL);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(monkey, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(monkey, 0, +1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(monkey, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(monkey, 1, 0);
	else
		monkey->key_pressed = 0;
	return (0);
}

int	key_release(int keycode, t_matrix *monkey)
{
	if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D
		|| keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
		monkey->key_pressed = 0;
	return (0);
}

void	move_player(t_matrix *monkey, int dir_x, int dir_y)
{
	int		new_x;
	int		new_y;
	char	next_tile;

	new_x = monkey->p_pos_x + dir_x;
	new_y = monkey->p_pos_y + dir_y;
	if (new_x < 0 || new_x >= monkey->map_x
		|| new_y < 0 || new_y >= monkey->map_y)
		return ;
	next_tile = monkey->map[new_y][new_x];
	if (next_tile == '1')
		return ;
	if (next_tile == 'E' && monkey->c_counter > 0)
		return ;
	if (next_tile == 'E')
		handle_exit(monkey);
	else if (next_tile == 'C')
		handle_collectibles(monkey, new_x, new_y);
	update_player_position(monkey, new_x, new_y, dir_x);
}

void	update_player_position(t_matrix *monkey, int new_x, int new_y, int dir_x)
{
	int		old_x;
	int		old_y;
	char	*moves_terminal;

	old_x = monkey->p_pos_x;
	old_y = monkey->p_pos_y;
	monkey->map[old_y][old_x] = '0';
	monkey->map[new_y][new_x] = 'P';
	monkey->p_pos_x = new_x;
	monkey->p_pos_y = new_y;
	monkey->move_counter++;
	render_tile(monkey, old_x, old_y);
	render_tile(monkey, new_x, new_y);
	moves_terminal = ft_itoa(monkey->move_counter);
	if (moves_terminal)
	{
		ft_printf("Moves: %s \n", moves_terminal);
		free(moves_terminal);
	}
}
