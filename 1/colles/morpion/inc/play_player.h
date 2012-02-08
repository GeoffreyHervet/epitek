/*
** play_player.h for  in /u/all/hervet_g/public/morpion/inc
** 
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
** 
** Started on  Wed May 25 21:16:26 2011 tracy nelcha
** Last update Wed May 25 21:16:28 2011 tracy nelcha
*/

#ifndef		PLAY_PLAYER_H_
# define	PLAY_PLAYER_H_

# define	WRONG_NB(x)	((x) < 0 || (x) > 2)
# define	GET_NB(x)	((x) - '0')

int		play_player(char grid[3][3], char sign);

#endif		/*!PLAY_PLAYER_H_*/
