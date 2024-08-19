/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 00:41:51 by samusanc          #+#    #+#             */
/*   Updated: 2024/08/19 17:12:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
// this is your include file you can found it in Doom-Nukem/includes/
#include "parsing.h"

int	fill_info(t_cub *cub, char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			while (ft_isspace(map[i][j]))
				j++;
			if (ft_isalpha(map[i][j]))
			{
				if (map[i][j + 1] && isalpha(map[i][j + 1]))
				{
					if (fill_textures(cub, map[i], j) == 0)
						return (print_msg("Error in textures", 0));
					break ;
				}
				else
				{
					if (fill_color(cub, map[i], j) == 0)
						return (print_msg("Error in colors", 0));
					break ;
				}
			}
			else if (ft_isdigit(map[i][j]))
			{
				if (fill_map(cub, map, i, j) == 0)
					return (print_msg("Error in map", 0));
				return (1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	parsing(t_cub *cub, char **argv)
{
	if(check_file(argv[1]) == 0 && parse_map(cub, argv[1]) == 0)
		free_stuff(cub);
	if(fill_info(cub, cub->map_info.file) == 0)
	{
		free_stuff(cub);
		return (0);
	}
	if (check_map(cub, cub->map) == 0)
	{
		free_stuff(cub);
		return (0);
	}
	return (1);
}