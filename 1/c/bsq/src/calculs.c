/*
** calculs.c for bsq in /home/hervet_g//work/projets/c/bsq
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Nov 12 12:44:07 2010 geoffrey hervet
** Last update Sat Nov 13 15:09:25 2010 geoffrey hervet
*/

#include	<stdlib.h>

#include	"header.h"
#include	"lib.h"
#include	"calculs.h"

static void	save_size(t_file *f, int x, int y, int size)
{
  if (size > f->square_size)
    {
      f->square_size = size;
      f->square_x = x;
      f->square_y = y;
     }
}

static int	is_square(t_file *f, int x, int y, int size)
{
  int	tmp;

  tmp = y - 1;
  while (++tmp <= y + size)
    {
      if ((f->tab[tmp] == NULL) || (f->tab[tmp][x + size - 1] != CHAR_OK))
	return (0);
    }
  tmp = x - 1;
  while (++tmp <= x + size)
    {
      if (f->tab[y][tmp] == 0 || (f->tab[y + size - 1][tmp] != CHAR_OK))
	return (0);
    }
  return (1);

}

static void	square_search(t_file *f)
{
  int		x;
  int		y;
  int		size;

  x = 0;
  y = 0;
  while (f->tab[y][x])
    {
      size = 0;
      while (is_square(f, x, y, ++size));
      save_size(f, x, y, size - 1);
      if (!f->tab[y][++x])
	{
	  y++;
	  x = 0;
	}
      if (!f->tab[y])
	return ;
    }
}

int		do_calculs(t_file *f)
{
  f->square_x = 0;
  f->square_y = 0;
  f->square_size = 0;
  square_search(f);
  return (0);
}
