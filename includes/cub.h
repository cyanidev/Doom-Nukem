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
# include "libft.h"
# include "T_Engine.h"
# include "mlx_utils.h"
# ifndef BONUS
#  define BONUS 1
# endif

typedef struct s_bsp t_bsp;

typedef struct s_cub
{
	void			*mlx;
	void			*mlx_win;
	unsigned int	frame;
	float			delta_time;

	t_img			*tmp;

	char			*north_path;
	char			*south_path;
	char			*east_path;
	char			*west_path;
	int				*floor;
	int			*celling;
	char			**map;
	t_player		*player;


	t_bsp			*root_node;

	t_img			*north;
	t_img			*south;
	t_img			*east;
	t_img			*west;
}               t_cub;

#endif