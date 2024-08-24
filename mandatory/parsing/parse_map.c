/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 00:35:37 by andie             #+#    #+#             */
/*   Updated: 2024/08/21 18:35:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub.h"
#include "parsing.h"

static int	file_lines(char *path)
{
	int		count;
	int		fd;
	char	*line;

	count = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (print_msg(strerror(errno), errno));
	while ((line = get_next_line(fd)) != NULL)
	{
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

static void	fill_tab(int row, int column, int i, t_cub *cub)
{
	char	*line;

	while ((line = get_next_line(cub->map_info.fd)) != NULL)
	{
		cub->map_info.file[row] = calloc((ft_strlen(line) + 1), sizeof(char));
		if (cub->map_info.file[row] == NULL)
		{
			print_msg("Malloc failed", 1);
			free_tab((void **)cub->map_info.file);
			return ;
		}
		while (line[i] != '\0')
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

void	parse_map(char *path, t_cub *cub)
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
	{
		print_msg("Malloc failed", 1);
		return ;
	}
	cub->map_info.fd = open(path, O_RDONLY);
	if (cub->map_info.fd == -1)
	{
		print_msg(strerror(errno), 1);
		return ;
	}
	fill_tab(row, column, i, cub);
	close(cub->map_info.fd);
}
