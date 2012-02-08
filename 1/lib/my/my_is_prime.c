/*
** my_is_prime.c for my_is_prime.c in /home/hervet_g//work/piscine/lib/my
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Oct 13 22:48:01 2010 geoffrey hervet
** Last update Wed Oct 13 22:48:03 2010 geoffrey hervet
*/

int	my_is_prime(int nb)
{
  int	n;
  int	lim;

  if (nb <= 0)
    return (0);
  if ((nb % 2) == 0)
    return (0);
  lim = (nb / 2) + 1;
  n = 3;
  while (n < lim)
    {
      if (nb % n == 0)
	return (0);
      n = n + 2;
    }
  return (1);
}
