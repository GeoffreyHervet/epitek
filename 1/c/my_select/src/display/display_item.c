/*
** display_item.c for my_select in /home/hervet_g//work/projets/my_select
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Jan 15 14:45:11 2011 geoffrey hervet
** Last update Sun Jan 16 01:52:09 2011 geoffrey hervet
*/

#include		<curses.h>
#include		<term.h>

#include		<stdio.h>
#include		<sys/types.h>
#include		<sys/stat.h>
#include		<fcntl.h>

#include		"libmy.h"
#include		"my_select.h"

#include		"display/display_item.h"
#include		"put_cap.h"

static void		move_cursor(t_coords *coo)
{
  static char		*cm = NULL;

  if (cm == NULL)
    cm = tgetstr("cm", NULL);
  tputs(tgoto(cm, coo->col, coo->row), 1, put_cap);
}

void			display_item(t_list_db *item,
				     t_coords *coo,
				     const int fd)
{
  static char		*mr = NULL;
  static char		*us = NULL;
  static char		*me = NULL;

  if (coo == NULL)
    coo = &(item->coords);
  if (coo->col == -1)
    return ;
  if (mr == NULL)
    {
      mr = tgetstr("mr", NULL);
      us = tgetstr("us", NULL);
      me = tgetstr("me", NULL);
    }
  move_cursor(coo);
  if (item->flags & FL_SELECT)
    tputs(mr, 1, put_cap);
  if (item->flags & FL_HOVER)
    tputs(us, 1, put_cap);
  my_putstr(item->data, fd);
  if (item->flags & (FL_HOVER | FL_SELECT))
    tputs(me, 1, put_cap);
  put_cap(' ');
}
