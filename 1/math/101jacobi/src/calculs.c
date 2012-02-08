/*
** calculs.c for 101 in /home/hervet_g//work/projets/maths/101
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Nov 24 09:56:59 2010 geoffrey hervet
** Last update Thu Nov 25 10:22:54 2010 geoffrey hervet
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<math.h>

#include	"101jacobi.h"
#include	"calculs.h"
#include	"inits.h"

static double	sqr(double a)
{
  return (a * a);
}

static void	swap_ptr(void *a, void *b)
{
  void		*c;

  c = a;
  a = b;
  b = c;
}

static void	reset_vect(double *vect, int size)
{
  while (size--)
    vect[size] = 0;
}

static int	conv_stop(int iterations, double **vector_x, int size)
{
  double	calc;

  if (!iterations)
    return (1);
  if (iterations >= MAX_IT)
    return (0);
  calc = 0;
  while (size--)
    calc += sqr(vector_x[!(iterations % 2)][size] - vector_x[iterations % 2][size]);
  calc = sqrt(calc);
  if (calc < 10e-6)
    return (0);
  return (1);
}

double		**calcul_vect_x(int **matrice, int *vector, int size)
{
  double	**vector_x;
  int		k;
  int		i;
  int		j;

  vector_x = init_vector_x(size);
  k = -1;
  while (conv_stop(++k, vector_x, size))
    {
      reset_vect(vector_x[k % 2], size);
      i = -1;
      while (++i < size)
	{
	  j = -1;
	  while (++j < size)
	    if (j != i)
	      vector_x[k % 2][i] += matrice[i][j] * vector_x[!(k % 2)][j];
	  vector_x[k % 2][i] =  (vector[i] - vector_x[k % 2][i]) / matrice[i][i];
	}
    }
  if (k % 2)
    swap_ptr(&vector_x[0], vector_x[1]);
  vector_x[1][0] = (double) k;
  return (vector_x);
}
