/*
** my_factorielle_rec.c for my_factorielle_rec in /home/hervet_g//work/piscine/Jour_05
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Oct  8 09:41:32 2010 geoffrey hervet
** Last update Mon Oct 11 18:45:50 2010 geoffrey hervet
*/

int	my_factorielle_rec(int nb)
{
  if (nb == 0)
    return (1);
  if (nb < 0 || nb > 12)
    return (0);
  return ((nb == 1) ? 1 : (nb * my_factorielle_rec(nb - 1)));
}
