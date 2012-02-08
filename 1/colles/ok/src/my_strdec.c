/*
** my_strdec.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/ok/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue May 17 20:10:07 2011 geoffrey hervet
** Last update Tue May 17 20:10:07 2011 geoffrey hervet
*/

#include	"my_strdec.h"
#include	"my_strlen.h"

char		*my_strdec(char *str, int dec)
{
  int		idx;
  int		len;

  idx = 0;
  len = my_strlen(str);
  if (dec >= len)
  {
    str[0] = 0;
    return (str);
  }
  while (str[idx])
  {
    str[idx] = (dec + idx >= len) ? 0 : str[idx + dec];
    idx++;
  }
  return (str);
}
