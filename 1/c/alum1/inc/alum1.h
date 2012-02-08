/*
** alum1.h for inc in /afs/epitech.net/users/epitech_2015/hervet_g/rendu/c/alum1/inc
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Feb 11 17:52:27 2011 geoffrey hervet
** Last update Fri Feb 11 17:52:27 2011 geoffrey hervet
*/

#ifndef __ALUM1_H__
# define __ALUM1_H__

# define	NB_FLOORS	4
# define	PLAYER_ID	1
# define	AI_ID		2
# define	AI_ENABLE	1

typedef struct
{
  unsigned int	*floors;
  int		player;
  int		selection;
  int		c_col;
  int		c_row;
}		t_game;

#endif /* !__ALUM1_H__ */
