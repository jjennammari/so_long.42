#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdio.h> // POISTA ENNEN PALAUTUSTA JA VAIHDA KAIKKI PRINTF FT_PRINTF
# include <stdlib.h> // for malloc, free, exit
# include <fcntl.h> // for open
# include <unistd.h> // for read, close
//# include "./libft/libft.h"

typedef struct	s_pos
{
	int	y;
	int	x;
}	t_pos;

typedef struct	s_matrix
{
	char	**map;
	char	**map_copy;
	int	map_hight;
	int	map_width;
	int	player_count;
	int	collect_count;
	int	exit_count;
	t_pos	player;
}	t_matrix;

// main.c
int main(int ac, char **av);

// check_args.c
void    check_args(char *av, int ac);
void    check_ac_amount(int ac);
void    check_file_extension(char *av);
void    check_if_directory(char *av);

// get_matrix.c
void    init_matrix(t_matrix *arena);
void    get_matrix(t_matrix *arena, char *av);
void    count_map_variables(t_matrix *arena, char *av);
void    create_matrix(t_matrix *arena, int fd);

// delete later
void    ft_putstr_fd(char *s, int fd);
size_t  ft_strlen(const char *s);
int ft_strncmp(const char *s1, const char *s2, size_t n);
// get_next_line.c
char	*extract_line(char *stash);
char	*get_next_line(int fd);
char	*read_to_stash(int fd, char *stash);
char	*update_stash(char *stash);
// get_next_line_utils.c
int		find_newline(char *str);
size_t	ft_strclen(char *str, char c);
char	*ft_strdup(const char *str);
char	*ft_strjoin(const char *str1, const char *str2);

// parsing.c
int	map_is_rectangular(t_matrix *arena, char *line);
void    count_gamepieces(t_matrix *arena, char *line);
void    check_gamepiece_amount(t_matrix *arena);
void    check_map_enclosed(t_matrix *arena);

// error_handling.c
void	error_fd(t_matrix *arena, int fd);
void	error_malloc(t_matrix *arena, int fd);
void	error_map_walls(t_matrix *arena, int fd);
void	free_matrix(t_matrix arena);

// flood_fill.c
//void    flood_fill(t_matrix *arena, int y, int x);

#endif
