/*
** sort_opt_c.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/ok/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue May 17 21:31:54 2011 geoffrey hervet
** Last update Tue May 17 21:31:54 2011 geoffrey hervet
*/

#include	<stdlib.h>

#include	"types.h"
#include	"sort_opt_c.h"

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

static int	kill_conflicts(t_opt_c *begin)
{
  t_opt_c	*tmp;
  t_opt_c	*dec;

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

int		sort_opt_c(t_opt_c *begin)
{
  t_opt_c	*tmp;
  int		have_changed;

  have_changed = 1;
  while (have_changed)
  {
    tmp = begin;
    have_changed = 0;
    while (tmp->next != NULL)
    {
      if (tmp->delim[0] < tmp->next->delim[0])
      {
        have_changed = 1;
        my_swap(tmp->next->delim, tmp->delim);
      }
      tmp = tmp->next;
    }
  }
  return (kill_conflicts(begin));
}
