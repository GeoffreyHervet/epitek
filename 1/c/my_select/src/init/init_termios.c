/*
** init_termios.c for my_select in /home/hervet_g//work/projets/my_select
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Jan 14 21:29:29 2011 geoffrey hervet
** Last update Sat Jan 15 14:38:20 2011 geoffrey hervet
*/

#include		<unistd.h>

#include		<curses.h>
#include		<stdlib.h>
#include		<term.h>
#include		<termios.h>

#include		"libmy.h"
#include		"my_select.h"

#include		"init/init_termios.h"

char			*get_term(const char **env)
{
  unsigned int		idx;

  idx = 0;
  while (env[idx] != NULL)
    {
      if (!my_strncmp("TERM=", env[idx], 5))
	return (my_strdup(&env[idx][5]));
      ++idx;
    }
  my_putstr("$TERM not found ...\n", 2);
  return (NULL);
}

int			init_termios(const char **env,
				     const int fd)
{
  char			*term;
  struct termios	termcap;

  if ((term = get_term(env)) == NULL)
    return (-1);
  if (tcgetattr(fd, &termcap) == -1)
    {
      my_putstr("tcgetattr() failled ...\n", 2);
      return (-1);
    }
  termcap.c_lflag &= ~(ICANON | ECHO);
  if (tcsetattr(fd, TCSANOW, &termcap) == -1)
    {
      my_putstr("tcgetattr() failled ...", 2);
      return (-1);
    }
  if (tgetent(NULL, term) == -1)
    {
      my_putstr("tgetent() failled ...\n", 2);
      free(term);
      return (-1);
    }
  free(term);
  return (0);
}
