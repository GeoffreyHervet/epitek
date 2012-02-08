/*
** creat_history.c for  in /home/tuilli_s//projet/42sh/src/history
** 
** Made by silvain tuilliere
** Login   <tuilli_s@epitech.net>
** 
** Started on  Thu Apr  7 12:34:00 2011 silvain tuilliere
** Last update Thu May 12 12:01:11 2011 tom-brent yau
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "sh.h"
#include "gnl.h"
#include "history.h"
#include "utils.h"
#include "xmalloc.h"

static char	*grep_cmd_from_history(char *buffer)
{
  int	count;
  int	i;
  char	*result;

  i = 0;
  count = strclen(buffer, " ");
  if (buffer[count])
    count++;
  count += strclen(buffer + count, " ");
  if (buffer[count++])
    {
      result = xmalloc(sizeof(*result) * (strlen(&buffer[count]) + 1));
      while (buffer[count])
	result[i++] = buffer[count++];
      result[i] = '\0';
      return (result);
    }
  return (NULL);
}

static void	read_elem_from_history(t_history *element, char *buffer)
{
  memset(element, 0, sizeof(*element));
  element->cmd = grep_cmd_from_history(buffer);
  element->id = my_getnbr(buffer);
  buffer += strclen(buffer, " ");
  if (*buffer)
    buffer++;
  element->hours = my_getnbr(buffer);
  buffer += strclen(buffer, ":");
  if (*buffer)
    buffer++;
  element->min = my_getnbr(buffer);
}

t_history	*creat_history(void)
{
  t_history	*element;
  t_history	*list;
  char		*buffer;
  int		fd;

  list = NULL;
  if ((fd = open(".history", O_RDONLY)) == -1)
    return (list);
  while ((buffer = gnl(fd)))
    {
      epur_str(buffer, " \t", "|<>;&");
      if (*buffer)
	{
	  element = xmalloc(sizeof(*element));
	  read_elem_from_history(element, buffer);
	  add_elem_to_history(&list, element);
	}
      free(buffer);
    }
  if (close(fd) == -1)
    fprintf(stderr, "Error on close\n");
  return (list);
}
