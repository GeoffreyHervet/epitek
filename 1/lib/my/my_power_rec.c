/*
** my_power_rec.c for my_power_rec.c in /home/hervet_g//work/piscine/lib/my
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Oct 13 18:33:50 2010 geoffrey hervet
** Last update Wed Oct 13 18:33:53 2010 geoffrey hervet
*/

int     my_power_rec(int nb, int power)
{
  if (!power)
    return (1);
  return (nb * my_power_rec(nb, (power - 1)));
}
