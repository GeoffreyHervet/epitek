/*
** epurstr.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/lemin/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  lun. avril 11 10:19:23 2011 geoffrey hervet
** Last update lun. avril 11 10:19:23 2011 geoffrey hervet
*/

#include		<stdlib.h>

#include		"epurstr.h"

#define			IS_SEP(x)	((char)(x) == ' ' || (char)(x) == '\t')

char			*epurstr(char *str)
{
  int			idx1;
  int			idx2;

  if (str == NULL)
    return (NULL);
  idx1 = 0;
  idx2 = 0;
  while (str[idx1])
  {
    if (!((!idx1 && IS_SEP(str[idx1])) ||
        (IS_SEP(str[idx1]) && IS_SEP(str[idx1 - 1]))))
      str[idx2++] = IS_SEP(str[idx1]) ? ' ' : str[idx1];
    idx1++;
  }
  if (idx2-- == 0)
    str[0] = 0;
  else
    str[(IS_SEP(str[idx2]) ? idx2 : idx2 + 1)] = '\0';
  return (str);
}
