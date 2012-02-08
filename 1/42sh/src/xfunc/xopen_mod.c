/*
** xopen_mod.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/xfunc
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Fri May 13 23:17:17 2011 tom-brent yau
** Last update Fri May 13 23:28:49 2011 tom-brent yau
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<errno.h>
#include	<stdio.h>
#include	<string.h>

int	xopen_mod(const char *pathname, int flags, mode_t mode)
{
  int	errno;
  int	ret;

  errno = 0;
  if ((ret = open(pathname, flags, mode)) == -1)
    {
      fprintf(stderr, "%s : %s\n", pathname, strerror(errno));
    }
  return (ret);
}
