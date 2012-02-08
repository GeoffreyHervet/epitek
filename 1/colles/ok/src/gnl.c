/*
** gnl.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/ok/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue May 17 21:21:15 2011 geoffrey hervet
** Last update Tue May 17 21:21:15 2011 geoffrey hervet
*/

#include	<stdlib.h>
#include	<unistd.h>

#include	"my_strlen.h"
#include	"gnl.h"

static char	*upadte_tmp(char *tmp,
			    const char buf[BUFF_SIZE],
                            int begin,
                            int *end)
{
  char		*ret;
  int		idx;

  idx = my_strlen(tmp) + *end - begin + 2;
  if ((ret = malloc(sizeof(*ret) * idx)) == NULL)
    return (NULL);
  idx = 0;
  while (tmp != NULL && tmp[idx])
    ret[idx++] = *tmp++;
  while (begin < *end)
    ret[idx++] = buf[begin++];
  ret[idx] = 0;
  *end = (buf[begin]) ? *end + 1 : -2;
  free(tmp);
  return (ret);
}

char		*gnl(const int fd)
{
  static int	bpos = -1;
  static char	buf[BUFF_SIZE];
  char		*tmp;
  int		btmp;

  tmp = NULL;
  btmp = bpos;
  while (1)
  {
    if (bpos == -1)
    {
      if ((bpos = read(fd, buf, BUFF_SIZE - 1)) <= 0)
        return (tmp);
      buf[bpos] = 0;
      bpos = 0;
      btmp = 0;
    }
    if (buf[bpos] == '\n')
      return (upadte_tmp(tmp, buf, btmp, &bpos));
    if (!buf[bpos])
      tmp = upadte_tmp(tmp, buf, btmp, &bpos);
    bpos++;
  }
}
