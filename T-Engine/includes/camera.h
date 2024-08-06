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

#ifndef CAMERA_H
# define CAMERA_H
# include "point.h"
# include "screen.h"

typedef struct s_camera
{
	t_point			pos;
	float			angle;
	float			fov;
	t_screen		*screen;
}		t_camera;

t_camera	*newCamera(t_point pos, float angle, float fov, t_screen *screen);
void		freeCamera(t_camera *cam);

#endif