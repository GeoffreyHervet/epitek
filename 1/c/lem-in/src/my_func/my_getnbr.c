/*
** my_getnbr.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/lemin/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Apr 12 12:18:38 2011 geoffrey hervet
** Last update Tue Apr 12 12:18:38 2011 geoffrey hervet
*/

#include	<stdlib.h>

#include	"my_getnbr.h"

int		my_getnbr(const char *str)
{
  int		nbr;

  nbr = 0;
  while (str != NULL && *str)
    nbr = nbr * 10 + *str++ - '0';
  return (nbr);
}
