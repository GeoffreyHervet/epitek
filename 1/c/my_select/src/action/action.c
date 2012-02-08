/*
** action.c for my_select in /home/hervet_g//work/projets/my_select
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Jan 15 17:13:12 2011 geoffrey hervet
** Last update Sun Jan 16 00:11:27 2011 geoffrey hervet
*/

#include		<curses.h>
#include		<stdlib.h>
#include		<term.h>

#include		"libmy.h"
#include		"my_select.h"

#include		"action/action.h"
#include		"action/key.h"

static t_func_array	array[9];

static void		init_tab(void)
{
  array[0].keys = tgetstr("ku", NULL);
  array[1].keys = tgetstr("kd", NULL);
  array[2].keys = tgetstr("kl", NULL);
  array[3].keys = tgetstr("kr", NULL);
  array[4].keys = tgetstr("kD", NULL);
  array[5].keys = tgetstr("kb", NULL);
  array[6].keys = "\n";
  array[7].keys = "\033";
  array[8].keys = " ";
  array[0].func = upper_key;
  array[1].func = down_key;
  array[2].func = left_key;
  array[3].func = right_key;
  array[4].func = delete_item;
  array[5].func = delete_itemb;
  array[6].func = validate;
  array[7].func = escape_prog;
  array[8].func = select_item;
  array[9].keys = NULL;
  array[9].func = NULL;
}

void			action(t_infos *inf,
			       const int fd,
			       char buf[5])
{
  unsigned int		idx;

  init_tab();
  idx = 0;
  while (array[idx].func != NULL)
    {
      if (!my_strcmp(buf, array[idx].keys))
	{
	  array[idx].func(inf, fd);
	  return ;
	}
      ++idx;
    }
}
