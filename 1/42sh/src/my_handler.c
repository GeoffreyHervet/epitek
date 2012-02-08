/*
** my_handler.c for my_handler in /home/yau_t//local/Projets/mysh
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Mon Dec 27 15:29:43 2010 tom-brent yau
** Last update Wed Jun  8 01:44:19 2011 quentin rufin
*/

#include	<string.h>
#include	<signal.h>

#include	"sh.h"
#include	"termcp.h"
#include	"utils.h"

extern t_termcp	t;
extern t_inf	infos;

void	my_handler(int signum)
{
  if (signum == SIGINT)
    {
      if (t.term != NULL)
	move_cursor_end(&infos, &t, t.cmd);
      memset(t.cmd, 0, SIZE + 1);
      t.idx = 0;
      t.size = 0;
      print("\n$> ");
    }
  else if (signum)
    print("\n$> ");
}
