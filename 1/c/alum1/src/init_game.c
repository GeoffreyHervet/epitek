/*
** init_game.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/rendu/c/alum1/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Feb 11 18:35:14 2011 geoffrey hervet
** Last update Fri Feb 11 18:35:14 2011 geoffrey hervet
*/

#include	<stdlib.h>

#include	"alum1.h"

#include	"init_game.h"

int		init_game(t_game *game)
{
  int		idx;

  idx = 0;
  if ((game->floors = malloc(sizeof(*game->floors) * NB_FLOORS)) == NULL)
    return (-1);
  game->floors[idx++] = 1;
  while (idx != NB_FLOORS)
  {
    game->floors[idx] = (game->floors[idx - 1] << 2) | 3;
    ++idx;
  }
  game->player = PLAYER_ID;
  game->selection = 0;
  return (0);
}
