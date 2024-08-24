/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:27:11 by andie             #+#    #+#             */
/*   Updated: 2024/08/19 03:13:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub.h"
#include "parsing.h"

static int	map_end(t_cub *cub)
{
	int	y;
	int	x;

	y = cub->map_info.index_end_of_map;
	while (cub->map_info.file[y])
	{
		x = 0;
		while (cub->map_info.file[y][x])
		{
			if (!(ft_isspace(cub->map_info.file[y][x])))
				return (print_msg("Error: ", 0));
			x++;
		}
		y++;
	}
	return (1);
}

static int	check_top_bottom(char **map_tab, int i, int j)
{
	if (!map_tab || !map_tab[i] || !map_tab[i][j])
		return (0);
	while (ft_isspace_no_nl(map_tab[i][j]))
		j++;
	while (map_tab[i][j])
	{
		if (map_tab[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	map_sides(t_map_info *map_info, char **map)
{
	int	y;
	int	x;

	if (check_top_bottom(map, 0, 0) == 0)
		return (0);
	y = 1;
	while (y < (map_info->height - 1))
	{
		x = ft_strlen(map[y]) - 1;
		if (map[y][x] != '1')
			return (0);
		y++;
	}
	if (check_top_bottom(map, y, 1) == 0)
		return (0);
	return (1);
}

int	check_map(t_cub *cub, char **map)
{
	if (!cub->map)
		return (print_msg("Error: no map", 0));
	if (map_sides(&cub->map_info, map) == 0)
		return (print_msg("Error: map is not surrounded by walls", 0));
	if (cub->map_info.width < 3 || cub->map_info.height < 3)
		return (print_msg("Error: map is too small", 0));
	if (check_player(cub, map) == 0)
		return (print_msg("Error: player not found or more than one", 0));
	if (replace_player_with_floor(cub, map) == 0)
		return (print_msg("Error: player not found or more than one", 0));
	if (map_end(cub) == 0)
		return (print_msg("Error: ", 0));
	return (1);
}
