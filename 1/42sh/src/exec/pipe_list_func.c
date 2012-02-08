/*
** exec_pipe_list_func.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/exec
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Tue May  3 16:57:40 2011 tom-brent yau
** Last update Sat May 14 19:06:33 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	<stdio.h>

#include	"sh.h"

#include	"exec_pipe.h"
#include	"xmalloc.h"

#include	"xclose.h"

void	put_in_list(t_wait_list **wait_list, pid_t pid)
{
  t_wait_list	*new;
  t_wait_list	*tmp;

  new = xmalloc(sizeof(*new));
  new->pid = pid;
  new->next = NULL;
  if (*wait_list == NULL)
    *wait_list = new;
  else
    {
      tmp = *wait_list;
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = new;
    }
}

void	close_in_list(t_close_list **close_list, int fd)
{
  t_close_list	*new;

  new = xmalloc(sizeof(*new));
  new->fd = fd;
  new->prev = NULL;
  if (*close_list == NULL)
    {
      new->next = NULL;
      *close_list = new;
    }
  else
    {
      new->next = *close_list;
      (*close_list)->prev = new;
      *close_list = new;
    }
}

void	close_all_opened_fd(t_close_list *list)
{
  t_close_list		*tmp;

  while (list)
    {
      tmp = list;
      if (list->fd != 0 && list->fd != 1 && list->fd != 2)
	xclose(list->fd);
      list = list->next;
      free(tmp);
    }
}

void	rm_in_list(t_close_list **close_list, int fd)
{
  t_close_list	*tmp;

  tmp = *close_list;
  while (tmp && tmp->fd != fd)
    tmp = tmp->next;
  if (tmp == NULL)
    return ;
  if (tmp->fd != 0 && tmp->fd != 1 && tmp->fd != 2)
    xclose(tmp->fd);
  if (tmp->prev)
    tmp->prev->next = tmp->next;
  else
    {
      *close_list = tmp->next;
      if (*close_list)
	(*close_list)->prev = NULL;
    }
  free(tmp);
}

