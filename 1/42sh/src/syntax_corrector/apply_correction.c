/*
** apply_correction.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/exec
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Wed Apr 27 18:38:51 2011 tom-brent yau
** Last update Sun May 22 20:34:16 2011 tom-brent yau
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	<termios.h>

#include	"sh.h"
#include	"termcp.h"

#include	"xstrdup.h"
#include	"xwrite.h"

void			apply_correction(t_tree *cmd, char *name)
{
  char			buffer[5];

  fprintf(stderr, "42sh correct '%s' to '%s' [ny/NY]? ", cmd->info.str, name);
  fflush(stderr);
  raw_mode();
  if (read(0, buffer, 3) == -1)
    *buffer = 'n';
  classic_mode();
  xwrite(1, "\n", 1);
  if (*buffer == 'y' || *buffer == 'Y')
    {
      free(cmd->info.str);
      cmd->info.str = xstrdup(name);
    }
}

