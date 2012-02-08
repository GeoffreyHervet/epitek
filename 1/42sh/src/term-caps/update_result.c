/*
** update_result.c for  in /home/tuilli_s//projet/42sh/src/term-caps
** 
** Made by silvain tuilliere
** Login   <tuilli_s@epitech.net>
** 
** Started on  Tue May  3 18:32:46 2011 silvain tuilliere
** Last update Fri May 20 21:57:25 2011 tom-brent yau
*/

#include "sh.h"

#include "termcp.h"

int	update_result(t_termcp *termcp, char *result, char c)
{
  char	buffer;
  int	count;

  count = termcp->idx;
  while (count < termcp->size)
    {
      buffer = result[count];
      result[count] = c;
      c = buffer;
      count++;
    }
  return (0);
}
