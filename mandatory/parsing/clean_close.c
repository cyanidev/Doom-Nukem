/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 03:23:23 by andie             #+#    #+#             */
/*   Updated: 2024/08/19 17:10:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

void free_tab(void **tab)
{
	int i;

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

void free_textures(t_cub *cub)
{
	if (cub->north_path)
		free(cub->north_path);
	if (cub->south_path)
		free(cub->south_path);
	if (cub->west_path)
		free(cub->west_path);
	if (cub->east_path)
		free(cub->east_path);
	cub->north_path = NULL;
	cub->south_path = NULL;
	cub->west_path = NULL;
	cub->east_path = NULL;
}

void free_all(t_cub cub)
{
	if (cub->map_info.fd > 0)
		close(cub->map_info.fd);
	if (cub->map_info.file)
		free_tab((void **)cub->map_info.file);
	if (cub->map)
		free_tab((void **)cub->map);
	free_textures(cub);
	
	
}

