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
# include "./archives/ft_printf/ft_printf.h"
# include "./archives/get_next_line/get_next_line.h"
# include "./archives/minilibx-linux/mlx.h"

# define FLOOR_PATH "textures/floor.xpm"
# define WALL_PATH "textures/wall.xpm"
# define EXIT_OPEN_PATH "textures/exit_open.xpm"
# define EXIT_CLOSED_PATH "textures/exit_closed.xpm"
# define COLLECTABLE_PATH "textures/collectable.xpm"
# define PLAYER_PATH "textures/player.xpm"

# define TILE_SIZE 32
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

typedef struct s_matrix
{
	char	**map;
	char	**map_cpy;
	int		map_y;
	int		map_x;
	int		p_pos_y;
	int		p_pos_x;
	int		e_pos_y;
	int		e_pos_x;
	int		p_amount;
	int		p_counter;
	int		c_amount;
	int		c_counter;
	int		e_amount;
	int		e_counter;
	void	*mlx;
	void	*window;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*player;
	void	*collectable;
	int		move_counter;
	bool	key_pressed;
	bool	exit_ready;
}	t_matrix;

// main.c
int		main(int ac, char **av);

// check_args.c
void	check_args(char *av, int ac);
void	check_ac_amount(int ac);
void	check_file_extension(char *av);//TODO: check wrong file extension
void	check_if_empty(char *av);

// create_matrix.c
void	init_struct_variables(t_matrix *monkey);
void	get_matrix(t_matrix *monkey, char *av);
void	count_map_variables(t_matrix *monkey, char *av);
void	count_gamepiece_amount(t_matrix *monkey, char *line, int y);
void	create_matrix(t_matrix *monkey, int fd);

// validate_map.c
int		map_is_rectangular(t_matrix *monkey, char *line);
void	check_gamepiece_amount(t_matrix *monkey);//NOTE: added some matrix frees
int		check_map_enclosed(t_matrix *monkey);
void	flood_fill(t_matrix *monkey, int y, int x);
void	validate_map_accessability(t_matrix *monkey);

// error_handling.c
void	handle_gnl(char *temp, int fd);
void	error_fd(int fd);
void	error_malloc(t_matrix *monkey, int fd);
void	error_map_walls(t_matrix *monkey, int fd);
void	free_matrix(t_matrix *monkey);

// open_game_window.c
void	open_game_window(t_matrix *monkey);
void	init_img(t_matrix *monkey);
void	*load_img(t_matrix *monkey, char *path);

// render_img.c
void	render_img(t_matrix *monkey);
void	render_tile(t_matrix *monkey, int y, int x);
void	put_img_to_window(t_matrix *monkey, void *img, int y, int x);

// key_movements.c
void	key_movements(t_matrix *monkey);
int		key_press(int keycode, t_matrix *monkey);
int		key_release(int keycode, t_matrix *monkey);//TODO: undifined end_game
void	move_player(t_matrix *monkey, int dir_y, int dir_x);
void	update_p_pos(t_matrix *monkey, int new_y, int new_x);

// game_utils.c
void	define_exit(t_matrix *monkey);
void	update_exit_status(t_matrix *monkey, int new_y, int new_x);

// end_game.c
int		handle_end(t_matrix *monkey);
void	end_game(t_matrix *monkey, char *message);
void	destroy_game(t_matrix *monkey);

#endif
