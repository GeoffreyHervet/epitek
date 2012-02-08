/*
** char_to_int.c for fdf in /home/hervet_g//work/projets/libx
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Dec  1 22:12:19 2010 geoffrey hervet
** Last update Thu Dec  2 09:23:06 2010 geoffrey hervet
*/

#include	"fdf.h"
#include	"char_to_int.h"

int		char_to_int(char c)
{
  if (c >= '0' && c <= '9')
    return (c - '0');
  if (c >= 'a' && c <= 'f')
    return (c - 'a' + 10);
  if (c >= 'A' && c <= 'F')
    return (c - 'A' + 10);
  return (0);
}
