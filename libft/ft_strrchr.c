/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:57:19 by jemustaj          #+#    #+#             */
/*   Updated: 2024/12/01 20:43:42 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			chr;
	char			*res;

	chr = (char)c;
	res = NULL;
	while (*s)
	{
		if (*s == chr)
			res = ((char *)s);
		s++;
	}
	if (chr == '\0')
		res = (char *)s;
	return (res);
}
