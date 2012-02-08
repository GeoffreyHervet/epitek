/*
** my_swap.c for my_swap.c in /home/hervet_g//afs/rendu/piscine/Jour_04
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Oct  7 10:33:42 2010 geoffrey hervet
** Last update Fri Oct  8 21:25:45 2010 geoffrey hervet
*/


int	my_swap(int *a, int *b)
{
  int   c;

  c = *a;
  *a = *b;
  *b = c;
  return (0);
}
