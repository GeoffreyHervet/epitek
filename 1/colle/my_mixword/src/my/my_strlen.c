/*
** my_strlen.c for my in /afs/epitech.net/users/epitech_2015/hervet_g/public/KHOL/src/my
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed May 04 19:26:16 2011 geoffrey hervet
** Last update Wed May 04 19:26:16 2011 geoffrey hervet
*/

#include	<stdlib.h>

#include	"my_strlen.h"

int		my_strlen(const char *str)
{
  int		idx;

  idx = 0;
  while (str != NULL && str[idx])
    idx++;
  return (idx);
}
