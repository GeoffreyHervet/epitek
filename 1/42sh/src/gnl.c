/*
** get_next_line.c for get_next_line in /home/yau_t//local/Projets/get_next_line
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Fri Nov 26 17:09:20 2010 tom-brent yau
** Last update Tue May 10 17:53:08 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	<unistd.h>

#include	"gnl.h"

static char	*cpy_in_buff(char *tmp, char *buffer, int *pos, int *pos2)
{
  while (*pos2 != BUFF_SIZE && tmp[*pos] != '\n' && tmp[*pos])
    buffer[(*pos2)++] = tmp[(*pos)++];
  buffer[*pos2] = 0;
  if (tmp[*pos] == '\n')
    (*pos)++;
  if (tmp[*pos] == 0)
    *pos = 0;
  return (buffer);
}

char		*gnl(const int fd)
{
  static char	tmp[READ_SIZE + 1];
  char		*buffer;
  static int	pos = 0;
  int		pos2;
  static int	ret = 0;

  pos2 = 0;
  buffer = NULL;
  while (pos2 < BUFF_SIZE)
    {
      if (pos == 0)
	{
	  if ((ret = read(fd, tmp, READ_SIZE)) <= 0)
	    return (NULL);
	  tmp[ret] = 0;
	}
      if (pos2 == 0)
	if ((buffer = malloc((BUFF_SIZE + 1) * sizeof(*buffer))) == NULL)
          return (NULL);
      buffer = cpy_in_buff(tmp, buffer, &pos, &pos2);
      if ((pos == 0 && ret != READ_SIZE) || (pos > 0 && tmp[pos - 1] == '\n')
	  || (pos == 0 && tmp[READ_SIZE - 1] == '\n'))
	return (buffer);
    }
  return (buffer);
}
