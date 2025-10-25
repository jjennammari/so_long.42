/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:53:47 by jemustaj          #+#    #+#             */
/*   Updated: 2024/12/01 18:47:52 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_len(long nbl)
{
	int	count;

	count = 0;
	if (nbl <= 0)
	{
		count++;
	}
	while (nbl != 0)
	{
		nbl /= 10;
		count++;
	}
	return (count);
}

static char	*calloc_mem(int len)
{
	char	*str;

	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*result;
	long	nbl;

	nbl = n;
	len = ft_len(nbl);
	result = calloc_mem(len);
	if (!result)
		return (NULL);
	if (n == 0)
		result[0] = '0';
	if (nbl < 0)
		nbl *= -1;
	i = len - 1;
	while (nbl != 0)
	{
		result[i] = ((nbl % 10) + '0');
		nbl /= 10;
		i--;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
