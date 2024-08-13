/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 22:32:43 by samusanc          #+#    #+#             */
/*   Updated: 2024/08/10 23:48:26 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"


//===========================================================================//


//===========================================================================//
void	freeGenStruct(t_cub *cub)
{
	if (cub)
	{		
		if (cub->mlx)
			free(cub->mlx);
		if (cub->mlx_win)
			free(cub->mlx_win);

		if (cub->north_path)
			free(cub->north_path);
		if (cub->south_path)
			free(cub->south_path);
		if (cub->east_path)
			free(cub->east_path);
		if (cub->west_path)
			free(cub->west_path);

		/*
		
		if (map)
			afeliciaFreeMap();

		*/
		if (cub->player)
			;//

		if (cub->north)
			freeImg(cub->north);
		if (cub->south)
			freeImg(cub->south);
		if (cub->east)
			freeImg(cub->east);
		if (cub->west)
			freeImg(cub->west);

		ft_bzero(cub, sizeof(t_cub));
		free(cub);
	}
}

int	iGSError(t_cub *cub)
{
	freeGenStruct(cub);
	return (0);
}

int	openWallTex(t_cub *cub)
{
	/*
	cub->north = openImg(cub->mlx, "");
	if (!cub->north)
		return (0);
	cub->south = openImg(cub->mlx, "");
	if (!cub->south)
		return (0);
	cub->east = openImg(cub->mlx, "");
	if (!cub->east)
		return (0);
	cub->west = openImg(cub->mlx, "");
	if (!cub->west)
		return (0);
	*/
	return (1);
}

//===========================================================================//

/*
	TODO: I want to implement the window array for a window managment system,
	so the general structure might change in the future
*/
int	initGenStruct(t_cub *cub, char *map_path)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (iGSError(cub));
	// CHANGE THIS RESOLUTION AFTER!!!!
	cub->mlx_win = mlx_new_window(cub->mlx, 1920, 1080, "Default Windows");
	if (!cub->mlx_win)
		return (iGSError(cub));
	if (!parsing(cub, map_path))
		return (iGSError(cub));
	if (!openWallTex(cub))
		return (iGSError(cub));
	return (1);
}

/*
	ft_constructor
	Allocates the hole struct, use bzero to NULL every element, 
	then initialize every single one of them with custom funtions.
	After bzero every error in funtion have to use the ft_freeGenStruct for error handling
	and return NULL after that
*/
t_cub	*ft_constructor(char *map_path)
{
	t_cub	*result;

	result = malloc(sizeof(t_cub));
	if (!result)
		return (NULL);
	ft_bzero(result, sizeof(t_cub));
	if (!initGenStruct(result, map_path))
		return (NULL);
	return (result);
}

int	ft_drawFrame(void *p_cub)
{
	t_cub	*cub;

	cub = (t_cub *)p_cub;
	cub->frame += 1;
	return (0);
}


t_point	getBoundsMax(t_line tmp, t_point max)
{
	if (tmp.a.px > max.px)
		max.px = tmp.a.px;
	if (tmp.b.px > max.px)
		max.px = tmp.b.px;
	if (tmp.a.py > max.py)
		max.py = tmp.a.py;
	if (tmp.b.py > max.py)
		max.py = tmp.b.py;
	return (max);
}

t_point	getBoundsMin(t_line tmp, t_point max)
{
	if (tmp.a.px < max.px)
		max.px = tmp.a.px;
	if (tmp.b.px < max.px)
		max.px = tmp.b.px;
	if (tmp.a.py < max.py)
		max.py = tmp.a.py;
	if (tmp.b.py < max.py)
		max.py = tmp.b.py;
	return (max);
}

t_line	getBounds(t_line *segments, unsigned int size)
{
	unsigned int	i;
	t_point			max;
	t_point			min;

	i = 0;
	max = point(FLT_MIN, FLT_MIN);
	min = point(FLT_MAX, FLT_MAX);
	while (i < size)
	{
		max = getBoundsMax(segments[i], max);
		min = getBoundsMin(segments[i], min);
		i++;
	}
	return (line(max, min));
}

t_point	remapPoint(t_point pt, t_line bounds, t_resolution map_offset, int offset)
{
	t_point	result;
	float	resultx;
	float	resulty;

	// 									this can be cut and passed as parameter, optimization!!!
	resultx = (pt.px - bounds.b.px) * (map_offset.width - offset) / (bounds.a.px - bounds.b.px) + offset;
	resulty = (pt.py - bounds.b.py) * (map_offset.height - offset) / (bounds.a.py - bounds.b.py) + offset;
	return (point(resultx, resulty));
}

void	drawNormal(t_line line)
{
	t_point	pr;
	t_point	normal;

	pr = line.a;
	pr.px = line.b.px - line.a.px;
	pr.py = line.b.py - line.a.py;
	normal = normalize(pr);


}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc > 2 || (argc < 2 && !BONUS))
	{
		write(2, "Error: wrong number of arguments\n", 34);
		return (-1);
	}


	cub = ft_constructor(argv[2]);
	//================================================================================

	cub->tmp = initImg(cub->mlx, resolution(1920, 1080));
	fillImg(cub->tmp, color(red));
	//drawLine(point(0, 0), point(2000, 1100), cub->tmp);

	t_line	segments[4];

	segments[0] = line(point(1, 1), point(7, 1));
	segments[1] = line(point(7, 1), point(7, 8));
	segments[2] = line(point(7, 8), point(1, 8));
	segments[3] = line(point(1, 8), point(1, 1));

	t_line			bounds;
	int				screen_offset;
	t_resolution	map_acot;

	screen_offset = 50;
	map_acot = resolution(cub->tmp->resolution.width - screen_offset, cub->tmp->resolution.height - screen_offset);
	bounds = getBounds(segments, 4);
	printf("BOUNDS: \nmax:%f, %f\nmin: %f, %f\n", bounds.a.px, bounds.a.py, bounds.b.px, bounds.b.py);
	int i = 0;
	while (i < 4)
	{
		t_point	tmp1;
		t_point	tmp2;

		tmp1 = segments[i].a;
		tmp2 = segments[i].b;
		tmp1 = remapPoint(tmp1, bounds, map_acot, 50);
		tmp2 = remapPoint(tmp2, bounds, map_acot, 50);
		ft_printf("point:%d (%d, %d)\n", (int)i, (int)tmp1.px, (int)tmp1.py);
		ft_printf("point:%d (%d, %d)\n", (int)i, (int)tmp2.px, (int)tmp2.py);
		drawLine(tmp1, tmp2, cub->tmp);
		i++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->tmp->img, 0, 0);

	if (!cub)
	{
		write(2, "Error: cannot initialize the general struct\n", 45);
		return (-1);
	}
	mlx_loop_hook(cub->mlx, ft_drawFrame, cub);
	mlx_loop(cub->mlx);
}
