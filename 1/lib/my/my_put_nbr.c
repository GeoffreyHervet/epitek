/*
** my_put_nbr.c for my_put_nbr.c in /home/hervet_g//work/piscine/lib/my
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Oct 13 16:12:07 2010 geoffrey hervet
** Last update Wed Oct 13 17:37:11 2010 geoffrey hervet
*/

int	my_put_nbr(int nb)
{
  int	n;
  int	i;

  i = 1;
  if (nb < 0)
    {
      n = - nb;
      my_putchar('-');
    }
  else
    n = nb;
  while (n / 10)
    {
      i = i + 1;
      n = n / 10;
    }
  n = (nb < 0) ? - nb : nb;
  while (i)
    {
      i = i - 1;
      my_putchar((n / my_power_rec(10, i)) + '0');
      n = n % my_power_rec(10, i);
    }
  my_putchar('\n');
  return (nb);
}
