/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 00:41:51 by samusanc          #+#    #+#             */
/*   Updated: 2024/08/21 18:45:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "cub.h"
// this is your include file you can found it in Doom-Nukem/includes/
#include "parsing.h"


/*
	Your part

	You only have to parse the proper values into the struct cub(the general struct),
	here is the part you need to parse and the corresponding members inside the cub struct:

		textures:
			*north tex path (cub->north_path)
			*south tex path (cub->south_path)
			*east tex path (cub->east_path)
			*west tex path (cub->west_path)

		color:
			*floor color (cub->floor)
			*celling color (cub->celling)
			
		map:
			*the map is a dobule array of mapChunk's: map[x][y] (cub->map) # more detail explanation down!

		player:
			*player (cub->player) # more detail explanation down!
		
	You also have to write a free map funtion
		void    freeMap(t_cub *cub);

*/

/*int	check_dir(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY | __O_DIRECTORY);
	if (fd < 0)
		return (0);
	return (1);
}

int	is_space(char *c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

//======================================= get element .c

typedef enum e_map_format
{
	north,
	south,
	east,
	west,
	ceiling,
	floor,
	error
}				t_map_format;

int	get_element_check_map(char c)
{
	if (c == '1')
		return (1);
	return (0);
}

int	get_element_check_col(char c)
{
	if (c == 'F' ||
		c == 'C' )
		return (1);
	return (0);
}

int	get_element_check_tex(char c)
{
	if (c == 'N' ||
		c == 'S' ||
		c == 'W' ||
		c == 'E')
		return (1);
	return (0);
}

int	get_element_check_char(char c)
{
	if (get_element_check_tex(c))
		return (1);
	else if (get_element_check_col(c))
		return (1);
	else if (get_element_check_map(c))
		return (1);
	return (0);
}

int	get_tex_check(char *str)
{
	int	a;
	int	b;
	int	c;
	int	i;

	i = 0;
	a = '\0';
	b = '\0';
	c = '\0';
	while (str[i])
	{
		if (i == 0)
			a = str[i];
		if (i == 1)
			b = str[i];
		if (i == 2)
			c = str[i];
		i++;
	}
	if (!a || !b || !c)
		return (0);
	if (!is_space(c))
		return (0);
	return (1);
}

t_map_format get_tex_util(int *type, t_map_format result)
{
	*type += 1;
	return (result);
}

t_map_format get_element_type_tex(char *str)
{
	static int	n = 0;
	static int	s = 0;
	static int	w = 0;
	static int	e = 0;

	if (!get_tex_check(str))
		return (error);
	if (str[0] == 'N' && str[1] == 'O' && !n)
		return (get_tex_util(&n, north));
	if (str[0] == 'S' && str[1] == 'O' && !s)
		return (get_tex_util(&s, south));
	if (str[0] == 'W' && str[1] == 'E' && !w)
		return (get_tex_util(&w, west));
	if (str[0] == 'E' && str[1] == 'A' && !e)
		return (get_tex_util(&e, east));
	return (error);
}

t_map_format get_element_type_col(char *str)
{
	static size_t	f = 0;
	static size_t	c = 0;


}

t_map_format get_element_type(char *str)
{
	// if map == 1 every other element type is invalid!!!
	static size_t	m = 0;
	int		i;

	i = 0;
	while (str[i])
	{
		if (get_element_check_char(str[i]))
		{
			if (get_element_check_tex(str[i]) && !m)
				return (get_element_type_tex(str + i));
			if (get_element_check_col(str[i]) && !m)
				return (get_element_type_col(str + i));
			if (get_element_check_map(str[i]))
			{
				m++;
				return (map);
			}
			printf("map duplicate???\n");
			return (error);
		}
		else if (!is_space(str[i]))
			return (error);
		++i;
	}
	printf("this should be space\n");
	return (space);
}

//======================================= get element .c

int	parse_by_element_type(t_cub *cub, t_map_format elment_type, char *line)
{
	if (elment_type == north)
	{

	}
	if (elment_type == south)
	{

	}

	free(line);
	return (1);
}

/*

	ON FAIL RETURN 0 and free your part

*/
/*
int	parsing(t_cub *cub, char *map_path)
{
	int		fd;

	if (check_dir(map_path))
		printf("this is bad directory!!!!\n");
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		printf("this is bad, file!!!!\n");
	else
	{
		char *extention = get_extention();
		if (!extention)
		{
			close(fd);
			printf("error bad extention!!!\n");
		}
		else
		{
			// do a stringcmp funiton in libft!!!!!!!!!!!!!
			if (ft_strncmp(extention, ".cub", 3) == 0)
			{
				char			*line;
				char			*map;
				t_map_format	element_type;

				line = get_next_line(fd);
				map = NULL;
				while (line)
				{
					element_type = get_element_type(line);
					if (element_type == error)
					{
						free(line);
						free(map);
						close(fd);
						printf("error bad elment type\n");
					}
					if (element_type != map)
					{
						//this funtion also free line!!!!
						if (!parse_by_element_type(cub, elment_type, line))
							printf("error in parsing!!!!");
					}
					else
						map = ft_strjoin(map, line);
				}
				if (!parse_map(map))
					printf("error in map parsing!!!!");

			}
			else if (ft_strncmp(extention, ".duk", 3) == 0)
			{
				printf("error, format still not supported!!!");
			}
			else
				printf("bad, format!!!");
		}
	}
	
	

	/*
	// textures
	if (!parsTex(cub, map_path))
		return (freeParsing(cub));
	// color
	if (!parsCol(cub, map_path))
		return (freeParsing(cub));
	// map
	if (!parsMap(cub, map_path))
		return (freeParsing(cub));
	// player
	if (!parsPlayer(cub, map_path))
		return (freeParsing(cub));
	*/
