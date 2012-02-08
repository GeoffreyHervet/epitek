/*
** my_strnstr.c for my in /home/hervet_g//work/lib/my
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun Dec 19 13:16:55 2010 geoffrey hervet
** Last update Fri Jan 14 21:46:41 2011 geoffrey hervet
*/

#include	"libmy.h"

int		my_strncmp(const char *s1,
			   const char *s2,
			   unsigned int size)
{
  unsigned int	idx;

  idx = 0;
  if (!s1 || !s2)
    return (1);
  while (size-- && (s1[idx] || s2[idx]))
    {
      if (!s1[idx] || !s2[idx])
	return (1);
      if (s1[idx] != s2[idx])
	return (1);
      ++idx;
    }
  return (0);
}
