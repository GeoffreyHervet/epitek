/*
** opt_get.c for opt_get in /afs/epitech.net/users/epitech_2015/hervet_g/public/opt_get/src/opt_get
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon May 09 19:35:14 2011 geoffrey hervet
** Last update Mon May  9 20:27:53 2011 tracy nelcha
*/

#include	<stdlib.h>

#include	"epur_str.h"
#include	"opt_get.h"
#include	"get_format.h"

t_opt		*opt_get(int ac,
			 char **av,
                         const char* format)
{
  char		**wt;
  t_opt 	*ret;

  ret = NULL;
  if (ac < 1 || av == NULL || *av == NULL || format == NULL)
    return (NULL);
  return (ret);
}
