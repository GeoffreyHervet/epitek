/*
** play_computer.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/rendu/c/alum1/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Feb 12 16:06:09 2011 geoffrey hervet
** Last update Sat Feb 12 16:06:09 2011 geoffrey hervet
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<curses.h>
#include		<term.h>
#include		<unistd.h>

#include		"alum1.h"

#include		"aff_map.h"
#include		"force.h"
#include		"play_computer.h"
#include		"putcap.h"

#define			POPCOUNT(x) (__builtin_popcount(x))

static unsigned int	what_play(const unsigned int *floors)
{
  unsigned int		ret;
  int			idx;

  idx = 0;
  ret = 0;
  while (idx < NB_FLOORS)
    ret ^= POPCOUNT(floors[idx++]);
  return (ret);
}

static void		make_move(t_game *game,
				  int idx,
                                  int to_play)
{
  int			tmp;

  tmp = 0;
  while (to_play)
  {
    if (game->floors[idx] & (1 << tmp))
    {
      game->floors[idx] &= ~(1 << tmp);
      to_play--;
    }
    tmp++;
  }
}

static void		play_game(t_game *game,
				  unsigned int to_play)
{
  int			idx;
  int			tmp;

  idx = 0;
  tmp = 0;
  while (idx < NB_FLOORS)
    tmp = (!tmp && POPCOUNT(game->floors[idx++]) >= to_play) ? 1 : 0;
  if (!tmp)
  {
    force(game);
    return ;
  }
  idx = 0;
  tmp = 0;
  while (idx < NB_FLOORS)
    if (POPCOUNT(game->floors[idx++]) >= POPCOUNT(game->floors[tmp]))
      tmp = idx - 1;
  make_move(game, tmp, to_play);
}

void			play_computer(t_game *game)
{
  sleep(1);
  play_game(game, what_play(game->floors));
  game->player = PLAYER_ID;
  aff_map(game);
}
