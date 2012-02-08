/*
** key_spe.c for my_select in /home/hervet_g//work/projets/my_select
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Jan 15 21:55:08 2011 geoffrey hervet
** Last update Sun Jan 16 01:12:44 2011 geoffrey hervet
*/

#include		<unistd.h>

#include		<stdlib.h>

#include		"libmy.h"
#include		"my_select.h"

#include		"action/key.h"
#include		"display/display_list.h"
#include		"clear_window.h"

void			select_item(t_infos *inf,
				    const int fd)

{
  if (inf->cursor_item->flags & FL_SELECT)
    inf->cursor_item->flags &= ~FL_SELECT;
  else
    inf->cursor_item->flags |= FL_SELECT;
  down_key(inf, fd);
}

void			delete_itemb(t_infos *inf,
				    const int fd)
{
  t_list_db		*tmp;

  if (inf->cursor_item == inf->cursor_item->next)
    escape_prog(inf, fd);
  tmp = inf->cursor_item;
  tmp->next->prev = tmp->prev;
  tmp->prev->next = tmp->next;
  inf->cursor_item = inf->cursor_item->prev;
  if (tmp == inf->begin)
    inf->begin = inf->begin->prev;
  free(tmp);
  tmp = inf->cursor_item;
  tmp->flags |= FL_HOVER;
  while (tmp != NULL)
    {
      tmp->coords.col = 0;
      tmp->coords.row = 0;
      tmp = tmp->next;
      if (tmp == inf->cursor_item)
	tmp = NULL;
    }
  display_list(inf, fd);
}

void			delete_item(t_infos *inf,
				    const int fd)
{
  t_list_db		*tmp;

  if (inf->cursor_item == inf->cursor_item->next)
    escape_prog(inf, fd);
  tmp = inf->cursor_item;
  tmp->next->prev = tmp->prev;
  tmp->prev->next = tmp->next;
  inf->cursor_item = inf->cursor_item->next;
  if (tmp == inf->begin)
    inf->begin = inf->begin->next;
  free(tmp);
  tmp = inf->cursor_item;
  tmp->flags |= FL_HOVER;
  while (tmp != NULL)
    {
      tmp->coords.col = 0;
      tmp->coords.row = 0;
      tmp = tmp->next;
      if (tmp == inf->cursor_item)
	tmp = NULL;
    }
  display_list(inf, fd);
}

void			validate(t_infos *inf,
				 const int fd)
{
  t_list_db		*tmp;

  clear_window();
  if (close(fd) == -1)
    my_putstr(ERR_CLOSE, 2);
  inf->begin->prev->next = NULL;
  tmp = inf->begin;
  while (tmp != NULL)
    {
      if (inf->begin->flags & FL_SELECT)
  	{
  	  my_putstr(tmp->data, 1);
  	  my_putchar(' ', 1);
  	}
      inf->begin = tmp->next;
      free(tmp);
      tmp = inf->begin;
    }
  exit(0);
}
void			escape_prog(t_infos *inf,
				    const int fd)
{
  t_list_db		*tmp;

  clear_window();
  if (close(fd) == -1)
    my_putstr(ERR_CLOSE, 2);
  inf->begin->prev->next = NULL;
  tmp = inf->begin;
  while (tmp != NULL)
    {
      inf->begin = tmp->next;
      free(tmp);
      tmp = inf->begin;
    }
  exit(0);
}
