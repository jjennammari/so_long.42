/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:07:52 by jemustaj          #+#    #+#             */
/*   Updated: 2025/10/19 22:03:22 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parsing(char *map)
{
	check_map_name(map);
	get_map(map);
}

void	check_map_name(char *map)
{
	char *file_extencion;
	int	i;
	int	name_len;

	file_extencion = ".ber";
	name_len = (count_len(map) - 1);
	i = 3;
	while (i >= 0)
	{
		if (file_extencion[i] != map[name_len])
		{
			printf("Wrong file extencion");
			exit(1);
		}
		i--;
		name_len--;
	}
	if (map[name_len] == '/' || map[name_len] == ' ')
	{
		printf("No file extencion");
		exit(1);
	}
	return ;
}

void	get_map(char *str)
{
	
}
