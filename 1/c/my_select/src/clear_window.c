/*
** clear_window.c for my_select in /home/hervet_g//work/projets/my_select
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun Jan 16 01:11:06 2011 geoffrey hervet
** Last update Sun Jan 16 01:11:09 2011 geoffrey hervet
*/

#include		<curses.h>
#include		<term.h>

#include		"put_cap.h"

void			clear_window(void)
{
  static char		*cl = NULL;

  if (cl == NULL)
    cl = tgetstr("cl", NULL);
  tputs(cl, 1, put_cap);
}
