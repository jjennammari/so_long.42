/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:26:50 by jemustaj          #+#    #+#             */
/*   Updated: 2025/02/13 22:19:00 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strclen(char *str, char c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*dest;
	size_t	str_len;
	size_t	i;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	dest = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*dest;
	size_t	dest_size;
	size_t	i;
	size_t	j;

	if (!str1 && !str2)
		return (NULL);
	if (!str1)
		return (ft_strdup(str2));
	if (!str2)
		return (ft_strdup(str1));
	dest_size = ft_strlen((char *)str1) + ft_strlen((char *)str2);
	dest = (char *)malloc(sizeof(char) * (dest_size + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i])
		dest[j++] = str1[i++];
	i = 0;
	while (str2[i])
		dest[j++] = str2[i++];
	dest[j] = '\0';
	return (dest);
}
