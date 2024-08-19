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

void init_color(t_color *color)
{
	color->r = 0;
	color->g = 0;
	color->b = 0;
}

void init_player(t_player *player)
{
	player->dir = '0';
	player->x = 0;
	player->y = 0;
	player->angle = 0;
}

void init_info(t_map_info mp_info)
{
	map_info->fd = 0;
	map_info->line_count = 0;
	map_info->path = NULL;
	map_info->file = NULL;
	map_info->height = 0;
	map_info->width = 0;
	map_info->index_end_of_map = 0;
}

int init_stuff(t_cub *cub)
{
	cub->north_path = NULL;
	cub->south_path = NULL;
	cub->east_path = NULL;
	cub->west_path = NULL;
	cub->map-> NULL;
	
	cub->floor = malloc(sizeof(t_color));
	if (cube->floor == NULL)
		return (0);
	cub->ceiling = malloc(sizeof(t_color));
	if (cube->ceiling == NULL)
	{
		free(cub->floor);
		return (0);
	}
	cub->player = malloc(sizeof(t_player));
	if (cube->player == NULL)
	{
		free(cub->floor);
		free(cub->ceiling);
		return (0);
	}
	init_color(&cub->floor);
	init_color(&cub->ceiling);
	init_player(&cub->player);
	init_info(&cub->map_info);
	return (1);
}

//for testing purposes
int main(int argc, char **argv)
{
	t_cub cub;

	if (init_stuff(&cub) = 0)
		return (print_msg("Error: malloc failed", 0));
	if (parsing(&cub, argv) = 0)
	{
		free_stuff(&cub);
		return (0);
	}
	return (1);
}
