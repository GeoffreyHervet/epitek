/*
** my_factorielle_it.c for my_factorielle_it in /home/hervet_g//work/piscine/Jour_05
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Oct  8 09:41:32 2010 geoffrey hervet
** Last update Sun Oct 10 16:18:34 2010 geoffrey hervet
*/

int	my_factorielle_it(int nb)
{
  int	result;

  result = 1;
  if (nb > 12 || nb < 0)
    return (0);
  if (!nb)
      return (1);
  while (nb)
    {
      result = result * nb;
      nb = nb - 1;
    }
  return (result);
}
