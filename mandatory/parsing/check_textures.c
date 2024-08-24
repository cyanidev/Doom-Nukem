/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:49:35 by andie             #+#    #+#             */
/*   Updated: 2024/08/25 00:03:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	check_rgb(int *color)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (color[i] < 0 || color[i] > 255)
			return (print_msg("RGB value is not between 0 and 255", 0));
		i++;
	}
	return (1);
}

static unsigned long	rgb_to_hex(int *color)
{
	unsigned long	hex;
	int				r;
	int				g;
	int				b;

	r = color[0];
	g = color[1];
	b = color[2];
	hex = r << 16 | g << 8 | b;
	return (hex);
}

int	check_texture(t_cub *cub)
{
	if (cub->north_path == NULL || cub->south_path == NULL
		|| cub->west_path == NULL || cub->east_path == NULL)
		return (print_msg("North texture is missing", 0));
	if (!cub->ceiling || !cub->floor)
		return (print_msg("Ceiling or floor color is missing", 0));
	if (check_path(cub->north_path) == 0
		|| check_path(cub->south_path) == 0
		|| check_path(cub->west_path) == 0
		|| check_path(cub->east_path) == 0
		|| check_rgb(cub->ceiling) == 0
		|| check_rgb(cub->floor) == 0)
		return (0);
	cub->x_ceiling = rgb_to_hex(cub->ceiling);
	cub->x_floor = rgb_to_hex(cub->floor);
	return (1);
}
