/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 02:02:49 by samusanc          #+#    #+#             */
/*   Updated: 2024/08/16 02:36:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include <stdlib.h>
# include "libft.h"
# include "T_Engine.h"
# include "mlx_utils.h"
# include "cub.h"
# include <fcntl.h>
# include <unistd.h>


int	check_file(char *arg);
int	print_msg(char *msg, int ret);
int	ft_isspace(char c);
int	ft_isspace_no_nl(char c);

#endif
