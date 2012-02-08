/*
** my_strdup.c for my_strdup.c in /home/hervet_g//work/piscine/Jour_08
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Oct 15 12:01:11 2010 geoffrey hervet
** Last update Fri Oct 15 14:00:06 2010 geoffrey hervet
*/

#include <stdlib.h>

char	*my_strcpy(char *dest, char *src);

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}

char	*my_strdup(char *str)
{
  char	*s;

  s = malloc((sizeof(*s) * my_strlen(str)) + 1);
  s = my_strcpy(s, str);
  return (s);
}
