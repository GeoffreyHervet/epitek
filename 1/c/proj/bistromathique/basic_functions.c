/*
** basic_functions.c for bistro in /home/hervet_g//public/projets/Bistromatique
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Nov  3 15:12:59 2010 geoffrey hervet
** Last update Wed Nov  3 15:13:00 2010 geoffrey hervet
*/

#include	"bistromathique.h"
#include	<unistd.h>

int		my_strlen(char *str)
{
  int		size;

  size = 0;
  while (str[size])
    size++;
  return (size);
}

int		my_putchar(char c)
{
  return (write(1, &c, 1));
}

int		my_putstr(char *s)
{
  return (write(1, s, my_strlen(s)));
}

int		char_in_str(char c, char *str)
{
  int		i;

  i = 0;
  while (str[i])
    if (str[i] == c)
      return (1);
  return (0);
}

int		str_only_digits(char *str, int start, int end, char *base)
{
  while (str[start] && start <= end)
    {
      if (!char_in_str(str[start], base))
	return (0);
    }
  return (1);
}
