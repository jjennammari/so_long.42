/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:38:36 by jemustaj          #+#    #+#             */
/*   Updated: 2025/01/09 20:04:12 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(unsigned int nb, int count)
{
	if (nb >= 10)
		count += ft_print_u (nb / 10, count);
	count += ft_print_c (nb % 10 + '0');
	return (count);
}
