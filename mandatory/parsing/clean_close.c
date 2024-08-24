/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andie <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:51:31 by andie             #+#    #+#             */
/*   Updated: 2024/08/24 18:51:34 by andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub.h"
#include "parsing.h"

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

void	free_textures(t_cub *cub)
{
	if (cub->north_path)
	{
		free(cub->north_path);
		cub->north_path = NULL;
	}
	if (cub->south_path)
	{
		free(cub->south_path);
		cub->south_path = NULL;
	}
	if (cub->west_path)
	{
		free(cub->west_path);
		cub->west_path = NULL;
	}
	if (cub->east_path)
	{
		free(cub->east_path);
		cub->east_path = NULL;
	}
}

void	free_parsing(t_cub *cub)
{
	if (!cub)
		exit(1);
	if (cub->map_info.fd > 0)
		close(cub->map_info.fd);
	if (cub->map_info.file)
		free_tab((void **)cub->map_info.file);
	if (cub->map)
		free_tab((void **)cub->map);
	free_textures(cub);
	exit(1);
}
