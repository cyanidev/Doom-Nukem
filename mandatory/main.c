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
#include "parsing.h"


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
	/*if (!parsingmap(&map_path, cub))
		return (i_g_s_error(cub));*/
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
	if (!result)
		return (NULL);
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


//============================================= Draw circle in mlx_utils

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
			

void	draw_circle(int radius, t_img *img, t_point center)
{

	int	cx;
	int	cy;

	cx = center.px;
	cy = center.py;

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

//============================================= Draw circle in mlx_utils

//============================================= get_bounds in engine

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

t_line	get_bounds(t_list *segments)
{
	t_node			*tmp;
	t_segment		*tmp2;
	t_point			max;
	t_point			min;

	tmp = segments->head;
	max = point(FLT_MIN, FLT_MIN);
	min = point(FLT_MAX, FLT_MAX);
	while (tmp)
	{
		tmp2 = (t_segment *)tmp->content;
		max = get_bounds_max(tmp2->segment, max);
		min = get_bounds_min(tmp2->segment, min);
		tmp = tmp->next;
	}
	return (line(max, min));
}

//============================================= get_bounds in engine

//============================================= s_map in t_engine
typedef struct s_map_editor
{
	t_list			segments;
	t_point			screen_center;
	int				screen_zoom;
	int				screen_offset;
	int				screen_real_offset;
	t_resolution	map_acot;
	t_line			bounds;
}				t_map_editor;

t_map_editor	new_map_editor(t_list segments, int screen_offset, t_resolution img_res);

t_map_editor	new_map_editor(t_list segments, int screen_offset, t_resolution img_res)
{
	t_map_editor	result;

	result.segments = segments;
	result.screen_center = point(0, 0);
	result.screen_zoom = 0;
	result.screen_offset = screen_offset;
	result.screen_real_offset = screen_offset + result.screen_zoom;
	result.map_acot = resolution(img_res.width - result.screen_real_offset, 
	img_res.height - result.screen_real_offset);
	result.bounds = get_bounds(&result.segments);
	return (result);
}

//============================================= s_map in t_engine

//============================================== draw map editor in mlx_utils

t_point	remap_point(t_point pt, t_line bounds, t_resolution map_offset, int offset)
{
	t_point	result;
	float	resultx;
	float	resulty;

	// you can calc this value 1 time or every time there is an update event
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

void	draw_map_editor(t_map_editor map_editor, t_img *img)
{
	t_node		*tmp;
	t_segment	*tmp1;
	t_point		tmp2;
	t_point		tmp3;

	tmp = map_editor.segments.head;
	while (tmp)
	{
		tmp1 = (t_segment *)tmp->content;
		tmp2 = tmp1->segment.a;
		tmp3 = tmp1->segment.b;
		tmp2 = remap_point(tmp2, map_editor.bounds, map_editor.map_acot, map_editor.screen_real_offset);
		tmp3 = remap_point(tmp3, map_editor.bounds, map_editor.map_acot, map_editor.screen_real_offset);
		draw_line(tmp2, tmp3, img);
		draw_normal(line(tmp2, tmp3), img);
		draw_circle(5, img, tmp2);
		draw_circle(5, img, tmp3);
		tmp = tmp->next;
	}
}

//============================================== draw map editor in mlx_utils

//=============================================BSP IN ENGINE

typedef struct s_bsp
{
	struct s_bsp	*front;
	struct s_bsp	*back;
	t_segment		*splitter;
}				t_bsp;


t_bsp	*bsp(t_bsp *front, t_bsp *back, t_segment *splitter)
{
	t_bsp	*result;

	result = malloc(sizeof(t_bsp));
	if (!result)
		return (NULL);
	ft_bzero(result, sizeof(t_bsp));
	result->front = front;
	result->back = back;
	result->splitter = splitter;
	return (result);
}

float	cross_2d(t_point a, t_point b)
{
	return (a.px * b.py - b.px * a.py);
}

#define EPS 1e-4

int	split_segments(t_list *front, t_list *back, t_list segments, t_bsp *nd)
{
	t_segment	*splitter_seg;
	t_node		*tmp;
	t_segment	*seg_tmp;
	t_segment	*content_tmp;
	float		numerator;
	float		denominator;
	float		t;
	int			denominator_is_zero;
	int			numerator_is_zero;
	float		intersection;
	t_point		intersection_pt;
	t_segment	*r_segment;
	t_segment	*l_segment;
	t_segment	*third_segment;

	splitter_seg = (t_segment *)segments.head->content;
	nd->splitter = malloc(sizeof(t_segment));
	if (!nd->splitter)
		return ;
	ft_memcpy(nd->splitter, split_segments, sizeof(t_segment));
	tmp = segments.head;
	while (tmp->next)
	{
		tmp = tmp->next;
		seg_tmp = (t_segment *)tmp->content;
		numerator = cross_2d(
		point(
		seg_tmp->segment.a.px - splitter_seg->segment.a.px, 
		seg_tmp->segment.a.py - splitter_seg->segment.a.py
		), splitter_seg->vector);
		denominator = cross_2d(splitter_seg->vector, seg_tmp->vector);


		denominator_is_zero = ft_abs(denominator) < EPS;
		numerator_is_zero = ft_abs(numerator) < EPS;

		if (denominator_is_zero && numerator_is_zero)
		{
			content_tmp = malloc(sizeof(t_segment));
			if (content_tmp)
			{
				ft_memcpy(content_tmp, seg_tmp, sizeof(t_segment));
				list_push_f(front, node(content_tmp, &default_node_free));
			}
		}
		if (!denominator_is_zero)
		{
			intersection = numerator / denominator;

			if (0.0 < intersection && intersection < 1.0)
			{
				intersection_pt = point(seg_tmp->segment.a.px + intersection * seg_tmp->vector.px, 
				seg_tmp->segment.a.py + intersection * seg_tmp->vector.py);

				r_segment = segment(line(seg_tmp->segment.a, intersection_pt));
				l_segment = segment(line(intersection_pt, seg_tmp->segment.b));
				if (numerator > 0)
				{
					third_segment = l_segment;
					l_segment = r_segment;
					r_segment = third_segment;
				}
				list_push_f(front, node(r_segment, &default_node_free));
				list_push_f(back, node(l_segment, &default_node_free));
			}
		}
		if (numerator < 0 || (numerator_is_zero && denominator > 0))
		{
			content_tmp = malloc(sizeof(t_segment));
			if (content_tmp)
			{
				ft_memcpy(content_tmp, seg_tmp, sizeof(t_segment));
				list_push_f(front, node(content_tmp, &default_node_free));
			}
		}
		else if (numerator > 0 || (numerator_is_zero && denominator < 0))
		{
			content_tmp = malloc(sizeof(t_segment));
			if (content_tmp)
			{
				ft_memcpy(content_tmp, seg_tmp, sizeof(t_segment));
				list_push_f(back, node(content_tmp, &default_node_free));
			}
		}
	}
}

t_bsp	*build_bsp(t_list segments);

t_bsp	*build_bsp(t_list segments)
{
	t_bsp	*result;
	t_list	front;
	t_list	back;

	if (!segments.head)
		return (NULL);
	result = bsp(NULL, NULL, NULL);
	if (!result)
		return (NULL);
	if (!split_segments(&front, &back, segments, result))
		return (NULL);

	if (front.head)
		result->front = build_bsp(front);
	if (back.head)
		result->back = build_bsp(back);

	list_clear(&front);
	list_clear(&back);
	return (NULL);
}

//=============================================BSP IN ENGINE



int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc > 2 || (argc < 2 && !BONUS))
	{
		write(2, "Error: wrong number of arguments\n", 34);
		return (-1);
	}


	cub = ft_constructor(argv[1]);
	//================================================================================
	parsingmap(argv, cub);
	cub->tmp = init_img(cub->mlx, resolution(1920, 1080));
	fill_img(cub->tmp, color(red));

	// this part is parsing one map ======================================================
	t_list	segments;

	segments = list(NULL);
	list_push_b(&segments, node(segment(line(point(1, 1), point(7, 1))), &default_node_free));
	list_push_b(&segments, node(segment(line(point(7, 1), point(7, 8))), &default_node_free));
	list_push_b(&segments, node(segment(line(point(7, 8), point(1, 8))), &default_node_free));
	list_push_b(&segments, node(segment(line(point(1, 8), point(1, 1))), &default_node_free));

	list_push_b(&segments, node(segment(line(point(2, 4), point(2, 3))), &default_node_free));
	list_push_b(&segments, node(segment(line(point(2, 3), point(5, 5))), &default_node_free));
	list_push_b(&segments, node(segment(line(point(5, 5), point(3, 6))), &default_node_free));
	list_push_b(&segments, node(segment(line(point(3, 6), point(2, 4))), &default_node_free));

	t_map_editor map_edit;

	map_edit = new_map_editor(segments, 50, cub->tmp->resolution);

	// this part is parsing the map ======================================================

	cub->root_node = build_bsp(segments);

	draw_map_editor(map_edit, cub->tmp);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->tmp->img, 0, 0);

	if (!cub)
	{
		write(2, "Error: cannot initialize the general struct\n", 45);
		return (-1);
	}
	mlx_loop_hook(cub->mlx, ft_draw_frame, cub);
	mlx_loop(cub->mlx);
}
