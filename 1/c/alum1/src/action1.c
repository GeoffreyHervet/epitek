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

#include	"keys.h"
#include	"putcap.h"

static void	move_cursor(int col, int row)
{
  static char	*cm = NULL;

  if (cm == NULL)
    cm = tgetstr("cm", NULL);
  tputs(tgoto(cm, col, row), 1, putcap);
}

int		_key_down(t_game *game)
{
  if (game->selection)
    return (_key_left(game));
  ROW = (ROW == NB_FLOORS - 1) ? 0 : ROW + 1;
  while (!(game->floors[ROW]))
  {
    game->c_row++;
    if (ROW == NB_FLOORS)
      ROW = 0;
  }
  if (!((1 << COL_DEC) & game->floors[ROW]))
    return (_key_left(game));
  move_cursor(COL, ROW);
  return (0);
}

int		_key_up(t_game *game)
{
  if (game->selection)
    return (_key_right(game));
  ROW = (ROW == 0) ? NB_FLOORS - 1 : ROW - 1;
  while (!(game->floors[ROW]))
  {
    ROW--;
    if (ROW == -1)
      ROW = NB_FLOORS - 1;
  }
  if (!((1 << COL_DEC) & game->floors[ROW]))
    return (_key_left(game));
  move_cursor(COL, ROW);
  return (0);
}

int		_key_right(t_game *game)
{
  game->c_col++;
  while (!((1 << COL_DEC) & game->floors[ROW]))
  {
    game->c_col++;
    if (COL_DEC == 32)
      game->c_col = DEC_LEFT;
  }
  move_cursor(COL, ROW);
  return (0);
}

int		_key_left(t_game *game)
{
  game->c_col--;
  while (!((1 << COL_DEC) & game->floors[ROW]))
  {
    game->c_col--;
    if (COL_DEC < 0)
      game->c_col = 31 + DEC_LEFT;
  }
  move_cursor(COL, ROW);
  return (0);
}
