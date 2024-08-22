/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:46:23 by andie             #+#    #+#             */
/*   Updated: 2024/08/18 00:24:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub.h"
#include "parsing.h"

static int map_lines(t_cub *cub, char **file, int i)
{
	int ival;
	int j;
	int count;

	count = 0;
	ival = i;
	while (file[i])
	{
		j = 0;
		while (ft_isspace_no_nl(file[i][j]))
			j++;
		if (file[i][j] != '1')
			break ;
		i++;
	}
	cub->map_info.index_end_of_map = i;
	count = i - ival;
	return (count);
}

static int longest_line(t_map_info *map_info, int i)
{
	size_t longest;

	longest = ft_strlen(map_info->file[i]);
	while (map_info->file[i])
	{
		if (ft_strlen(map_info->file[i]) > longest)
			longest = ft_strlen(map_info->file[i]);
		i++;
	}
	return (longest);
}

static int	map_alloc_width(t_map_info *map_info, char **map, int i)
{
	int j;
	int k;

	j = 0;
	k = 0;
	map_info->width = longest_line(map_info, i);
	while (j < map_info->height)
	{
		k = 0;
		map[j] = malloc(sizeof(char) * (map_info->width + 1));
		if (!map[j])
			return (print_msg("Malloc failed", 0));
		while (map_info->file[i][k] && map_info->file[i][k] != '\n')
		{
			map[j][k] = map_info->file[i][k];
			k++;
		}
		while (k < map_info->width)
			map[j][k++] = '\0';
		i++;
		j++;
	}
	return (1);
}

static int	map_alloc_height(t_cub *cub, char **file, int i)
{
	cub->map_info.height = map_lines(cub, file, i);
	cub->map = malloc(sizeof(char *) * (cub->map_info.height + 1));
	if (cub->map == NULL)
		return (print_msg("Malloc failed", 0));
	if (map_alloc_width(&cub->map_info, cub->map, i) == 0)
		return (0);
	return (1);
}

static void	change_space_to_empty(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while(cub->map[i])
	{
		j = 0;
		while (ft_isspace_no_nl(cub->map[i][j]))
			j++;
		while (cub->map[i][++j])
		{
			if (cub->map[i][j] == ' ' && j != cub->map[i][ft_strlen(cub->map[i]) - 1])
				cub->map[i][j] = 'X';
		}
		i++;
	}
}

int	fill_map(t_cub *cub, char **file, int i)
{
	if (map_alloc_height(cub, file, i) == 0)
		return (0);
	change_space_to_empty(cub);
	return (1);
}