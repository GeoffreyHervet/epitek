/*
** play_ai.h for  in /u/all/hervet_g/public/morpion/inc
** 
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
** 
** Started on  Wed May 25 21:16:47 2011 tracy nelcha
** Last update Wed May 25 22:54:39 2011 tracy nelcha
*/

#ifndef		PLAY_AI_H_
# define	PLAY_AI_H_

/*
** STRUCTURE
*/

typedef struct  s_ai
{
  int           y;
  int           x;
  int           tmp;
  int           coo[3];
}               t_ai;

/*
** PROTO
*/

int		play_ai(char grid[3][3], char sign);

#endif		/*!PLAY_AI_H_*/
