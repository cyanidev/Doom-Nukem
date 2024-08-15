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
void	free_gen_struct(t_cub *cub)
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
			afelicia_free_map();

		*/
		if (cub->player)
			;//

		if (cub->north)
			free_img(cub->north);
		if (cub->south)
			free_img(cub->south);
		if (cub->east)
			free_img(cub->east);
		if (cub->west)
			free_img(cub->west);

		ft_bzero(cub, sizeof(t_cub));
		free(cub);
	}
}

int	i_g_s_error(t_cub *cub)
{
	free_gen_struct(cub);
	return (0);
}

int	open_wall_tex(t_cub *cub)
{
	/*
	cub->north = open_img(cub->mlx, "");
	if (!cub->north)
		return (0);
	cub->south = open_img(cub->mlx, "");
	if (!cub->south)
		return (0);
	cub->east = open_img(cub->mlx, "");
	if (!cub->east)
		return (0);
	cub->west = open_img(cub->mlx, "");
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
int	init_gen_struct(t_cub *cub, char *map_path)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (i_g_s_error(cub));
	// CHANGE THIS RESOLUTION AFTER!!!!
	cub->mlx_win = mlx_new_window(cub->mlx, 1920, 1080, "Default Windows");
	if (!cub->mlx_win)
		return (i_g_s_error(cub));
	if (!parsing(cub, map_path))
		return (i_g_s_error(cub));
	if (!open_wall_tex(cub))
		return (i_g_s_error(cub));
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
	if (!init_gen_struct(result, map_path))
		return (NULL);
	return (result);
}

int	ft_draw_frame(void *p_cub)
{
	t_cub	*cub;

	cub = (t_cub *)p_cub;
	cub->frame += 1;
	return (0);
}


t_point	get_bounds_max(t_line tmp, t_point max)
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

t_point	get_bounds_min(t_line tmp, t_point max)
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

t_line	get_bounds(t_line *segments, unsigned int size)
{
	unsigned int	i;
	t_point			max;
	t_point			min;

	i = 0;
	max = point(FLT_MIN, FLT_MIN);
	min = point(FLT_MAX, FLT_MAX);
	while (i < size)
	{
		max = get_bounds_max(segments[i], max);
		min = get_bounds_min(segments[i], min);
		i++;
	}
	return (line(max, min));
}

t_point	remap_point(t_point pt, t_line bounds, t_resolution map_offset, int offset)
{
	t_point	result;
	float	resultx;
	float	resulty;

	// 									this can be cut and passed as parameter, optimization!!!
	resultx = (pt.px - bounds.b.px) * (map_offset.width - offset) / (bounds.a.px - bounds.b.px) + offset;
	resulty = (pt.py - bounds.b.py) * (map_offset.height - offset) / (bounds.a.py - bounds.b.py) + offset;
	return (point(resultx, resulty));
}

void	draw_normal(t_line line, t_img *img)
{
	t_point	p10;
	t_point	p0;
	t_point	p1;
	t_point	normal;

	p10 = line.a;
	p10.px = line.b.px - line.a.px;
	p10.py = line.b.py - line.a.py;
	normal = normalize(point(-p10.py, p10.px));
	p0.px = (line.a.px + line.b.px) * 0.5f;
	p0.py = (line.a.py + line.b.py) * 0.5f;
	p1.px = p0.px + normal.px * 12.0f;
	p1.py = p0.py + normal.py * 12.0f;
	draw_line(p0, p1, img);
}


//=================================================== segment in engine

typedef	struct s_segment
{
	t_line	segment;
	t_point	vector;
}				t_segment;

t_segment	*segment(t_line line)
{
	t_segment	*result;
	t_point		a;
	t_point		b;

	result = malloc(sizeof(t_segment));
	ft_bzero(result, sizeof(t_segment));
	result->segment = line;
	a = line.a;
	b = line.b;
	a.px = b.px - a.px;
	a.py = b.py - a.py;
	result->vector = a;
	return (result);
}

void	*default_node_free(void *ptr)
{
	free(ptr);
	return (NULL);
}

//=================================================== segment in engine

//=============================================BSP IN ENGINE

void	horizontal_line(int x0, int y0, int x1, t_img *img)
{
	int x;

	x = x0;
	while (x <= x1)
	{
		++x;
		put_pixel(img, point(x, y0));
	}

}

void	plot4points(int cx, int cy, int x, int y, t_img *img)
{
	horizontal_line(cx - x, cy + y, cx +x, img);
	if (y != 0)
		horizontal_line(cx - x, cy - y, cx +x, img);
}
			

void	draw_circle(int radius, t_img	*img)
{

	int	cx;
	int	cy;

	cx = 100;
	cy = 100;

	int error;
	int	x;
	int y;
	int	lasty;

	error = -radius;
	x = radius;
	y = 0;
	while (x >= y)
	{
			lasty = y;
			error += y++;
			error += y;
			plot4points(cx, cy, x, lasty, img);
			if (error >= 0)	
			{
				if (x != lasty)
					plot4points(cx, cy, lasty, x, img);
				error -= x--;
				error -= x;
			}
	}

}

void	draw_circle2(int radius, t_img	*img)
{
	float	x;
	float	y;
	float	r;
	float	distance;

	y = -1;
	r = 2.0 * radius;
	while (y < r)
	{
			x = 0;
			while (x <= r)
			{
				distance = (r - sqrt((radius - x) * 
				(radius - x) + (radius - y) * (radius - y)));
				distance = (int)(distance / radius);
				distance *= 255;
				if (distance)
				{
					put_pixel(img, color_point(point(x, y), 
					color_from_rgb(distance, distance, distance)));
				}
				x++;
			}
			y++;
	}
}


/*
for (float y = 0; y < 2.0 * r; y++)
{
    for (float x = 0; x < 2 * r; x++)
    {
        float deltaX = r - x;
        float deltaY = r - y;
        float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
        color = clamp (r - distance, 0, 1);
        plot(x, y, color);
    }
}
*/

typedef struct s_BSP
{
	struct s_BSP	*front;
	struct s_BSP	*back;
	t_segment		splitter;
}				t_BSP;

//=============================================BSP IN ENGINE

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

	cub->tmp = init_img(cub->mlx, resolution(1920, 1080));
	fill_img(cub->tmp, color(red));
	//draw_line(point(0, 0), point(2000, 1100), cub->tmp);

	t_list	segments;

	segments = list(NULL);
	list_push_b(&segments, node(segment(line(point(1,1), point(7,1))), &default_node_free));
	list_clear(&segments);
	ft_printf("segments: %p, %p, %d\n", segments.head, segments.tail, segments.size);
	/*
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
	bounds = get_bounds(segments, 4);
	printf("BOUNDS: \nmax:%f, %f\nmin: %f, %f\n", bounds.a.px, bounds.a.py, bounds.b.px, bounds.b.py);
	int i = 0;
	while (i < 4)
	{
		t_point	tmp1;
		t_point	tmp2;

		tmp1 = segments[i].a;
		tmp2 = segments[i].b;
		tmp1 = remap_point(tmp1, bounds, map_acot, 50);
		tmp2 = remap_point(tmp2, bounds, map_acot, 50);
		ft_printf("point:%d (%d, %d)\n", (int)i, (int)tmp1.px, (int)tmp1.py);
		ft_printf("point:%d (%d, %d)\n", (int)i, (int)tmp2.px, (int)tmp2.py);
		draw_line(tmp1, tmp2, cub->tmp);
		draw_normal(line(tmp1, tmp2), cub->tmp);
		i++;
	}
	*/
	int	z;

	z = 0;
	while (z < 1000)
	{
		draw_circle(5, cub->tmp);
		z++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->tmp->img, 0, 0);

	if (!cub)
	{
		write(2, "Error: cannot initialize the general struct\n", 45);
		return (-1);
	}
	mlx_loop_hook(cub->mlx, ft_draw_frame, cub);
	mlx_loop(cub->mlx);
}
