/*
** menger.c for ex01 in /home/hervet_g/piscine/d01/piscine_cpp_d01-2015-hervet_g/ex01
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Jan 04 12:41:40 2012 geoffrey hervet
** Last update Wed Jan 04 12:41:40 2012 geoffrey hervet
iiuuu*/


#include <stdio.h>

#include "drawing.h"
#include "bitmap.h"

static unsigned int getColor(int rec)
{
  rec = 0xFF / rec;

  return (rec  | (rec << 8) | (rec << 16));
}

static void algo(int size, unsigned int x, unsigned int y, int lev, unsigned int **img, int rec)
{
  rec++;
  if (size)
  {
    size = size / 3;
    t_point p = {x + size, y + size};
    draw_square(img, &p, size, getColor(lev+1));
    if (lev--)
    {
      algo(size, x,		y,		lev, img, rec);
      algo(size, x,		y + size,	lev, img, rec);
      algo(size, x,		y + size *  2,	lev, img, rec);
      algo(size, x + size,	y,		lev, img, rec);

      algo(size, x + size,	y + size * 2,	lev, img, rec);
      algo(size, x + 2 * size, 	y, 		lev, img, rec);
      algo(size, x + 2 * size, 	y + size,	lev, img, rec);
      algo(size, x + 2 * size, 	y + size * 2,	lev, img, rec);
    }
  }
}

void	menger(int size, int lev, unsigned int **img)
{
  if (size/3 && lev)
    algo(size, 0, 0, lev - 1, img, 1);
}
