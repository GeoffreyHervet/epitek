/*
** error.c for 101 in /home/hervet_g//work/projets/maths/101
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Nov 24 21:52:58 2010 geoffrey hervet
** Last update Thu Nov 25 13:41:48 2010 geoffrey hervet
*/

#include	<stdlib.h>
#include	<math.h>

#include	"101jacobi.h"
#include	"error.h"

static double	sqr(double a)
{
  return (a * a);
}

double		get_error(int **matrice, double **vector_x, int *vector, int size)
{
  int		i;
  int		j = -1;
  double	*matr_error;
  double	error = 0;

  if ((matr_error = malloc(sizeof(*matr_error) * size)) == NULL)
    return (-1);
  while (++j < size)
    {
      i = -1;
      matr_error[j] = 0;
      while (++i < size)
	{
	  matr_error[j] += (double) matrice[j][i] * vector_x[0][j];
	}
      error += sqr(matr_error[j] -(double) vector[j]);
    }
  free(matr_error);
  return (sqrt(error));
}
