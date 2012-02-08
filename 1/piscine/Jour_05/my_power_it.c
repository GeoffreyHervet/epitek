/*
** my_power_it.c for my_power_it.c in /home/hervet_g//work/piscine/Jour_05
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Oct  8 16:41:22 2010 geoffrey hervet
** Last update Mon Oct 11 18:46:41 2010 geoffrey hervet
*/

int	my_power_it(int nb, int power)
{
  int	result;

  result = 1;
  while (power)
    {
      if (power > 0)
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
