/*
** header for norme in /
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.eu>
** 
** Started on  Mon Jan 01 00:00:00 2011 geoffrey hervet
** Last update Mon Jan 01 00:00:00 2011 geoffrey hervet
*/

#include	<stdlib.h>

#include	"my_strlen.h"

int		my_strlen(const char *str)
{
  int		ret;

  ret = 0;
  while (str != NULL && str[ret])
    ret++;
  return (ret);
}
