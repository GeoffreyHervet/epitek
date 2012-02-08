/*
** tab_to_2dtab.c for ex02 in /home/hervet_g/piscine/piscine_cpp_d02m-2015-hervet_g/ex02
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Jan 05 10:02:32 2012 geoffrey hervet
** Last update Thu Jan 05 10:02:32 2012 geoffrey hervet
*/

#include <stdlib.h>
#include <stdio.h>


void		tab_to_2dtab(int *tab, int length, int width, int ***res)
{
  int		**tmp;
  int		y;
  int		x;

  *res = NULL;
  if (NULL == (tmp = malloc(sizeof(tab) * (length))))
    return;
  for (y = 0; y < length; y++)
  {
    if (NULL == (tmp[y] = malloc(sizeof(*tab) * (width))))
      return ;
      for (x = 0; x < width; x++)
        tmp[y][x] = *tab++;
  }
  *res = tmp;
}
