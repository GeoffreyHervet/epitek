/*
** drawing.c for ex03 in /home/hervet_g/piscine/d01/piscine_cpp_d01-2015-hervet_g/ex03
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Jan 04 17:50:04 2012 geoffrey hervet
** Last update Wed Jan 04 17:50:04 2012 geoffrey hervet
*/

#include	<unistd.h>
#include	<stdio.h>

#include	"drawing.h"

void draw_square(uint32_t **img,
		 t_point  *orig,
                 size_t   size,
                 uint32_t color)
{
  for (unsigned int y = 0; y < size; y++)
    for (unsigned int x = 0; x < size; x++)
      img[y + orig->y][orig->x + x] = color;
}
