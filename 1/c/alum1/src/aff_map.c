/*
** aff_map.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/rendu/c/alum1/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Feb 12 15:56:48 2011 geoffrey hervet
** Last update Sat Feb 12 15:56:48 2011 geoffrey hervet
*/

#include	<curses.h>
#include	<term.h>

#include	"alum1.h"

#include	"aff_map.h"
#include	"putcap.h"

void		aff_map(t_game *game)
{
  game->c_row = 0;
  tputs(tgetstr("cl", NULL), 1, putcap);
  while (game->c_row != NB_FLOORS)
  {
    game->c_col = NB_FLOORS - game->c_row - 1;
    while (game->c_col--)
      putcap(' ');
    game->c_col = 0;
    while (game->c_col <= 31)
      putcap(((1 << game->c_col++) & game->floors[game->c_row]) ? '|' : ' ');
    putcap('\n');
    game->c_row++;
  }
  game->c_row = 0;
  while (!game->floors[game->c_row])
    game->c_row++;
  game->c_col = 0;
  while (!((1 << game->c_col) & game->floors[game->c_row]))
    game->c_col++;
  game->c_col += NB_FLOORS - game->c_row - 1;
  tputs(tgoto(tgetstr("cm", NULL), game->c_col, game->c_row), 1, putcap);
}
