/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:30:07 by jemustaj          #+#    #+#             */
/*   Updated: 2025/01/10 00:15:39 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int nb, char *base, int count)
{
	if (nb >= 16)
		count = ft_print_hex ((nb / 16), base, count);
	count += ft_print_c (base[nb % 16]);
	return (count);
}
