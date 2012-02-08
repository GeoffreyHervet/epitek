/*
** action1.c for alum1 in /u/all/hervet_g/rendu/c/alum1
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Feb 11 21:41:59 2011 geoffrey hervet
** Last update Fri Feb 11 22:06:13 2011 geoffrey hervet
*/
#include	<stdio.h>
#include	<curses.h>
#include	<stdlib.h>
#include	<term.h>

#include	"alum1.h"

#include	"aff_map.h"
#include	"keys.h"
#include	"putcap.h"

int		_key_select(t_game *game)
{
  if (!((1 << COL_DEC) & game->selection))
  {
    tputs(tgetstr("us", NULL), 1, putcap);
    putcap('|');
    tputs(tgetstr("ue", NULL), 1, putcap);
    game->selection |= 1 << COL_DEC;
  }
  else
  {
    putcap('|');
    game->selection &= ~(1 << COL_DEC);
  }
  return (_key_right(game));
}

int		_key_valid(t_game *game)
{
  if (!game->selection)
    return (0);
  game->floors[ROW] &= ~(game->selection);
  game->selection = 0;
  game->player = AI_ID * AI_ENABLE + !AI_ENABLE * PLAYER_ID;
  aff_map(game);
  return (0);
}
