/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andie <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 00:32:01 by andie             #+#    #+#             */
/*   Updated: 2024/08/25 00:32:04 by andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_player(t_cub *cub, char **map)
{
	int	y;
	int	x;

	y = 0;
	cub->player.dir = '0';
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x])
		{
			while (ft_isspace_no_nl(map[y][x]))
				x++;
			if (!(ft_strchr("10NSEW", map[y][x])))
				return (print_msg("Error: invalid character in map", 0));
			if (ft_strchr("NSEW", map[y][x]) && cub->player.dir != '0')
				return (print_msg("Error: more than one player", 0));
			if (ft_strchr("NSWE", map[y][x]) && cub->player.dir == '0')
				cub->player.dir = map[y][x];
			x++;
		}
		y++;
	}
	return (1);
}

int	valid_pos(t_cub *cub, char **map)
{
	int	y;
	int	x;

	y = (int)cub->player.plane_y;
	x = (int)cub->player.plane_x;
	if (ft_strlen(map[y - 1]) < (size_t)x
		|| ft_strlen(map[y + 1]) < (size_t)x
		|| ft_isspace(map[y][x - 1]) || ft_isspace(map[y][x + 1])
		|| ft_isspace(map[y - 1][x]) || ft_isspace(map[y + 1][x]))
		return (0);
	return (1);
}

int	replace_player_with_floor(t_cub *cub, char **map)
{
	int	y;
	int	x;

	if (cub->player.dir == '0')
		return (print_msg("Error: player not found", 0));
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NSWE", map[y][x]))
			{
				cub->player.plane_y = (double)y + 0.5;
				cub->player.plane_x = (double)x + 0.5;
				map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	if (valid_pos(cub, map) == 0)
		return (print_msg("Error: invalid player position", 0));
	return (1);
}
