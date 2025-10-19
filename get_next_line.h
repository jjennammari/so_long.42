/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:52:00 by jemustaj          #+#    #+#             */
/*   Updated: 2025/02/13 21:40:08 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>  // open flags
# include <stdlib.h> // free, malloc
# include <unistd.h> // open, read

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
size_t	ft_strlen(const char *str);

#endif
