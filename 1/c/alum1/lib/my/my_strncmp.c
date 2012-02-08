/*
** my_strncmp.c for my in /afs/epitech.net/users/epitech_2015/hervet_g/rendu/c/alum1/lib/my
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Feb 11 18:26:51 2011 geoffrey hervet
** Last update Fri Feb 11 18:26:51 2011 geoffrey hervet
*/

#include	"libmy.h"

int		my_strncmp(const char *s1,
                           const char *s2,
                           unsigned int size)
{
  int		idx;

  idx = 0;
  while ((s1[idx] || s2[idx]) && size--)
  {
    if (!s1[idx] || !s2[idx] || (s1[idx] != s2[idx]))
      return ((s1[idx] > s2[idx]) ? 1 : -1);
    idx++;
  }
  return (0);
}
