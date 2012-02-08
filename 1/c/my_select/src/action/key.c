/*
** key.c for my_select in /home/hervet_g//work/projets/my_select
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Jan 15 17:53:42 2011 geoffrey hervet
** Last update Sun Jan 16 01:12:59 2011 geoffrey hervet
*/

#include		<curses.h>
#include		<term.h>

#include		"libmy.h"
#include		"my_select.h"

#include		"action/key.h"
#include		"display/display_item.h"
#include		"move_cursor.h"

void		upper_key(t_infos *inf,
			  const int fd)
{
  t_list_db	*tmp;

  tmp = inf->cursor_item;
  tmp->flags &= ~FL_HOVER;
  display_item(tmp, &(tmp->coords), fd);
  tmp = tmp->prev;
  while (tmp->coords.col == -1)
    tmp = tmp->prev;
  tmp->flags |= FL_HOVER;
  display_item(tmp, &(tmp->coords), fd);
  move_cursor(&(tmp->coords));
  inf->cursor_item = tmp;
}

void		left_key(t_infos *inf,
			     const int fd)
{
  t_list_db	*tmp;
  t_list_db	*actu;

  actu = inf->cursor_item;
  tmp = inf->cursor_item;
  tmp->flags &= ~FL_HOVER;
  display_item(tmp, &(tmp->coords), fd);
  tmp = tmp->prev;
  while (tmp->coords.row != actu->coords.row)
    tmp = tmp->prev;
  tmp->flags |= FL_HOVER;
  display_item(tmp, &(tmp->coords), fd);
  move_cursor(&(tmp->coords));
  inf->cursor_item = tmp;
}

void		right_key(t_infos *inf,
			  const int fd)
{
  t_list_db	*tmp;
  t_list_db	*actu;

  actu = inf->cursor_item;
  tmp = inf->cursor_item;
  tmp->flags &= ~FL_HOVER;
  display_item(tmp, &(tmp->coords), fd);
  tmp = tmp->next;
  while (tmp->coords.row != actu->coords.row)
    tmp = tmp->next;
   tmp->flags |= FL_HOVER;
  display_item(tmp, &(tmp->coords), fd);
  move_cursor(&(tmp->coords));
  inf->cursor_item = tmp;
}

void		down_key(t_infos *inf,
			 const int fd)
{
  t_list_db	*tmp;

  tmp = inf->cursor_item;
  tmp->flags &= ~FL_HOVER;
  display_item(tmp, &(tmp->coords), fd);
  tmp = tmp->next;
  while (tmp->coords.col == -1)
    tmp = tmp->next;
  tmp->flags |= FL_HOVER;
  display_item(tmp, &(tmp->coords), fd);
  move_cursor(&(tmp->coords));
  inf->cursor_item = tmp;
}
