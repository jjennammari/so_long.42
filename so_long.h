/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 13:19:19 by jemustaj          #+#    #+#             */
/*   Updated: 2025/10/25 13:31:39 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h> // for malloc, free, exit
# include <fcntl.h> // for open
# include <unistd.h> // for read, close
# include <stdbool.h>
# include "./archives/libft/libft.h"
# include "./archives/ft_printf/ft_printf.h"// TODO: delete ft_printf before submit
# include "./archives/get_next_line/get_next_line.h"
//# include "./archives/minilibx-linux/mlx.h"

typedef struct	s_matrix
{
	char	**map;
	char	**map_cpy;
	int	map_y;
	int	map_x;
	int	p_pos_y;
	int	p_pos_x;
	int	p_amount;
	int	p_counter;
	int	c_amount;
	int	c_counter;
	int	e_amount;
	int	e_counter;
}	t_matrix;

// main.c
int main(int ac, char **av);

// check_args.c
void    check_args(char *av, int ac);
void    check_ac_amount(int ac);
void    check_file_extension(char *av);
void	check_if_empty(char *av);

// create_matrix.c
void    init_struct_variables(t_matrix *monkey);
void    get_matrix(t_matrix *monkey, char *av);
void    count_map_variables(t_matrix *monkey, char *av);
void    count_gamepiece_amount(t_matrix *monkey, char *line, int y);
void    create_matrix(t_matrix *monkey, int fd);

// validate_map.c
int	map_is_rectangular(t_matrix *monkey, char *line);
void    check_gamepiece_amount(t_matrix *monkey);
int    check_map_enclosed(t_matrix *monkey);
void	flood_fill(t_matrix *monkey, int y, int x);
void	validate_map_accessability(t_matrix *monkey);

// error_handling.c
void	error_fd(int fd);
void	error_malloc(t_matrix *monkey, int fd);
void	error_map_walls(t_matrix *monkey, int fd);
void	free_matrix(t_matrix *monkey);

#endif
