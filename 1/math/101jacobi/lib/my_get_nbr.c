/*
** my_get_nbr.c for  in /home/hervet_g//work/projets/maths/101
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Nov 23 16:32:09 2010 geoffrey hervet
** Last update Tue Nov 23 18:22:05 2010 geoffrey hervet
*/

#include	"lib.h"

int		my_get_nbr(char *nb)
{
  int		res;
  int		nb_pos;

  res = 0;
  nb_pos = 0;
  while (nb[nb_pos])
    res = res * 10 + nb[nb_pos++] - '0';
  return (res);
}
