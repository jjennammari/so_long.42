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

#include "../../so_long.h"

void	init_struct_variables(t_matrix *monkey)
{
	monkey->map = NULL;
	monkey->map_cpy = NULL;
	monkey->map_y = 0;
	monkey->map_x = 0;
	monkey->p_pos_y = 0;
	monkey->p_pos_x = 0;
	monkey->e_pos_y = 0;
	monkey->e_pos_x = 0;
	monkey->p_amount = 0;
	monkey->p_counter = 0;
	monkey->c_amount = 0;
	monkey->c_counter = 0;
	monkey->e_amount = 0;
	monkey->e_counter = 0;
	monkey->mlx = NULL;
	monkey->window = NULL;
	monkey->floor = NULL;
	monkey->wall = NULL;
	monkey->exit = NULL;
	monkey->collectable = NULL;
	monkey->player = NULL;
	monkey->move_counter = 0;
	monkey->key_pressed = 0;
	monkey->exit_ready = false;
}

void	get_matrix(t_matrix *monkey, char *av)
{
	int	fd;

	count_map_variables(monkey, av);
	check_gamepiece_amount(monkey);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		error_fd(fd);
	monkey->map = malloc(sizeof(char *) * (monkey->map_y + 1));
	if (!monkey->map)
		error_malloc(monkey, fd);
	monkey->map[monkey->map_y] = NULL;
	monkey->map_cpy = malloc(sizeof(char *) * (monkey->map_y + 1));
	if (!monkey->map_cpy)
		error_malloc(monkey, fd);
	monkey->map_cpy[monkey->map_y] = NULL;
	create_matrix(monkey, fd);
	if (check_map_enclosed(monkey))
		error_map_walls(monkey, fd);
	close(fd);
}

void	count_map_variables(t_matrix *monkey, char *av)
{
	char	*temp;
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		error_fd(fd);
	temp = get_next_line(fd);
	monkey->map_x = ft_strlen(temp); 
	while (temp)
	{
		if (!(map_is_rectangular(monkey, temp)))
		{
			ft_putstr_fd("Error: map is not rectangular\n", 1);
			free(temp);
			close(fd);
			exit(1);
		}
		count_gamepiece_amount(monkey, temp, monkey->map_y);
		free(temp);
		monkey->map_y++;
		temp = get_next_line(fd);
	}
	close(fd);
}

void	count_gamepiece_amount(t_matrix *monkey, char *line, int y)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] == 'C')
			monkey->c_amount++;
		else if (line[x] == 'E')
		{
			monkey->e_amount++;
			monkey->e_pos_y = y;
			monkey->e_pos_x = x;
		}
		else if (line[x] == 'P')
		{
			monkey->p_amount++;
			monkey->p_pos_y = y; 
			monkey->p_pos_x = x;
		}
		x++;
	}
}

void	create_matrix(t_matrix *monkey, int fd)
{
	int	y;
	char	*line;
	char	*temp;

	y = 0;
	while (y < monkey->map_y)
	{
		line = get_next_line(fd);
		if (!line)
			error_malloc(monkey, fd);
		monkey->map[y] = line;
		monkey->map_cpy[y] = ft_strdup(monkey->map[y]);
		y++;
	}
	temp = get_next_line(fd);
	if (!temp)
		free(temp);
}
