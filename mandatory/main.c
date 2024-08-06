/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 22:32:43 by samusanc          #+#    #+#             */
/*   Updated: 2024/08/04 22:32:44 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"

void	ft_free_img(t_img *img)
{
	if (img)
	{
		if (img->img)
			free(img->img);
		if (img->path)
			free(img->path);
		if (img->data_addr)
			free(img->data_addr);
		if (img->pixel_addr)
			free(img->pixel_addr);
		ft_bzero(img, sizeof(t_img));
		free(img);
	}
}

//===========================================================================//

t_img	*ft_free_open_img(t_img *img)
{
	ft_free_img(img);
	return (NULL);
}

t_img	*ft_open_img_utils(t_img *img, void *mlx, char *path)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	if (!img->img)
		return (ft_free_open_img(img));
	img->data_addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_size), &(img->endian));
	if (!img->data_addr)
		return (ft_free_open_img(img));
	img->pixel_addr = (int *)mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_size), &(img->endian));
	if (!img->pixel_addr)
		return (ft_free_open_img(img));
	tmp = ft_strdup(path);
	if (!tmp)
		return (ft_free_open_img(img));
	return (img);
}

t_img	*ft_open_img(void *mlx, char *path)
{
	t_img	*img;
	char	*tmp;

	if (!path)
		return (NULL);
	img = malloc(sizeof(t_img) * 1);
	if (!img)
		return (NULL);
	ft_bzero(img, sizeof(t_img));
	if (!ft_open_img_utils(img, mlx, path))
		return (NULL);
}

//===========================================================================//

void	ft_freeGenStruct(t_cub *cub)
{
	if (cub)
	{		
		if (cub->mlx)
			free(cub->mlx);
		if (cub->mlx_win)
			free(cub->mlx_win);
		

		ft_bzero(cub, sizeof(t_cub));
		free(cub);
	}
}

int	ft_iGSError(t_cub *cub)
{
	ft_freeGenStruct(cub);
	return (0);
}

/*
	TODO: I want to implement the window array for a window managment system,
	so the general structure might change in the future
*/
int	ft_initGenStruct(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (ft_iGSError(cub));
	cub->mlx_win = mlx_new_window(cub->mlx, 1920, 1080, "Default Windows");
	if (!cub->mlx_win)
		return (ft_iGSError(cub));
	return (1);
}

/*
	ft_constructor
	Allocates the hole struct, use bzero to NULL every element, 
	then initialize every single one of them with custom funtions.
	After bzero every error in funtion have to use the ft_freeGenStruct for error handling
	and return NULL after that
*/
t_cub	*ft_constructor()
{
	t_cub	*result;

	result = malloc(sizeof(t_cub));
	if (!result)
		return (NULL);
	ft_bzero(result, sizeof(t_cub));
	if (!ft_initGenStruct(result))
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

int	main(void)
{
	t_cub	*cub;

	cub = ft_constructor();
	if (!cub)
	{
		write(2, "Error: cannot initialize the general struct\n", 45);
		return (-1);
	}
	mlx_loop_hook(cub->mlx, ft_drawFrame, cub);
	mlx_loop(cub->mlx);
}
