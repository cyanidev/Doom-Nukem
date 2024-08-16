/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 02:02:49 by samusanc          #+#    #+#             */
/*   Updated: 2024/08/16 02:57:33 by marvin           ###   ########.fr       */
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

/*typedef struct s_cub
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
	t_color			floor;
	t_color			celling;
	char			**map;
	t_player		*player;

	t_img			*north;
	t_img			*south;
	t_img			*east;
	t_img			*west;
}               t_cub;*/

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_player
{
	int	x;
	int	y;
	int	angle;
}	t_player;

typedef struct s_mapinfo
{
	int			fd;
	int			line_count;
	char		*path;
	char		**file;
	int			height;
	int			width;
	int			index_end_of_map;
}	t_mapinfo;

typedef struct s_cub
{
	void			*mlx;
	void			*mlx_win;
	unsigned int	frame;
	float			delta_time;
//
	t_img			*tmp;
//
	t_mapinfo	mapinfo;
//
	char			*north_path;
	char			*south_path;
	char			*east_path;
	char			*west_path;
	t_color				*floor;
	t_color				*ceiling;
	char			**map;
	t_player		*player;
//
	t_img			*north;
	t_img			*south;
	t_img			*east;
	t_img			*west;
}	t_cub;

#endif