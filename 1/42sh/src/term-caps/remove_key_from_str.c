/*
** remove_key_from_str.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/term-caps
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu May 19 22:26:43 2011 tom-brent yau
** Last update Fri May 20 21:57:37 2011 tom-brent yau
*/

#include "sh.h"

#include "termcp.h"

void	remove_key_from_str(char *result, int *size, int idx)
{
  char	buffer;

  while (idx < *size)
    {
      buffer = result[idx + 1];
      result[idx] = buffer;
      idx++;
    }
  --(*size);
}
