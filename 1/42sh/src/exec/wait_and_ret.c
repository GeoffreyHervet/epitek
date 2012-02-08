/*
** wait_and_ret.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/exec
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Fri May 13 22:04:58 2011 tom-brent yau
** Last update Fri May 13 22:12:03 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/wait.h>

#include	"sh.h"

#include	"show_message.h"
#include	"xwait.h"

int	wait_and_ret(void)
{
  int	status;

  xwait(&status);
  if (WIFSIGNALED(status))
    show_message(WTERMSIG(status));
  if (WIFEXITED(status))
    return (WEXITSTATUS(status));
  return (FALSE);
}
