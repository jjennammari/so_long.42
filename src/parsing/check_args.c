/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 04:39:58 by jemustaj          #+#    #+#             */
/*   Updated: 2025/10/22 04:43:44 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_args(char *av, int ac)
{
	check_ac_amount(ac);
	check_file_extension(av);
	check_if_empty(av);
}

void	check_ac_amount(int ac)
{
	if (ac != 2)
	{
		ft_putstr_fd("Error: launch with two args:\
		 ./so_long map_file.ber\n", 1);
		exit(1);
	}
}

void	check_file_extension(char *av)
{
	int	name_len;

	name_len = ft_strlen(av);
	if (name_len < 5 || av[name_len - 5] == '/')
	{
		ft_putstr_fd("Error: Missing file extension\n", 1);
		exit(1);
	}
	if (ft_strncmp(&av[name_len - 4], ".ber", 4) != 0)
	{
		ft_putstr_fd("Error: Using wrong file extension\n", 1);
		exit(1);
	}
}

void	check_if_empty(char *av)
{
	int		fd;
	char	*temp;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		error_fd(fd);
	temp = get_next_line(fd);
	if (!temp)
	{
		ft_putstr_fd("Error: map is empty\n", 1);
		close(fd);
		exit(1);
	}
	free(temp);
	while (temp)
	{
		temp = get_next_line(fd);
		free(temp);
	}
	close(fd);
}
