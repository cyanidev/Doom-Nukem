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

static int	check_digit(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			flag = 1;
		i++;
	}
	return (flag);
}

static int	*rgb_array(char **rgb, int *color)
{
	int	i;

	i = 0;
	while (rgb[i])
	{
		color[i] = ft_atoi(rgb[i]);
		if (color[i] < 0 || check_digit(rgb[i]) == 0)
		{
			free_tab((void **)rgb);
			free(color);
			return (0);
		}
		i++;
	}
	free_tab((void **)rgb);
	return (color);
}

static int	*parse_rgb_values(char *line)
{
	char	**rgb;
	int		i;
	int		*color;

	rgb = ft_split(line, ',');
	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
	{
		free_tab((void **)rgb);
		return (0);
	}
	color = malloc(sizeof(int) * 3);
	if (color == NULL)
	{
		free_tab((void **)rgb);
		return (0);
	}
	return (rgb_array(rgb, color));
}

//returns 1 if the color is successfully parsed, 0 otherwise
int	fill_color(t_cub *cub, char *line, int i)
{
	if (line[i + 1] && ft_isprint(line[i + 1]))
		return (print_msg("Error in colors", 0));
	if (!cub->ceiling && line[i] == 'C')
	{
		cub->ceiling = parse_rgb_values(line + i + 1);
		if (!cub->ceiling)
			return (print_msg("Error parsing ceiling color", 0));
	}
	else if (!cub->floor && line[i] == 'F')
	{
		cub->floor = parse_rgb_values(line + i + 1);
		if (!cub->floor)
			return (print_msg("Error parsing ceiling color", 0));
	}
	else
		return (print_msg("Error in colors", 0));
	return (1);
}
