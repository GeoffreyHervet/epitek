/*
** display.c for 101 in /home/hervet_g//work/projets/maths/101
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Nov 23 16:06:36 2010 geoffrey hervet
** Last update Wed Nov 24 20:24:24 2010 geoffrey hervet
*/

#include	<stdio.h>

#include	"display.h"
#include	"lib.h"

void		display_matrice(int **matrice, int length)
{
  int		x;
  int		y;

  y = -1;
  while (matrice[++y])
    {
      x = -1;
      while (++x < length)
	{
	  my_putnbr_espace(matrice[y][x]);
	  my_putchar(' ');
	}
      my_putchar('\n');
    }
}

void		display_vector(int *vector, int length)
{
  int		x;

  x = -1;
  while (++x < length)
    {
      my_putnbr_espace(vector[x]);
      my_putchar('\n');
    }
}

void		display_vector_x(double *vector, int length)
{
  int		x;

  x = -1;
  while (++x < length)
    printf("%6.3f\n", vector[x]);
}
