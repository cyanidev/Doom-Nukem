/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 02:02:49 by samusanc          #+#    #+#             */
/*   Updated: 2024/08/05 02:03:30 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include <stdlib.h>
# include "player.h"
# include "libft.h"
# include "image.h"

typedef struct s_cub
{
	void			*mlx;
	void			*mlx_win;
	unsigned int	frame;
	t_img			*north;
	t_img			*south;
	t_img			*east;
	t_img			*west;
	t_color			ground;
	t_color			celling;
	t_player		*player;
	
}               t_cub;

#endif