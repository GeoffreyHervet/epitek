/*
** xopen.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/xfunc
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Fri May 13 20:09:00 2011 tom-brent yau
** Last update Fri May 13 20:13:20 2011 tom-brent yau
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<errno.h>
#include	<stdio.h>
#include	<string.h>

int	xopen(const char *path, int flags)
{
  int	errno;
  int	ret;

  errno = 0;
  if ((ret = open(path, flags)) == -1)
    {
      fprintf(stderr, "%s : %s\n", path, strerror(errno));
    }
  return (ret);
}
