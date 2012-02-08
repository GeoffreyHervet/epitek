/*
** get_max_len.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/term-caps
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sun May 22 13:39:45 2011 tom-brent yau
** Last update Sun May 22 13:40:13 2011 tom-brent yau
*/

#include	<string.h>

int	get_max_len(char **tab)
{
  int	count;
  int	max;

  count = -1;
  max = -1;
  while (tab && tab[++count])
    {
      if (max == -1 || max < (int)strlen(tab[count]))
	max = (int)strlen(tab[count]);
    }
  return (max);
}
