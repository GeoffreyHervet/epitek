/*
** get.c for  in /u/all/hervet_g/public/KHOL
** 
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
** 
** Started on  Wed May  4 19:24:43 2011 tracy nelcha
** Last update Wed May  4 19:48:33 2011 tracy nelcha
*/

#include	<unistd.h>
#include	<stdlib.h>

#include	"gnl.h"
#include	"my_strlen.h"

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
      upadte_tmp(tmp, buf, btmp, &bpos);
    bpos++;
  }
}
