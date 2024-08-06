/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 02:02:49 by samusanc          #+#    #+#             */
/*   Updated: 2024/08/05 02:18:39 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include "camera.h"

/*
	Player
		camera: the camera of the player, aka t_cam
		start: Unity-like or Unreal-like funtion,
		It is executed when the object is born.
		update: Unity-like funtion, it is called each frame.
*/
typedef struct s_player
{
	t_camera	*camera;
	int			(*start)(struct s_player, void *);
	int			(*update)(struct s_player, void *);
}		t_player;

// Player Constructor
t_player	*newPlayer(t_camera *camera);
void		freePlayer(t_player *player);

#endif
