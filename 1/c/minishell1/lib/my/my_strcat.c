/*
** my_strcat.c for my in /home/hervet_g//work/lib/my
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Dec 15 11:17:09 2010 geoffrey hervet
** Last update Sun Jan  2 11:31:55 2011 geoffrey hervet
*/

#include	<stdlib.h>

#include	"libmy.h"

char		*my_strcat(const char *left,
			   const char *right)
{
  char		*ret;
  int		ret_size;
  int		idx;

  ret_size = my_strlen(left) + my_strlen(right) + 1;
  if ((ret = malloc(sizeof(*ret) * ret_size)) == NULL)
    return (NULL);
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
