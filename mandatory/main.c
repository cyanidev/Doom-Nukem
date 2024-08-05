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
#include "ft_cub.h"

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