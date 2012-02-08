/*
** get_next_line.c for gnl in /home/hervet_g//work/projets/c/gnl
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Nov 15 09:10:05 2010 geoffrey hervet
** Last update Thu Nov 25 13:59:45 2010 geoffrey hervet
*/

#include	<stdlib.h>
#include	<unistd.h>

#include	"get_next_line.h"
#include	"my.h"

static char	*edit_tmp(char *tmp, char *buf, int start, const int end)
{
  int		ret_pos;
  char		*ret;

  if (start > end)
    return (NULL);

  ret = malloc(sizeof(*ret) * (my_strlen(tmp) + end - start + 2));
  if (ret == NULL)
    return (NULL);
  ret_pos = 0;
  while ((tmp) && (tmp[ret_pos]))
    {
      ret[ret_pos] = tmp[ret_pos];
      ++ret_pos;
    }
  free(tmp);
  while ((buf[start]) && (start < end) && (ret_pos < GNL_LINE_WIDTH))
    {
      ret[ret_pos] = buf[start];
      ++ret_pos;
      ++start;
    }
  ret[ret_pos] = 0;
  return (ret);
}

char		*get_next_line(const int fd)
{
  static char	buf[GNL_BUFFER_SIZE];
  static int	bpos = -1;
  int		bpos_tmp;
  char		*tmp;

  tmp = NULL;
  bpos_tmp = bpos;
  while (1)
    {
      if (bpos == -1)
	{
	  if ((bpos_tmp = read(fd, buf, (GNL_BUFFER_SIZE - 1))) <= 0)
	    return (tmp);
	  buf[bpos_tmp] = 0;
	  bpos_tmp = ++bpos;
	}
      if (buf[bpos] == GNL_DELIM || (my_strlen(tmp) + bpos -bpos_tmp) ==  GNL_LINE_WIDTH)
	return (edit_tmp(tmp, buf, bpos_tmp, (buf[bpos] == GNL_DELIM) ? bpos++ : bpos));
      if (!buf[bpos])
	{
	  tmp = edit_tmp(tmp, buf, bpos_tmp, bpos);
	  bpos = -2;
	}
      bpos++;
    }
}
