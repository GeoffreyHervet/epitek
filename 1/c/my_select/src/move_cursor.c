/*
** move_cursor.c for my_select in /home/hervet_g//work/projets/my_select
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Jan 15 22:17:50 2011 geoffrey hervet
** Last update Sat Jan 15 22:27:28 2011 geoffrey hervet
*/

#include		<curses.h>
#include		<term.h>

#include		"my_select.h"

#include		"move_cursor.h"
#include		"put_cap.h"

void		move_cursor(t_coords *coo)
{
  static char		*cm = NULL;

  if (cm == NULL)
    cm = tgetstr("cm", NULL);
  tputs(tgoto(cm, coo->col, coo->row), 1, put_cap);
}
