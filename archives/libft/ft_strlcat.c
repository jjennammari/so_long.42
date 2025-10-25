/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:30:53 by jemustaj          #+#    #+#             */
/*   Updated: 2024/12/01 20:10:47 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	if (size < ft_strlen(dst))
		return (ft_strlen(src) + size);
	else
	{
		i = 0;
		while (dst[i])
			i++;
		ft_strlcpy(&dst[i], src, size - i);
		len = ft_strlen(src) + i;
		return (len);
	}
}
