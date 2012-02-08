/*
** complete_file.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/term-caps
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sun May 22 13:40:40 2011 tom-brent yau
** Last update Sun May 22 15:36:05 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	<string.h>

#include	"sh.h"

#include	"termcp.h"
#include	"utils.h"

#include	"xtputs.h"
#include	"xtgetstr.h"

void	complete_file(t_termcp *t, char **name, char *buffer, int pos)
{
  int	count;
  int	letter;
  int	max;

  letter = -1;
  max = get_max_len(name);
  while (++letter < max)
    {
      count = 0;
      while (name && name[++count]
	     && *(name[0] + pos + letter) == *(name[count] + pos + letter));
      if (name[count] == NULL && t->size < SIZE && *(name[0] + pos + letter))
	{
	  ++t->size;
	  update_result(t, buffer, *(name[0] + pos + letter));
	  ++t->idx;
	  if ((t->idx + SIZE_PROMPT) % t->width == 0)
	    xtputs(xtgetstr("do"), 1, &go);
	  else
	    xtputs(xtgetstr("nd"), 1, &go);
	}
      else
	return ;
    }
}
