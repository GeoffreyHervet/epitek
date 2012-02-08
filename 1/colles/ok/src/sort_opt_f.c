/*
** sort_opt_f.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/ok/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue May 17 21:31:54 2011 geoffrey hervet
** Last update Tue May 17 21:31:54 2011 geoffrey hervet
*/

#include	<stdlib.h>

#include	"types.h"
#include	"sort_opt_f.h"

static void	my_swap(int a[2], int b[2])
{
  int		c[2];

  c[0] = a[0];
  c[1] = a[1];
  a[0] = b[0];
  a[1] = b[1];
  b[0] = c[0];
  b[1] = c[1];
}

static int	kill_fonflicts(t_opt_f *begin)
{
  t_opt_f	*tmp;
  t_opt_f	*dec;

  dec = begin;
  while (dec != NULL && dec->next != NULL)
  {
    if ((dec->delim[0] >= dec->next->delim[0] &&
        dec->delim[0] <= dec->next->delim[1]) ||
       (dec->delim[0] == dec->next->delim[0] &&
        dec->delim[1] > dec->next->delim[1]))
    {
      tmp = dec->next->next;
      dec->delim[0] = dec->next->delim[0];
      if (dec->next->delim[1] > dec->delim[1])
        dec->delim[1] = dec->next->delim[1];
      dec->next = dec->next->next;
      free(tmp);
    }
    dec = dec->next;
  }
  return (0);
}

int		sort_opt_f(t_opt_f *begin)
{
  t_opt_f	*tmp;
  int		have_fhanged;

  have_fhanged = 1;
  while (have_fhanged)
  {
    tmp = begin;
    have_fhanged = 0;
    while (tmp->next != NULL)
    {
      if (tmp->delim[0] < tmp->next->delim[0])
      {
        have_fhanged = 1;
        my_swap(tmp->next->delim, tmp->delim);
      }
      tmp = tmp->next;
    }
  }
  return (kill_fonflicts(begin));
}
