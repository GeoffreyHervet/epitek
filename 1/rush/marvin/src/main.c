/*
** main.c for marvin in /home/hervet_g//work/rush/marvin/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Nov 26 20:30:12 2010 geoffrey hervet
** Last update Sat Nov 27 10:50:54 2010 geoffrey hervet
*/

#include	<stdlib.h>

#include	"lib.h"
#include	"marvin.h"
#include	"check.h"
#include	"repartition.h"

static t_marvin	*init_marvin(char *str)
{
  t_marvin	*marvin;

  marvin = malloc(sizeof(*marvin));
  if (!marvin)
    return (NULL);

  marvin->is_funct = NULL;
  marvin->str = str;
  marvin->len_str = my_strlen(str);

  return (marvin);
}

static int	marvin(char *str)
{
  t_marvin	*marvin;
  int		nb_par;

  marvin = init_marvin(str);
  if (marvin == NULL)
    return (-1);
  nb_par = check_par(marvin);
  if (nb_par == -1)
    return (-1);
  /* ERREUR DE SYNTAXE */
  repartition(marvin, nb_par);
  free(marvin);
  return (0);
}

int		main(int ac, char **av)
{
  if (ac == 2)
    {
      if (marvin(av[1]) == -1)
	return (1);
    }
  my_putchar('\n');
  return (0);
}
