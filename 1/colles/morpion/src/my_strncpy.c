/*
** my_strncpy.c for  in /u/all/hervet_g/public/morpion/src
** 
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
** 
** Started on  Wed May 25 19:27:13 2011 tracy nelcha
** Last update Wed May 25 19:43:16 2011 tracy nelcha
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"my_strncpy.h"

int		my_strncpy(char *dst, const char *src, int len)
{
  while (len--)
  {
    if (src != NULL && *src)
      *dst = *src++;
    else
      *dst = 0;
    dst++;
  }
  *dst = 0;
  return (0);
}
