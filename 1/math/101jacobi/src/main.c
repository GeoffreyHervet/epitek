/*
** main.c for 101] in /home/hervet_g//work/projets/maths/101
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Nov 23 09:50:34 2010 geoffrey hervet
** Last update Thu Nov 25 13:46:17 2010 geoffrey hervet
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>

#include	"101jacobi.h"
#include	"inits.h"
#include	"display.h"
#include	"lib.h"
#include	"calculs.h"
#include	"error.h"

static void	result(int **matrice, int *vector, double **vector_x, int size)
{
  printf("Dimension\nn=%d\n", size);

  printf("Matrice A\n");
  display_matrice(matrice, size);

  printf("Vecteur B\n");
  display_vector(vector, size);

  printf("Convergence atteinte en %d iterations\n", (int) vector_x[1][0]);

  printf("Vecteur solution\n");
  display_vector_x(vector_x[0], size);

  printf("Erreur = %E\n", get_error(matrice, vector_x, vector, size));
}

static void	do_jacobi(int size)
{
  int		**matrice;
  int		*vector;
  double	**vector_x;
  int		idx;

  if ((matrice = create_matrice(size)) == NULL)
    return ;

  init_matrice(matrice, size);
  vector = create_vector(matrice, size);

  vector_x = calcul_vect_x(matrice, vector, size);

  result(matrice, vector, vector_x, size);

  idx = -1;
  while (++idx < size)
    free(matrice[idx]);
  free(matrice);
  free(vector);
}

int		main(int ac, char **av)
{
  if (ac <= 1)
    return (0);

  do_jacobi(my_get_nbr(av[1]));

  return (0);
}
