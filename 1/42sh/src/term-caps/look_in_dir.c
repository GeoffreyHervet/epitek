/*
** look_in_exec.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/term-caps
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sat May 21 17:18:20 2011 tom-brent yau
** Last update Sun May 22 18:48:31 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	<string.h>
#include	<glob.h>
#include	<stdio.h>

#include	"sh.h"

#include	"termcp.h"
#include	"utils.h"

void	look_in_dir(t_inf *infos, t_termcp *t, char *buffer)
{
  int	count;
  char	tmp[SIZE + 1];
  glob_t	glb;

  memset(tmp, 0, SIZE + 1);
  count = t->idx - 1;
  while (count >= 0 && buffer[count] != ' ' && buffer[count] != '<' &&
	 buffer[count] != '>')
    --count;
  ++count;
  strncpy(tmp, buffer + count, strclen(buffer + count, " <>|;&"));
  tmp[(int)strlen(tmp)] = '*';
  if (glob(tmp, GLOB_MARK, NULL, &glb) == GLOB_NOMATCH)
    return ;
  complete_file(t, glb.gl_pathv, buffer, strclen(buffer + count, " <>|;&"));
  aff_list(infos, t, glb.gl_pathv, buffer);
  globfree(&glb);
}
