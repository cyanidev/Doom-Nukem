/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 00:41:51 by samusanc          #+#    #+#             */
/*   Updated: 2024/08/16 02:51:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
// this is your include file you can found it in Doom-Nukem/includes/
#include "parsing.h"
/*
TODO:	read the map
		save the map in a double array of chars
		
*/
int	parsing(t_cub *cub,)



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


/*

	ON FAIL RETURN 0 and free your part

*/
int	parsing(t_cub *cub, char *map_path)
{

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

	return (1);
}

int freeParsing(t_cub *cub)
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
			t_color			floor;
			t_color			celling;
		}				t_cub;

	What you need to do:
		here you only need to parse with atoi the colors and put them with 
		colorFromRGB(int red, int green, int blue); already made funtion

*/
int parsCol(t_cub *cub, char *map_path)
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
int parsMap(t_cub *cub, char *map_path)
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
int parsPlayer(t_cub *cub, char *map_path)
{

	return (1);
}


// REMIDER  this parsing flow line is something that I made to make the things easier to you, if you want to change the code flow, the funtions or anything you are free to do whatever you want as long as you respect the next rules
/*
	you have to deliver a parsing funtion, this funtion free the parsing members if something fail
	you have to deliver a map free funtion, this funtion free a the map array
	you cannot free or change any other cub struct member other than parsing members, if you need to do that tell me pls I will make the changes you need
	all your funtions need to go in the parsing folder, and the prototipes in the include in the Doom-nukem/includes/parsing.h include file
*/

// PD: pardon the bad english grammar, it's 2 o'clock in the morning.