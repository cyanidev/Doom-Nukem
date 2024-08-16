/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:19:11 by andie             #+#    #+#             */
/*   Updated: 2024/08/16 01:11:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub.h"
#include "parsing.h"

//checks whether the argument is a directory, return 1 if it is, 0 if it is not
static int	check_dir(char *arg)
{
	int fd;
	
	fd = open(arg, O_RDONLY | O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		return (1);
	}
	return (0);
}

//checks the .cub extension, return 1 if it is, 0 if it is not
static int	check_exten(char *arg)
{
	size_t length;

	length = ft_strlen(arg);
	if ((arg[lenght - 4] != '.' || arg[lenght - 3] != 'c' || arg[lenght - 2] != 'u'
		|| arg[lenght - 1] != 'b'))
		return (0);
}

//returns 0 on success
int	check_file(char *arg)
{
	int	fd;
	
	if (check_dir(arg))
		return (print_msg("File is a directory.", 1));
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (err_msg(arg, strerror(errno), 1));
	close(fd);
	if (!check_exten(arg))
		return (print_msg("Incorrect type of file.", 1));
	return (0);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_isspace_no_nl(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}