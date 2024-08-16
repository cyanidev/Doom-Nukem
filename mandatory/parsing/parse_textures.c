/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 00:59:44 by andie             #+#    #+#             */
/*   Updated: 2024/08/16 02:52:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

char	*texture_path(char *line, int i)
{
	int		j;
	int		len;
	char	*texture_path;

	while (line[i] && ft_isspace_no_nl(line[i]))
		i++;
	len = i;
	while(line[len] && !ft_isspace_no_nl(line[len]))
		len++;
	path = malloc(sizeof(char) * (len - i + 1));
	if(path == NULL)
		return (NULL);
	j = 0;
	while (line[i] && !ft_isspace_no_nl(line[i]) && line[i] != '\n')
	{
		path[j] = line[i];
		i++;
		j++;
	}
	path[j] = '\0';
	/* unexpected content after path?? 
	while (line[i] && ft_isspace_no_nl(line[i]))
		i++;
	if (line[i] && line[i] != '\n')
	{
		free(path);
		return (NULL);
	}*/
	return (path);
}

int	fill_textures(t_cub *cub, char *line, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O')
		cub->north_path = texture_path(line, i + 2);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		cub->south_path = texture_path(line, i + 2);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		cub->west_path = texture_path(line, i + 2);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		cub->east_path = texture_path(line, i + 2);
	else
		return (0);
	return (1);
}

