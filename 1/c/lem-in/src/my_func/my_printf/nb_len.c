/*
** nb_len.c for nb_len in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu Nov 18 18:07:35 2010 tom-brent yau
** Last update Fri Nov 19 23:55:09 2010 tom-brent yau
*/

#include	<stdarg.h>
#include	"my_printf.h"

int	nb_len(int nb)
{
  int	nb_len;

  nb_len = 0;
  if (nb < 0)
    nb_len++;
  else if (nb == 0)
    return (1);
  while (nb)
    {
      nb = nb / 10;
      nb_len++;
    }
  return (nb_len);
}
