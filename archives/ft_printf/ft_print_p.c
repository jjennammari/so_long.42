/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:54:37 by jemustaj          #+#    #+#             */
/*   Updated: 2025/01/09 22:42:02 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prt(unsigned long long ptr, int count);

int	ft_print_p(unsigned long long ptr, int count)
{
	if (ptr != '\0')
		count += write (1, "0x", 2);
	count = ft_prt (ptr, count);
	return (count);
}

int	ft_prt(unsigned long long ptr, int count)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (!ptr)
		return (count += ft_print_s ("(nil)"));
	if (ptr >= 16)
		count = ft_prt (ptr / 16, count);
	count += ft_print_c(hex[ptr % 16]);
	return (count);
}
