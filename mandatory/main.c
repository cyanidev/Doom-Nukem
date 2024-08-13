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

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc > 2 || (argc < 2 && !BONUS))
	{
		write(2, "Error: wrong number of arguments\n", 34);
		return (-1);
	}


	cub = ft_constructor(argv[2]);
	cub->tmp = initImg(cub->mlx, resolution(1920, 1080));
	fillImg(cub->tmp, color(red));
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->tmp->img, 0, 0);
	if (!cub)
	{
		write(2, "Error: cannot initialize the general struct\n", 45);
		return (-1);
	}
	mlx_loop_hook(cub->mlx, ft_drawFrame, cub);
	ft_printf("yes 6\n");
	mlx_loop(cub->mlx);
}
