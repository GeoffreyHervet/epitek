/*
** pyramid.c for ex05 in /home/hervet_g/piscine/d01/piscine_cpp_d01-2015-hervet_g/ex05
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Jan 04 21:18:40 2012 geoffrey hervet
** Last update Wed Jan 04 21:18:40 2012 geoffrey hervet
*/

#include <stdio.h>

void	rec(int x, int y, int sum, int size, int ** map)
{
  if (!size)
  {
    if (res == -1 || res > sum)
      res = sum;
    return;
  }
  rec(x, y+1, sum + map[y][x], size - 1, map);
  rec(x+1, y+1, sum + map[y][x], size - 1, map);
}

int	pyramid_path(int size, int ** map)
{
  rec(0, 0, 0, size, map);
  return res;
}
