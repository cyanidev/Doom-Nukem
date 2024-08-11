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

typedef enum e_structType
{
	Empty,
	Floor,
	Wall,
	Door
}			t_structType;

typedef struct s_mapChunk
{
	t_structType	type;
	unsigned int	light;
}				t_mapChunk;

typedef struct s_cub
{
	void			*mlx;
	void			*mlx_win;
	unsigned int	frame;
	float			delta_time;

	char			*north_path;
	char			*south_path;
	char			*east_path;
	char			*west_path;
	t_color			floor;
	t_color			celling;
	t_mapChunk		**map;
	t_player		*player;

	t_img			*north;
	t_img			*south;
	t_img			*east;
	t_img			*west;
}               t_cub;

#endif