/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:56:39 by andie             #+#    #+#             */
/*   Updated: 2024/08/24 23:01:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

static void	north_south(t_player *player)
{
	if (player->dir == 'S')
	{
		player->x = 0;
		player->y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else if (player->dir == 'N')
	{
		player->x = 0;
		player->y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else
		return ;
}

static void	east_west(t_player *player)
{
	if (player->dir == 'W')
	{
		player->x = -1;
		player->y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
	else if (player->dir == 'E')
	{
		player->x = 1;
		player->y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else
		return ;
}

void	player_dir(t_cubp *cubp)
{
	north_south(&cubp->player);
	east_west(&cubp->player);
}