/*
	return (1);
}

int free_parsing(t_cub *cub)
{
	// free and set to null
	
	// textures paths
	if (cub->north_path)
		free(cub->north_path);
	if (cub->south_path)
		free(cub->south_path);
	if (cub->east_path)
		free(cub->east_path);
	if (cub->west_path)
		free(cub->west_path);

	// map
	if (cub->map)
	{
		;// use your freeMap funtion 
	}

	// player
	if (cub->player)
		;//freePlayer(cub->player);

	// set all members of parsing to NULL
	cub->north_path = NULL;
	cub->south_path = NULL;
	cub->east_path = NULL;
	cub->west_path = NULL;
	cub->map = NULL;
	cub->player = NULL;
	return (0);
}

/*

	the cub struct memebers for this part:

		typedef struct s_cub
		{
			char			*north_path;
			char			*south_path;
			char			*east_path;
			char			*west_path;
		}				t_cub;

	What you need to do:
		here you need to put the texture paths
*/
/*
int pars_tex(t_cub *cub, char *map_path)
{

	return (1);
}

/*

	the cub struct memebers for this part:

		typedef struct s_cub
		{
			t_color			floor;
			t_color			celling;
		}				t_cub;

	What you need to do:
		here you only need to parse with atoi the colors and put them with 
		colorFromRGB(int red, int green, int blue); already made funtion

*/
/*
int pars_col(t_cub *cub, char *map_path)
{

	return (1);
}

/*

	the cub struct memebers for this part:

		**
		**
		typedef struct s_cub
		{

			char		**map;

		}				t_cub;

	What you need to do:
		the most dificult part, here you need to parse the map

		you have to use the next symbols to store the values
		FLOOR = '0'
		WALL = '1'
		EMPTY = 'E'

		the map need to be a rectagle shape
		so your task is allocate and fill the map with the "Empty" the empty spaces to match an rectangle 
		example:
			1111111
			1000001
			1111101111
			1111100001
			1111111111
		this should transform into this
			1111111EEE
			1000001EEE
			1111101111
			1111100001
			1111111111
		(the player == Floor) you have to save the position in the parsPlayer funtion
		you can store the position and direction of the player temp or can you call to your parsPlayer funtion here, the choice is yours
		you will save the map in a double array of chars
		you have to use the next symbols to store the values
		FLOOR = '0'
		WALL = '1'
		EMPTY = 'E'
		in the next order
		map[x][y]
		that means if i want to check the point x:10 y: 3
		i will check map[10][3]

		and for last make sure the walls are closed
		ask to lyandriy, she make this so easy. I dont remember well the algorithm but my guess is this:
		She check if a Floor (F) is soround by another (F) or a Wall (W) if it was anything else *aka empty(E)*, you can throw an error in parsing, 


		the doors only are valid during the bonus.
		the character for a door is '2'
		check the doors with if (!BONUS) BONUS define should be 1 if we are compiling the bonus and should be zero if we are not.

*/
/*
int pars_map(t_cub *cub, char *map_path)
{
	return (1);
}

/*

	the cub struct memebers for this part:

		typedef struct s_cub
		{
			t_player		*player;
		}				t_cub;

	What you need to do:
		the player is the last part you only have to initialize the player with the custom funtion that I already made
		and your task here is only assing the angle and the position to the player with already made custom funtions
*/
/*
int pars_player(t_cub *cub, char *map_path)
{

	return (1);
}*/


// REMIDER  this parsing flow line is something that I made to make the things easier to you, if you want to change the code flow, the funtions or anything you are free to do whatever you want as long as you respect the next rules
/*
	you have to deliver a parsing funtion, this funtion free the parsing members if something fail
	you have to deliver a map free funtion, this funtion free a the map array
	you cannot free or change any other cub struct member other than parsing members, if you need to do that tell me pls I will make the changes you need
	all your funtions need to go in the parsing folder, and the prototipes in the include in the Doom-nukem/includes/parsing.h include file
*/

// PD: pardon the bad english grammar, it's 2 o'clock in the morning.
