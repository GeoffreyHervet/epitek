/*
** replace_cmd.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/history
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Fri May 13 15:24:52 2011 tom-brent yau
** Last update Fri May 13 15:33:01 2011 tom-brent yau
*/

#include	<string.h>

#include	"sh.h"

void	replace_cmd(char *dest,
		    char *src,
		    const int dest_pos,
		    const int delete)
{
  char	tmp[SIZE + 1];

  memset(tmp, 0, SIZE + 1);
  strncpy(tmp, dest, SIZE);
  memset(dest, 0, SIZE);
  strncpy(dest, tmp, dest_pos);
  strncat(dest, src, SIZE - strlen(dest));
  strncat(dest, tmp + dest_pos + delete, SIZE - strlen(dest));
}
