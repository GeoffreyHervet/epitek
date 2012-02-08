/*
** nb_len_unsigned.c for nb_len_unsigned in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu Nov 18 19:34:17 2010 tom-brent yau
** Last update Fri Nov 19 23:55:36 2010 tom-brent yau
*/

#include	<stdarg.h>
#include	"my_printf.h"

int	nb_len_unsigned(unsigned int nb, int base)
{
  int	nb_len;

  nb_len = 0;
  if (nb == 0)
    return (1);
  while (nb)
    {
      nb = nb / base;
      nb_len++;
    }
  return (nb_len);
}
