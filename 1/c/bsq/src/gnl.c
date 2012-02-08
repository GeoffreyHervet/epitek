/*
** get_next_line.c for get_next_line in /home/hervet_g//work/projets/c/gnl
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Nov 11 15:29:21 2010 geoffrey hervet
** Last update Sat Nov 13 15:13:36 2010 geoffrey hervet
*/

#include	<stdlib.h>
#include	<unistd.h>

#include	"lib.h"
#include	"header.h"

static char	*conc(char *begin, char *buf, int start, int end)
{
  char		*ret;
  int		pos_ret;

  ret = malloc(sizeof(*ret) * (my_strlen(begin) + end - start + 2));
  if (ret == NULL)
    return (NULL);
  pos_ret = -1;
  while (begin[++pos_ret])
    ret[pos_ret] = begin[pos_ret];
  free(begin);
  while (start < end)
    {
      ret[pos_ret] = buf[start];
      start++;
      pos_ret++;
    }
  ret[pos_ret] = 0;
  return (ret);
}

static int	do_new_width(int fd, char *buffer, int *tmp_bpos, int *bpos)
{
  *bpos = 0;
  *tmp_bpos = 0;
  return (read(fd, buffer, BUFFER_SIZE));
}

static	int	my_init(int bpos, char *tmp)
{
  tmp[0] = 0;
  return (bpos);
}

char		*get_next_line(int fd)
{
  static char	buffer[BUFFER_SIZE];
  static int	bpos = 0;
  static int	bwidth = 0;
  char		*tmp;
  int		tmp_bpos;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (NULL);
  tmp_bpos = my_init(bpos, tmp);
  if (bwidth == 0)
    bwidth = read(fd, buffer, BUFFER_SIZE);
  while (bpos < bwidth)
    {
      if (buffer[bpos] == CHAR_NEW_LINE)
	return ((bpos++) ? (conc(tmp, buffer, tmp_bpos, bpos - 1)) : (tmp));
      if (++bpos >= bwidth)
        {
	  tmp = conc(tmp, buffer, tmp_bpos, bpos);
  	  bwidth = do_new_width(fd, buffer, &tmp_bpos, &bpos);
        }
    }
  return (NULL);
}

