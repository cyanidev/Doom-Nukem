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

#ifndef NPC_H
# define NPC_H
# include "point.h"

/*
	NPC:
		model: this is the model or sprites from the npc

*/
typedef struct s_npc
{
	void	*model;
	t_point	pos;
	float	angle;
	int		(*start)(struct s_npc, void *);
	int		(*update)(struct s_npc, void *);
}		t_npc;

// npc Constructor
t_npc		*newNpc(void *model, t_point pos, float angle);
void		freeNpc(t_npc *npc);

#endif
