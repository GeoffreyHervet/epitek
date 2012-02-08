/*
** is_function.c for marvin in /home/hervet_g//work/rush/marvin/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Nov 26 21:03:34 2010 geoffrey hervet
** Last update Fri Nov 26 23:00:21 2010 geoffrey hervet
*/

#include	<stdlib.h>

#include	"lib.h"
#include	"marvin.h"
#include	"check.h"

int		check_par(t_marvin *marvin)
{
  int		idx;
  int		nb_par;
  int		have_par;

  idx = -1;
  have_par = 0;
  nb_par = 0;
  while (++idx < marvin->len_str)
    {
      if (marvin->str[idx] == ')')
	if (!nb_par)
	  return (-1);
	else
	  --nb_par;
      else if (marvin->str[idx] == '(')
	{
	  if (!have_par)
	    have_par = 1;
	  ++nb_par;
	}
    }
  if (nb_par)
    return (-1);
  return (0);
}
