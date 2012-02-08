/*
** fonctions.c for fonctions.c in /home/hervet_g//work/piscine/Jour_12/cat
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Oct 21 15:04:17 2010 geoffrey hervet
** Last update Thu Oct 21 16:10:35 2010 geoffrey hervet
*/

#include	"fonctions.h"

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}
