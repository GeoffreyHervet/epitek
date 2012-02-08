/*
** my_power_it.c for my_power_it.c in /home/hervet_g//work/piscine/lib/my
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Oct 13 18:34:13 2010 geoffrey hervet
** Last update Wed Oct 13 18:34:59 2010 geoffrey hervet
*/

int     my_power_it(int nb, int power)
{
  int   result;

  result = 1;
  while (power)
    {
      if (nb > 0)
        {
          result = result * nb;
          power = power - 1;
        }
      else
        {
          result = result / nb;
          power = power + 1;
        }
    }
  return (result);
}
