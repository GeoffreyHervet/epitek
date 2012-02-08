/*
** history.c for  in /home/tuilli_s//projet/42sh/src/history
** 
** Made by silvain tuilliere
** Login   <tuilli_s@epitech.net>
** 
** Started on  Wed Apr  6 20:09:53 2011 silvain tuilliere
** Last update Wed Jun  8 16:45:30 2011 tom-brent yau
*/

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include "sh.h"

#include "history.h"
#include "utils.h"
#include "xmalloc.h"
#include "xstrdup.h"

static void	get_time(t_history *element)
{
  time_t	info;
  struct tm	*tm;

  time(&info);
  tm = localtime(&info);
  element->hours = tm->tm_hour;
  element->min = tm->tm_min;
}

static void	update_file(t_history *list)
{
  int	fd;

  if ((fd = open(".history", O_WRONLY | O_CREAT | O_TRUNC,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    return ;
  while (list)
    {
      if (list->cmd)
	{
	  dprintf(fd, "%d ", list->id);
	  dprintf(fd, "%02d:%02d %s\n", list->hours, list->min, list->cmd);
	}
      list = list->next;
    }
  if (close(fd) == -1)
    fprintf(stderr, "Error on close\n");
}

static t_history	*cmp_cmd_in_history(t_history *list, char *str)
{
  while (list)
    {
      if (list->cmd && !strcmp(list->cmd, str))
	return (list);
      list = list->next;
    }
  return (NULL);
}

static void	del_elem_in_history(t_history **history, t_history *tmp)
{
  if (tmp->previous == NULL)
    {
      *history = tmp->next;
      if (*history != NULL)
	(*history)->previous = NULL;
    }
  else
    {
      tmp->previous->next = tmp->next;
      if (tmp->next != NULL)
	tmp->next->previous = tmp->previous;
    }
  free(tmp->cmd);
  free(tmp);
}

int	update_history(char *str, t_history **history)
{
  t_history	*element;
  t_history	*tmp;
  int		pos;

  pos = 0;
  if (strclen(str + pos, "!") != (int)strlen(str))
    {
      while ((pos += strclen(str + pos, "!")) != (int)strlen(str))
	if (look_in_history(str, pos++, *history) == FALSE)
	  return (FALSE);
      printf("%s\n", str);
    }
  if (str && str[0] != '\0')
    {
      element = xmalloc(sizeof(*element));
      memset(element, 0, sizeof(*element));
      element->cmd = xstrdup(str);
      get_time(element);
      if ((tmp = cmp_cmd_in_history(*history, str)) != NULL)
	del_elem_in_history(history, tmp);
      add_elem_to_history(history, element);
      update_file(*history);
    }
  return (TRUE);
}
