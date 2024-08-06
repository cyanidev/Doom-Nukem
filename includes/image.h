
#ifndef IMAGE_H
# define IMAGE_H
# include "color.h"


typedef struct s_img{
	char	*path;
	char	*data_addr;
	void	*img;
	int		*pixel_addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
	int		width;
	int		height;
	float	alpha;
}				t_img;

t_img	*ft_open_img(void *mlx, char *path);

#endif
