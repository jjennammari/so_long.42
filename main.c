/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 23:12:02 by jemustaj          #+#    #+#             */
/*   Updated: 2025/10/19 20:07:04 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		parsing(av[1]);
	}
	else
		printf("Launch with two args: ./so_long and map_file"); // vaihda ft_printf
	return (0);
}
