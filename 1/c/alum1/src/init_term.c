/*
** init_term.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/rendu/c/alum1/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Feb 11 17:58:20 2011 geoffrey hervet
** Last update Fri Feb 11 21:36:26 2011 geoffrey hervet
*/

#include		<curses.h>
#include		<term.h>
#include		<termios.h>
#include		<unistd.h>

#include		"libmy.h"

#include		"init_term.h"
#include		"putcap.h"

extern char		**environ;

static char		*get_term()
{
  int			idx;

  idx = 0;
  while (environ[idx] != NULL)
  {
    if (!my_strncmp("TERM=", environ[idx], 5))
      return (&environ[idx][5]);
    ++idx;
  }
  return (NULL);
}

static void		init_termios()
{
  struct termios	term;

  tcgetattr(1, &term);
  term.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(1, TCSANOW, &term);
}

static void	init_curses()
{
  tgetent(NULL, get_term());
}

int		init_term()
{
  init_termios();
  init_curses();
  tputs(tgetstr("ks", NULL), 1, putcap);
  return (0);
}
