/*
** inits.c for 101 in /home/hervet_g//work/projets/maths/101
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Nov 23 16:24:39 2010 geoffrey hervet
** Last update Thu Nov 25 09:22:17 2010 geoffrey hervet
*/

#include	<stdlib.h>

#include	"inits.h"

int		**create_matrice(int length)
{
  int		**matrice;
  int		x;
  int		y;

  if ((matrice = malloc(sizeof(*matrice) * (length + 2))) == NULL)
    return (NULL);
  y = -1;
  while (++y < length)
    {
      if ((matrice[y] = malloc(sizeof(*matrice[y]) * length + 1)) == NULL)
	return (NULL);
      x = -1;
      while (++x < length)
	matrice[y][x] = 0;
    }
  matrice[y] = NULL;
  return (matrice);
}

int		**init_matrice(int **matrice, int length)
{
  int		i;

  i = 0;
  while (i < length)
    {
      matrice[i][i] = 2;
      if ((i + 1) < length)
	{
	  matrice[i][i + 1] = -1;
	  matrice[i + 1][i] = -1;
	}
      ++i;
    }
  return (matrice);
}

int		*create_vector(int **matrice, int length)
{
  int		*vector;
  int		i;
  int		j;

  if ((vector = malloc(sizeof(*vector) * length)) == NULL)
    return (NULL);
  i = 0;
  while (i < length)
    {
      j = 0;
      vector[i] = 0;
      while (j < length)
	vector[i] += matrice[i][j++];
      i++;
    }
  return (vector); 
}

double		**init_vector_x(int length)
{
  double	**vect;

  if (((vect = malloc(sizeof(*vect) * 3)) == NULL) ||
      ((vect[0] = malloc(sizeof(**vect) * (length + 1))) == NULL) ||
      ((vect[1] = malloc(sizeof(**vect) * (length + 1))) == NULL))
    return (NULL);
  vect[length] = NULL;
  while (length--)
    {
      vect[0][length] = 0;
      vect[1][length] = 0;
    }
  return (vect);
}
