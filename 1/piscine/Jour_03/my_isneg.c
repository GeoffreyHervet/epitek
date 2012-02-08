/*
** my_isneg.c for my_isneg in /home/hervet_g//afs/rendu/piscine/Jour_03
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Oct  6 14:46:06 2010 geoffrey hervet
** Last update Wed Oct  6 17:38:56 2010 geoffrey hervet
*/

int	my_isneg (int n)
{
  if (n >= 0)
    {
      my_putchar ('P');
      return (0);
    }
  my_putchar ('N');
  return (0);
}
