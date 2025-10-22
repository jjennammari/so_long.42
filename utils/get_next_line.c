/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:00:57 by jemustaj          #+#    #+#             */
/*   Updated: 2025/10/21 21:47:00 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*read_to_stash(int fd, char *stash);
char	*extract_line(char *stash);
char	*update_stash(char *stash);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = update_stash(stash);
	return (line);
}

char	*read_to_stash(int fd, char *stash)
{
	char	*buff;
	char	*temp;
	ssize_t	readed;

	if (!stash)
		stash = ft_strdup("");
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (free(stash), NULL);
	readed = 1;
	while (readed > 0 && !find_newline(stash))
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1)
			return (free(buff), free(stash), NULL);
		buff[readed] = '\0';
		temp = ft_strjoin(stash, buff);
		if (!temp)
			return (free(buff), free(stash), NULL);
		free(stash);
		stash = temp;
	}
	free(buff);
	return (stash);
}

char	*extract_line(char *stash)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	if (!stash || !stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	j = 0;
	i = 0;
	while (stash[i] && stash[i] != '\n')
		line[j++] = stash[i++];
	if (stash[i] == '\n')
		line[j++] = stash[i++];
	line[j] = '\0';
	return (line);
}

char	*update_stash(char *stash)
{
	size_t	pos;
	char	*new_stash;

	pos = ft_strclen(stash, '\n');
	if (stash[pos] == '\0')
	{
		free(stash);
		return (NULL);
	}
	pos++;
	new_stash = ft_strdup(stash + pos);
	free(stash);
	return (new_stash);
}
