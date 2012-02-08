/*
** xchdir.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/xfunc
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sun Apr 17 18:07:11 2011 tom-brent yau
** Last update Fri May 13 20:08:48 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<unistd.h>
#include	<errno.h>

#include	"sh.h"

int	xchdir(char *path)
{
  int	ret;
  int	errno;

  ret = TRUE;
  errno = 0;
  if (chdir(path) == -1)
    {
      ret = FALSE;
      fprintf(stderr, "%s: %s\n", path, strerror(errno));
    }
  return (ret);
}
