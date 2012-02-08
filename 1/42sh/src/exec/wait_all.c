/*
** wait_all.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/exec
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sat May 14 18:00:31 2011 tom-brent yau
** Last update Sun May 22 20:10:18 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	<sys/wait.h>
#include	<sys/types.h>
#include	<signal.h>

#include	"sh.h"

#include	"exec_pipe.h"
#include	"exec_redir.h"
#include	"show_message.h"

#include	"xkill.h"
#include	"xwaitpid.h"

int	wait_all(t_wait_list *list)
{
  int			status;
  t_wait_list		*tmp;
  int			ret;

  ret = TRUE;
  tmp = list;
  if (tmp != NULL)
    {
      xwaitpid(tmp->pid, &status, 0);
      if (WIFSIGNALED(status))
	show_message(WTERMSIG(status));
      if (WIFEXITED(status))
	ret = WEXITSTATUS(status);
      tmp = tmp->next;
    }
  while (tmp != NULL)
    {
      if (xwaitpid(tmp->pid, 0, WNOHANG) == 0)
	{
	  xkill(tmp->pid, SIGKILL);
	  xwaitpid(tmp->pid, 0, 0);
	}
      tmp = tmp->next;
    }
  return (ret);
}
