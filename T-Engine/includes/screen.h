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

#ifndef SCREEN_H
# define SCREEN_H
# include "resolution.h"
# include "color.h"

/*
	Screen struct works like an object
	Is highly recommended to use it with 
	screen custom funtions:
*/
typedef struct s_screen
{
	t_color			*pixels;
	t_resolution	resolution;
}		t_screen;

t_screen	*newScreen(t_resolution resolution);
void		*freeScreen(t_screen *screen);

#endif
