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
		end_game(monkey, "Okay fine, see ya!\n");
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(monkey, -1, 0);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(monkey, +1, 0);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(monkey, 0, 1);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(monkey, 0, 1);
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

void	move_player(t_matrix *monkey, int dir_y, int dir_x)
{
	int		new_x;
	int		new_y;
	char	next_tile;

	new_y = monkey->p_pos_y + dir_y;
	new_x = monkey->p_pos_x + dir_x;
	if (new_y < 0 || new_y >= monkey->map_x
		|| new_x < 0 || new_x >= monkey->map_y)
		return ;
	next_tile = monkey->map[new_y][new_x];
	if (next_tile == '1')
		return ;
	if (next_tile == 'E' && monkey->c_counter > 0)
		return ;
	if (next_tile == 'E')
		define_exit(monkey);
	else if (next_tile == 'C')
		update_exit_status(monkey, new_y, new_x);
	update_p_pos(monkey, new_y, new_x);
}

void	update_p_pos(t_matrix *monkey, int new_y, int new_x)
{
	int		old_x;
	int		old_y;
	char	*moves_terminal;

	old_y = monkey->p_pos_y;
	old_x = monkey->p_pos_x;
	monkey->map[old_y][old_x] = '0';
	monkey->map[new_y][new_x] = 'P';
	monkey->p_pos_x = new_y;
	monkey->p_pos_y = new_x;
	monkey->move_counter++;
	render_tile(monkey, old_y, old_x);
	render_tile(monkey, new_y, new_x);
	moves_terminal = ft_itoa(monkey->move_counter);
	if (moves_terminal)
	{
		ft_printf("Moves: %s \n", moves_terminal);
		free(moves_terminal);
	}
}
