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

#ifndef RESOLUTION_H
# define RESOLUTION_H

typedef struct s_resolution
{
	unsigned int	width;
	unsigned int	height;
}		t_resolution;

// set resolution by hand
t_resolution	setRes(unsigned int width, unsigned int height);

// set the resolution by aspect ratio
t_resolution	setResByAR(char *aspect_ratio);

#endif
