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

#include "cub.h"

staitc int	check_player(t_cub *cub, char **map)
{
	int	y;
	int	x;

	y = 0;
	cub->player->dir = '0';
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x])
		{
			while(ft_isspace_no_nl(map[y][x]))
				j++;
			if (!(ft_strchr("10NSEW", map[y][x])))
				return (print_msg("Error: invalid character in map", 0));
			if (ft_strchr("NSEW", map[y][x]) && cub->player->dir != '0')
				return (print_msg("Error: more than one player", 0));
			if (ft_strchr("NSWE"), map[y][x] && cub->player->dir == '0')
				cub->player->dir = map[y][x];
			x++;
		}
		y++;
	}
	return (1);
}

static int valid_pos(map, int y, int x)
{
	if (ft_isspace(map[y][x - 1]) || ft_isspace(map[y][x + 1])
		|| ft_isspace(map[y - 1][x]) || ft_isspace(map[y + 1][x]))
		return (0);
	return (1);
}

static int	replace_player_with_floor(t_cub *cub, char **map)
{
	int	y;
	int	x;

	if (cube->player->dir == '0')
		return (print_msg("Error: player not found", 0));
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NSWE", map[y][x]))
			{
				if (valid_pos(map, y, x) == 0)
					return (print_msg("Error: invalid player position", 0));	
				map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	return (1);
}

static int map_end(t_cub *cub)
{
	int y;
	int x;

	y = cub->map_info.index_end_of_map;
	while (cub->map_info->file[y])
	{
		x = 0;
		while (cub->map_info->file[y][x])
		{
			if (!(ft_isspace(cub->map_info->file[y][x])))
				return (print_msg("Error: ", 0));
			x++;
		}
		y++;
	}
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