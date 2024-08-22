/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 02:02:49 by samusanc          #+#    #+#             */
/*   Updated: 2024/08/22 04:37:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include <stdlib.h>
# include "get_next_line.h"
//# include "libft.h"
//# include "T_Engine.h"
//# include "mlx_utils.h"
//# include "cub.h"
# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
#include <ctype.h>


typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_player
{
	int	x;
	int	y;
	int	angle;
	char	dir;
}	t_player;

typedef struct s_map_info
{
	int			fd;
	int			lines;
	char		*path;
	char		**file;
	int			height;
	int			width;
	int			index_end_of_map;
}	t_map_info;

typedef struct s_cub
{
//
	t_map_info	map_info;
//
	char			*north_path;
	char			*south_path;
	char			*east_path;
	char			*west_path;
	t_color			*floor;
	t_color			*ceiling;
	char			**map;
	t_player		*player;
}	t_cub;

//todelete
char	*ft_strchr(const char *str, int c);
int	ft_isalpha(int c);
int	ft_isprint(int c);
int	ft_isdigit(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int	ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
//todelete
int	parsing(t_cub *cub, char **argv);
int	parse_map(char *path, t_cub *cub);
int	check_file(char *arg);
int	print_msg(char *msg, int ret);
int	ft_isspace(char c);
int	ft_isspace_no_nl(char c);
int	fill_map(t_cub *cub, char **file, int i);
int	check_map(t_cub *cub, char **map);
void free_stuff(t_cub *cub);
int	fill_textures(t_cub *cub, char *line, int i);
int fill_color(t_cub *cub, char *line, int i);

#endif
