
#ifndef POINT_H
# define POINT_H
# include "color.h"

typedef struct s_point
{
	float	px;
	float	py;
	float	pz;
	t_color	color;
}		t_point;

// point is a 2d representation of a vector
t_point	point(float px, float py);

t_point	vector(float px, float py, float pz);

t_point	setPtColor(t_point pt, t_color color);

#endif