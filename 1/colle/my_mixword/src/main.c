/*
** main.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/KHOL/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed May 04 19:46:46 2011 geoffrey hervet
** Last update Wed May  4 22:44:27 2011 tracy nelcha
*/

#include	<stdlib.h>

#include	"types.h"

#include	"my_putstr.h"
#include	"check_arg.h"
#include	"read_file.h"

int		main(int ac, char **av)
{
  t_infos	infos;

  if (check_arg(av, ac, &infos))
    return (EXIT_FAILURE);
  if (read_file(&infos))
    return (EXIT_FAILURE);
  while (infos.begin != NULL)
  {
    my_putstr(infos.begin->data, 1);
    my_putstr("\n", 1);
    infos.begin = infos.begin->next;
  }
  return (EXIT_SUCCESS);
}
