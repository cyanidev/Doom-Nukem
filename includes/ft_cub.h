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

#ifndef FT_CUB_H
# define FT_CUB_H
# include <stdlib.h>
# include "player.h"
# include "libft.h"

typedef struct s_cub
{
	void			*mlx;
	void			*mlx_win;
	unsigned int	frame;
	t_player		player;
}               t_cub;

#endif