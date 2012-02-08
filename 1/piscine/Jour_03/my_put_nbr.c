/*
** my_put_nbr.c for my_put_nbr in /home/hervet_g//work/piscine/Jour_03
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Wed Oct  6 22:32:07 2010 geoffrey hervet
** Last update Thu Oct  7 20:48:21 2010 geoffrey hervet
*/

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      nb = - nb;
      my_putchar('-');
    }
  if (nb / 10)
    {
      my_put_nbr(nb / 10);
    }
  my_putchar(nb % 10 + '0');
}
