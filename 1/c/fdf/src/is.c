/*
** is.c for fdf in /home/hervet_g//work/projets/libx
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Dec  4 12:44:21 2010 geoffrey hervet
** Last update Sat Dec  4 17:52:07 2010 geoffrey hervet
*/

#include	<stdio.h>
#include	"is.h"

int		is_num(char c, int base)
{
  if ((base <= 16) && (c >= '0') && (c <= ('0' + base)))
    return (1);
  if (base == 16 && (((c >= 'a') && (c <= 'f')) || ((c >= 'A') && (c <= 'F'))))
    return (1);
  return (0);
}

int		is_valid_char(char *str, int idx)
{
  if (!idx)
    return (!(!is_num(str[idx], 10) && str[idx] != ' '));
  if (is_num(str[idx], 10) || str[idx] == ' ')
    return (1);
  if (str[idx] == ',')
    return (((idx - 1) >= 0) && is_num(str[idx - 1], 10) &&
	    str[idx + 1] == '0');
  if (str[idx] != 'x' && is_num(str[idx], 16))
    while (idx-- && str[idx] != 'x');
  if (str[idx] == 'x')
    return (((idx - 3) >= 0) && is_num(str[idx - 3], 10) &&
	    (str[idx - 2] == ',') && (str[idx - 1] == '0'));
  return (0);
}
