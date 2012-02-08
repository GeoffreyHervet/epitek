/*
** main.c for main.c in /home/hervet_g//work/projets/c/bsq
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Nov  3 14:10:52 2010 geoffrey hervet
** Last update Sat Nov 13 14:47:56 2010 geoffrey hervet
*/

#include	<stdlib.h>

#include	"header.h"
#include	"lib.h"
#include	"bsq.h"

static void	free_struct(t_file *f)
{
  int		tab_idx;

  tab_idx = -1;
  f = f;
  while (f->tab[++tab_idx])
    free(f->tab[tab_idx]);
  free(f);
}

int		main(int ac, char **av)
{
  t_file	*f;

  if ((f = malloc(sizeof(*f))) == NULL)
    {
      my_putstr(ERR_ALLOC);
      return (1);
    }
  if (ac > 1)
    if (do_bsq(av[1], f) == -1)
      {
	my_putstr(f->message);
	free_struct(f);
	return (1);
      }
  free_struct(f);
  return (0);
}
