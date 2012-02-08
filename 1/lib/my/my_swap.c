/*
** my_swap.c for my_swap.c in /home/hervet_g//work/piscine/Jour_04
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Thu Oct  7 10:17:29 2010 geoffrey hervet
** Last update Wed Oct 13 17:40:09 2010 geoffrey hervet
*/

int     my_swap(int *a, int *b)
{
  int   c;

  c = *a;
  *a = *b;
  *b = c;
  return (0);
}
