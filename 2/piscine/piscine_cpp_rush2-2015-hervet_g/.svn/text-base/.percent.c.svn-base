/*
** header for norme in /
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.eu>
** 
** Started on  Mon Jan 01 00:00:00 2011 geoffrey hervet
** Last update Mon Jan 01 00:00:00 2011 geoffrey hervet
*/

#include	<stdio.h>
#include	<string.h>

int main(int ac, char **av)
{
  int i = 0;
  if (ac < 2)
    return 0;
  for(i = 2; i < ac; i++)
    if (0 == strcmp(av[1], av[i]))
    {
      printf("%d", (100 * (i - 1)) / (ac - 1));
      return 0;
    }
  return 0;
}

