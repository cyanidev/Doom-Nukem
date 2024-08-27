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

//#include "cub.h"
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

int init_parsing_info(t_cub *cub)
{
	cub->north_path = NULL;
	cub->south_path = NULL;
	cub->east_path = NULL;
	cub->west_path = NULL;
	cub->map = NULL;
//
	cub->floor = 0;
	cub->ceiling = 0;
	cub->x_floor = 0x0;
	cub->x_ceiling = 0x0;
//
	init_player(&cub->player);
	init_info(&cub->map_info);
	return (1);
}

//for testing purposes
int main(int argc, char **argv)
{
	t_cub cub;

	if (argc != 2)
		return (print_msg("Wrong number of arguments.", 0));
	init_parsing_info(&cub);
	if (parsing(&cub, argv) == 0)
		return (0);
	printf("everything is ok\n");
	return (1);
}