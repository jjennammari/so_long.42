/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 23:45:23 by jemustaj          #+#    #+#             */
/*   Updated: 2025/01/09 22:37:48 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_print_c(int c);
int	ft_print_s(char *str);
int	ft_print_p(unsigned long long ptr, int count);
int	ft_print_di(int nb, int count);
int	ft_print_u(unsigned int nb, int count);
int	ft_print_hex(unsigned int nb, char *base, int count);

#endif
