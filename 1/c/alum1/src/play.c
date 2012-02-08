/*
** play.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/rendu/c/alum1/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Feb 11 18:45:23 2011 geoffrey hervet
** Last update Fri Feb 11 18:45:23 2011 geoffrey hervet
*/

#include	<curses.h>
#include	<term.h>

#include	"libmy.h"
#include	"alum1.h"

#include	"aff_map.h"
#include	"play.h"
#include	"play_computer.h"
#include	"play_player.h"
#include	"putcap.h"

static int	is_end(t_game *game)
{
  int		idx;

  idx = 0;
  while (idx < NB_FLOORS)
    if (__builtin_popcount(game->floors[idx++]))
      return (0);
  return (1);
}

static int	aff_msg(t_game *game)
{
  tputs(tgetstr("cl", NULL), 1, putcap);
  if (game->player == PLAYER_ID)
    my_putstr("\n\n\n\nYou loose ...\n", 1);
  else
    my_putstr("\n\n\n\nYou win \\o/ ...\n", 1);
  return (0);
}

static int	play_rec(t_game *game)
{
  if (game->player == PLAYER_ID)
    play_player(game);
  else if (game->player == AI_ID)
    play_computer(game);
  if (is_end(game))
    return (aff_msg(game));
  return (play_rec(game));
}

void		play(t_game *game)
{
  aff_map(game);
  play_rec(game);
}
