

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	float	alpha;
}		t_color;

t_color	color(char *name);
t_color	colorFormRGB(int red, int green, int blue);
t_color	colorFormHEX(int color);
t_color	color_mix(t_color a, t_color b, float lerp);

#endif