/*
** main.c for  in /home/hervet_g/mynm
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun Mar  4 15:51:46 2012 geoffrey hervet
** Last update Sun Mar  4 15:51:48 2012 geoffrey hervet
*/

#include <stdlib.h>

char		*get_file_name(int ac, char **av)
{
  static int	idx = 0;

  if (ac == 1 && idx == 0)
  {
    ++idx;
    return ("a.out");
  }
  if (ac != 1 && ++idx < ac)
    return (av[idx]);
  return (NULL);
}

