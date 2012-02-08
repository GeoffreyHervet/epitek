/*
** my_find_prime_sup.c for my_find_prime_sup.c in /home/hervet_g//work/piscine/lib/my
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Oct 13 22:48:41 2010 geoffrey hervet
** Last update Wed Oct 13 22:48:47 2010 geoffrey hervet
*/

int	my_find_prime_sup_test(int nb)
{
  int	n;

  if (nb <= 0)
    return (0);
  n = 2;
  while (n < nb)
    {
      if (nb % n == 0)
	return (1);
      n = n + 1;
    }
  return (0);
}


int	my_find_prime_sup(int nb)
{
  while (my_find_prime_sup_test(nb))
    nb = nb + 1;
  return (nb);
}
