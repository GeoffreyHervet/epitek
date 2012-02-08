/*
** put_in_buff.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/exec
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Wed May 11 12:51:19 2011 tom-brent yau
** Last update Sat May 21 16:28:29 2011 quentin rufin
*/

#include	<string.h>
#include	<stdlib.h>
#include	<unistd.h>

#include	"sh.h"

#include	"utils.h"

#include	"xmalloc.h"
#include	"xstrdup.h"

static void	put_in_list(char *buff, t_buff **list)
{
  t_buff	*tmp;

  if (*list == NULL)
    {
      *list = xmalloc(sizeof(**list));
      (*list)->buff = xstrdup(buff);
      (*list)->next = NULL;
    }
  else
    {
      tmp = *list;
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = xmalloc(sizeof(*tmp));
      tmp->next->buff = xstrdup(buff);
      tmp->next->next = NULL;
    }
}

void	put_in_buff(char *name, t_buff **list)
{
  char	buff[SIZE + 1];
  int	ret;
  int	size;

  size = 0;
  print("? ");
  memset(buff, 0, SIZE + 1);
  ret = read(0, buff, SIZE);
  if (ret <= 0)
    return ;
  buff[ret - 1] = 0;
  while (strcmp(buff, name))
    {
      if (size < MAX_SIZE)
	put_in_list(buff, list);
      print("? ");
      memset(buff, 0, SIZE + 1);
      ret = read(0, buff, SIZE);
      size += ret;
      if (ret <= 0)
	return ;
      buff[ret - 1] = 0;
    }
}
