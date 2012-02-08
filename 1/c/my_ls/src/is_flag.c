/*
** is_flag.c for my_ls in /home/hervet_g//work/projets/my_ls
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Dec 17 16:56:19 2010 geoffrey hervet
** Last update Fri Dec 17 16:59:55 2010 geoffrey hervet
*/

#include	"table_flag.h"
#include	"is_flag.h"

int		is_flag(unsigned int flags, char flag)
{
  int		idx;

  idx = 0;
  while (good_flags[idx])
    {
      if (good_flags[idx] == flag)
	{
	  if (flags & (1 << ++idx))
	    return (1);
	  return (0);
	}
      ++idx;
    }
  return (0);
}
