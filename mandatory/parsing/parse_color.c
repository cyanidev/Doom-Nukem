/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 02:38:15 by andie             #+#    #+#             */
/*   Updated: 2024/08/17 15:34:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub.h"
#include "parsing.h"


int parse_rgb_values(char *line, int *red, int *green, int *blue)
{
	int i = 0;

	while (ft_isspace(line[i]))
		i++;
	*red = ft_atoi(&line[i]);
	if (*red < 0 || *red > 255)
		return (0);
	while (line[i] && line[i] != ',')
		i++;
	if (line[i] == ',')
		i++;
	*green = ft_atoi(&line[i]);
	if (*green < 0 || *green > 255)
		return (0);
	while (line[i] && line[i] != ',')
		i++;
	if (line[i] == ',')
		 i++;
	*blue = ft_atoi(&line[i]);
	if (*blue < 0 || *blue > 255)
		return (0);
	return (1);
}

void colorFromRGB(int r, int g, int b, t_color *color)
{
	color->r = r;
	color->g = g;
	color->b = b;
}

//returns 1 if the color is successfully parsed, 0 otherwise
int fill_color(t_cub *cub, char *line, int i)
{
	int	red;
	int	green;
	int	blue;
	
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == 'C')
	{
		if (parse_rgb_values(&line[i + 1], &red, &green, &blue) == 0)
			return (print_msg("Error parsing ceiling color", 0));
		colorFromRGB(red, green, blue, cub->ceiling);
	}
	else if (line[i] == 'F')
	{
		if (parse_rgb_values(&line[i + 1], &red, &green, &blue) == 0)
			return (print_msg("Error parsing ceiling color", 0));
		colorFromRGB(red, green, blue, cub->floor);
	}
	else
		return (print_msg("Error in colors", 0));
	return (1);
}