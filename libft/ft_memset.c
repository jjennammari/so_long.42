/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:11:05 by jemustaj          #+#    #+#             */
/*   Updated: 2024/11/18 22:13:30 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*setchar;

	setchar = (unsigned char *)s;
	i = 0;
	while (i < n)
		setchar[i++] = (unsigned char)c;
	return (s);
}
