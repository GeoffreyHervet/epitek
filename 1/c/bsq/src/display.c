/*
** display.c for bsq in /home/hervet_g//work/projets/c/bsq
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Nov 13 13:53:02 2010 geoffrey hervet
** Last update Sat Nov 13 14:50:45 2010 geoffrey hervet
*/

#include        <stdlib.h>

#include        "header.h"
#include	"lib.h"
#include	"display.h"

static int             on_replacement(int x, int y, t_file *f)
{
  if (((x >= f->square_x) && (x <= (f->square_x + f->square_size - 1))) &&
      ((y >= f->square_y) && (y <= (f->square_y + f->square_size - 1))))
    return (1);
  return (0);
}

void            display(t_file *f)
{
  int           x;
  int           y;

  x = 0;
  y = 0;
  while (f->tab[y] != NULL)
    {
      x = 0;
      while (f->tab[y][x])
        {
          if (on_replacement(x, y, f))
	    my_putchar(CHAR_REPLACE);
          else
            my_putchar(f->tab[y][x]);
          x++;
        }
      y++;
      my_putchar(CHAR_NEW_LINE);
    }
}
