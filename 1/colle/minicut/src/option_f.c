/*
** option_f.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/ok/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue May 17 21:01:55 2011 geoffrey hervet
** Last update Tue May 17 21:01:55 2011 geoffrey hervet
*/

#include	<stdlib.h>

#include	"types.h"

#include	"my_strlen.h"
#include	"option_f.h"

static void	set_zero(char *str, int beg, int end)
{
  while (beg < end)
    str[beg++] = 0;
}

static void	reset_str(char *str, int len)
{
  int		idx;
  int		dec;

  idx = 0;
  dec = 0;
  while (idx + dec < len)
  {
    if (str[idx + dec])
    {
      str[idx] = str[idx + dec];
      idx++;
    }
    else
      dec++;
  }
  str[idx] = 0;
}

void		option_f(t_opt_f *opts, char *str)
{
  int		len;
  int		idx;
  int		idx2;

  len = my_strlen(str);
  idx2 = len;
  while (opts != NULL)
  {
    idx = opts->delim[1];
    set_zero(str, idx, idx2);
    idx2 = opts->delim[0] - 1;
    opts = opts->next;
  }
  reset_str(str, len);
}
