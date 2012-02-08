/*
** play_player.h for inc in /afs/epitech.net/users/epitech_2015/hervet_g/rendu/c/alum1/inc
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Feb 11 19:19:33 2011 geoffrey hervet
** Last update Fri Feb 11 19:19:33 2011 geoffrey hervet
*/

#ifndef __PLAY_PLAYER_H__
# define __PLAY_PLAYER_H__

void		play_player(t_game *game);

typedef struct
{
  int		(*func)(t_game *);
  char		*key;
}		t_tab;

#endif /* !__PLAY_PLAYER_H__ */
