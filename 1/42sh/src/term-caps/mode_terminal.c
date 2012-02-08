/*
** mode_terminal.c for  in /home/tuilli_s//projet/42sh/src/term-caps
** 
** Made by silvain tuilliere
** Login   <tuilli_s@epitech.net>
** 
** Started on  Tue Apr 26 16:15:36 2011 silvain tuilliere
** Last update Sun May 22 20:34:53 2011 tom-brent yau
*/

#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sh.h"

#include "termcp.h"

#include "xwrite.h"

void    classic_mode(void)
{
  struct termios        t;

  if (tcgetattr(0, &t) == -1)
    {
      fprintf(stderr, "tcgetattr failed.\n");
      return ;
    }
  t.c_lflag |= ECHO;
  t.c_lflag |= ICANON;
  if (tcsetattr(0, TCSANOW, &t) == -1)
    {
      fprintf(stderr, "tcsetattr failed.\n");
    }
}

void    raw_mode(void)
{
  struct termios        t;

  if (tcgetattr(0, &t) == -1)
    {
      fprintf(stderr, "tcgetattr failed.\n");
      return ;
    }
  t.c_lflag &= ~ECHO;
  t.c_lflag &= ~ICANON;
  t.c_cc[VMIN] = 1;
  t.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, &t) == -1)
    {
      fprintf(stderr, "tcsetattr failed.\n");
    }
}

char    *my_get_env(char **env, char *aim)
{
  int   i;
  int   j;

  j = 0;
  if (env != NULL)
    {
      while (env[j] != NULL)
        {
          i = 0;
          while (env[j][i] == aim[i] && env[j][i] != '=' && aim[i] != 0)
            {
              if (i == ((int)strlen(aim) - 1))
                return (env[j] + (int)strlen(aim) + 1);
              i++;
            }
          j++;
        }
    }
  return (NULL);
}

int     go(int c)
{
  xwrite(1, &c, 1);
  return (0);
}
