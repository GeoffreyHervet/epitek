/*
** my_power_rec.c for my_power_rec.c in /home/hervet_g//work/piscine/Jour_05
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Oct  8 16:41:22 2010 geoffrey hervet
** Last update Mon Oct 11 21:34:15 2010 geoffrey hervet
*/

int	my_power_rec(int nb, int power)
{
  if (power <= 0)
    return (1);
  if (power > 0)
    return (nb * my_power_rec(nb, (power - 1)));
}

int	main()
{
  int i;
  for(i=10; i < 300; i++)
    {
      printf("2^%d == %d\n", i,my_power_rec(2,i));
    }
}
