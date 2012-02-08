/*
** my_put_nbr_espace.c for  in /home/hervet_g//work/projets/maths/101
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Nov 23 16:35:58 2010 geoffrey hervet
** Last update Tue Nov 23 16:48:49 2010 geoffrey hervet
*/

#include	"lib.h"

void		my_putnbr_espace(int nb)
{
  int		power;
  int		tmp;

  tmp = nb;
  power = 1;
  if (nb < 0)
    my_putchar('-');
  else
    my_putchar(' ');
  while ((nb > 9) || (nb < -9))
    {
      power *= 10;
      nb /= 10;
    }
  while (power)
    {
      my_putchar('0' + ABS(tmp / power));
      tmp %= power;
      power /= 10;
    }
}
