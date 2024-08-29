/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maincito.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:03:11 by andie             #+#    #+#             */
/*   Updated: 2024/08/19 17:19:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

void init_player(t_player *player)
{
	player->dir = '\0';
	player->x = 0.0;
	player->y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
}

void init_info(t_map_info *map_info)
{
	map_info->fd = 0;
	map_info->lines = 0;
	map_info->path = NULL;
	map_info->file = NULL;
	map_info->height = 0;
	map_info->width = 0;
	map_info->index_end_of_map = 0;
}

int init_parsing_info(t_cubp *cubp)
{
	cubp->north_path = NULL;
	cubp->south_path = NULL;
	cubp->east_path = NULL;
	cubp->west_path = NULL;
	cubp->map = NULL;
//
	cubp->floor = 0;
	cubp->ceiling = 0;
	cubp->x_floor = 0x0;
	cubp->x_ceiling = 0x0;
//
	init_player(&cubp->player);
	init_info(&cubp->map_info);
	return (1);
}

void fill_structure(t_cub *cub, t_cub *cubp)
{
	cub->north_path = cubp->north_path;
	cub->south_path = cubp->south_path;
	cub->east_path = cubp->east_path;
	cub->west_path = cubp->west_path;
	cub->map = cubp->map;
//
	cub->floor = cubp->floor;
	cub->ceiling = cubp->ceiling;
	cub->x_floor = cubp->x_floor;
	cub->x_ceiling = cubp->x_ceiling;
}

//for testing purposes
int parsingmap(char **argv, t_cub *cub)
{
	t_cubp cubp;

	init_parsing_info(&cubp);
	if (parsing(&cubp, argv) == 0)
		return (0);
	fill_structure(cub, &cubp);
	printf("everything is ok\n");
	return (1);
}