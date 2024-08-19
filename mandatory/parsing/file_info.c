/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 00:35:37 by andie             #+#    #+#             */
/*   Updated: 2024/08/17 19:10:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

static void	init_mapinfo(t_mapinfo *map_info)
{
	map_info->fd = 0;
	map_info->lines = 0;
	map_info->height = 0;
	map_info->width = 0;
	map_info->index_end_of_map = 0;
	map_info->path = NULL;
	map_info->file = NULL;
}

static int file_lines(char *path)
{
	int		count;
	int		fd;
	char	*line;

	count = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((line = get_next_line(fd)) != NULL)
	{
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

static void fill_tab(int row, int column, int i, t_cub *cub)
{
	char	*line;

	while ((line = get_next_line(cub->map_info.fd)) != NULL)
	{
		cub->map_info.file[row] = calloc((ft_strlen(line) + 1), sizeof(char));
		if (cub->map_info.file[row] == NULL)
			return (print_msg("Malloc failed", 0));//tab needs to be freeded before return
		while(line[i] != '\0')
		{
			cub->map_info.file[row][column] = line[i];
			column++;
			i++;
		}
		cub->map_info.file[row][column] = '\0';
		row++;
		column = 0;
		i = 0; 
		free(line);
	}
	cub->map_info.file[row] = NULL;
}

int	parse_map(char *path, t_cub *cub)
{
	int	i;
	int	row;
	int	column;

	i = 0;
	row = 0;
	column = 0;
	cub->map_info.lines = file_lines(path);
	cub->map_info.path = path;
	cub->map_info.file = calloc(cub->map_info.lines + 1, sizeof(char *));
	if (cub->map_info.file == NULL)
		return (print_msg("Malloc failed", 0));
	cub->map_info.fd = open(path, O_RDONLY);
	if (cub->map_info.fd == -1)
		return (print_msg("Failed to open file", 0));
	fill_tab(row, column, i , cub);
	close(cub->map_info.fd);
	return (1);
}