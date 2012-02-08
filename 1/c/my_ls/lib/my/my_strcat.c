/*
** my_strcat.c for my in /home/hervet_g//work/projets/my_ls/lib/my
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Dec 15 11:17:09 2010 geoffrey hervet
** Last update Wed Dec 15 11:32:17 2010 geoffrey hervet
*/

#include	<stdlib.h>

#include	"libmy.h"

char		*my_strcat(char *left, char *right)
{
  char		*ret;
  int		ret_size;
  int		idx;

  ret_size = my_strlen(left) + my_strlen(right) + 2;
  if ((ret = malloc(sizeof(*ret) * ret_size)) == NULL)
    return (NULL);
  ret[ret_size] = 0;
  ret[ret_size - 1] = 0;
  ret_size = 0;
  while (left[ret_size])
    {
      ret[ret_size] = left[ret_size];
      ++ret_size;
    }
  idx = 0;
  while (right[idx])
    ret[ret_size++] = right[idx++];
  return (ret);
}
