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

//#include "cub.h"
#include "parsing.h"

static int	while_condition(t_cub *cub, char **map, int i, int j)
{
	while (ft_isspace(map[i][j]))
		j++;
	if (ft_isprint(map[i][j]) && !ft_isdigit(map[i][j]))
	{
		if (map[i][j + 1] && ft_isprint(map[i][j + 1]))
		{
			if (fill_textures(cub, map[i], j) == 0)
				return (print_msg("Error in textures", 0));
			return (3);
		}
		else
		{
			if (fill_color(cub, map[i], j) == 0)
				return (print_msg("Error in colors", 0));
			return (3);
		}
	}
	else if (ft_isdigit(map[i][j]))
	{
		if (fill_map(cub, map, i) == 0)
			return (print_msg("Error in map", 0));
		return (1);
	}
	return (2);
}

int	fill_info(t_cub *cub, char **map)
{
	int	i;
	int	j;
	int	stop;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			stop = while_condition(cub, map, i, j);
			if (stop == 3)
				break ;
			else if (stop == 1)
				return (1);
			else if (stop == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	parsing(t_cub *cub, char **argv)
{
	if (check_file(argv[1]) == 0)
		free_parsing(cub);
	parse_map(argv[1], cub);
	if (fill_info(cub, cub->map_info.file) == 0)
	{
		free_parsing(cub);
		return (0);
	}
	if (check_map(cub, cub->map) == 0)
	{
		free_parsing(cub);
		return (0);
	}
	if (check_texture(cub) == 0)
	{
		free_parsing(cub);
		return (0);
	}
	player_dir(cub);
	return (1);
}
