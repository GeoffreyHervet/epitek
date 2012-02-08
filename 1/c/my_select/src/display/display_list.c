/*
** display_list.c for my_select in /home/hervet_g//work/projets/my_select
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Jan 15 13:24:09 2011 geoffrey hervet
** Last update Sun Jan 16 02:09:24 2011 geoffrey hervet
*/

#include		<curses.h>
#include		<term.h>

#include		"libmy.h"
#include		"my_select.h"

#include		"clear_window.h"
#include		"display/display_list.h"
#include		"display/display_item.h"
#include		"move_cursor.h"
#include		"put_cap.h"

static void		setval(int *a,
			       int val_a,
			       int *b,
			       int val_b)
{
  *a = val_a;
  *b = val_b;
}

static void		setzero(int *a,
				int *b,
				int *c)
{
  *a = 0;
  *b = 0;
  *c = 0;
}

static void		calc_coor(t_infos *inf,
				  t_list_db *item,
				  t_coords *coo)
{
  static int		col = 0;
  static int		row = 0;
  static int		col_w = 0;

  if (inf == NULL)
    setzero(&col, &row, &col_w);
  else if (col != -1)
    {
      if ((row < inf->window->row) &&
	  ((col + (int) my_strlen(item->data)) > inf->window->col))
	col = -1;
      coo->col = col;
      coo->row = row++;
      col_w = GET_MAX(col_w, (signed int) my_strlen(item->data));
      if (row >= inf->window->row)
	{
	  col += col_w + 1;
	  row = 0;
	  col_w = 0;
	}
    }
  if (col == -1)
    setval(&(coo->col), -1, &(coo->row), -1);
}

void			display_list(t_infos *inf,
				     const int fd)
{
  t_list_db		*tmp;
  t_coords		cur;

  calc_coor(NULL, NULL, NULL);
  if (inf->window->col < inf->min_w)
    my_putstr("Window is too small !\n", 2);
  else
    {
      tmp = inf->begin;
      clear_window();
      while (tmp != NULL)
	{
	  if (tmp->coords.col == 0)
	    {
	      calc_coor(inf, tmp, &cur);
	      tmp->coords = cur;
	    }
	  if (tmp->coords.col != -1)
	    display_item(tmp, NULL, fd);
	  tmp = tmp->next;
	  if (tmp == inf->begin)
	    tmp = NULL;
	}
    }
  move_cursor(&(inf->cursor_item->coords));
}
