/*
** init_keys.c for my_select in /home/hervet_g//work/projets/my_select
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Jan 15 17:00:57 2011 geoffrey hervet
** Last update Sat Jan 15 17:04:43 2011 geoffrey hervet
*/

#include		<curses.h>
#include		<term.h>

#include		"init/init_keys.h"
#include		"put_cap.h"

void			init_keys(void)
{
  tputs(tgetstr("ks", NULL), 1, put_cap);
}
