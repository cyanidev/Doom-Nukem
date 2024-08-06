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
# include "point.h"

// TODO I NEED TO CHANGE THIS SECTION TO MATCH PLAYERS ENEMYS AND OTHER SPRITES
typedef struct s_player
{
	t_point	pos;
	float	dx;
	float	dy;
	float	angle;
}		t_player;

// seters Player
void	setPlayerA(float angle);
void	setPlayerPos(t_point pos);

// getters Player
t_point	getPlayerPos(void);
float	getPlayerA(void);

#endif
