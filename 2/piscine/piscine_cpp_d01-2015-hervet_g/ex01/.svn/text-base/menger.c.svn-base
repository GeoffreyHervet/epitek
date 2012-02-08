/*
** menger.c for ex01 in /home/hervet_g/piscine/d01/piscine_cpp_d01-2015-hervet_g/ex01
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Jan 04 12:41:40 2012 geoffrey hervet
** Last update Wed Jan 04 12:41:40 2012 geoffrey hervet
*/


#include <stdio.h>

static void algo(unsigned int size, unsigned int x, unsigned int y, unsigned int lev)
{
  if (size)
  {
    size = size / 3;
    printf("%03d %03d %03d\n", size, size + x, size + y);
    if (lev--)
    {
      algo(size, x,		y,		lev);
      algo(size, x,		y + size,	lev);
      algo(size, x,		y + size *  2,	lev);
      algo(size, x + size,	y,		lev);

      algo(size, x + size,	y + size * 2,	lev);
      algo(size, x + 2 * size, 	y, 		lev);
      algo(size, x + 2 * size, 	y + size,	lev);
      algo(size, x + 2 * size, 	y + size * 2, lev);
    }
  }
}

void	menger(unsigned int size, unsigned int lev)
{
  if (size/3 && lev)
    algo(size, 0, 0, lev - 1);
}

