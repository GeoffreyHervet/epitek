/*
** my_str_to_wordtab.c for  in /u/all/hervet_g/public/opt_get/src/my
** 
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
** 
** Started on  Mon May  9 19:31:33 2011 tracy nelcha
** Last update Mon May  9 21:21:25 2011 tracy nelcha
*/

#include	<stdlib.h>
#include	"my_strlen.h"
#include	"xfunc.h"

void		cut_cmd(const char *str, char **tab, int i, int size)
{
  int		k;
  int		j;

  k = 0;
  j = 0;
  while (str[k])
  {
    if (str[k] >= '!' && str[k] <= '~')
      tab[i][j++] = str[k++];
    else
    {
      j = 0;
      i++;
      tab[i] = malloc(sizeof(**tab) * size);
      k++;
    }
   tab[i][j] = '\0';
  }
  tab[i + 1] = NULL;
}

char		**my_str_to_wordtab(const char *str)
{
  int		size;
  int		i;
  char		**tab;

  if (str == NULL)
    return (NULL);
  i = 0;
  size = my_strlen(str);
  tab = xmalloc(sizeof(*tab) * size);
  tab[i] = xmalloc(sizeof(**tab) * size);
  cut_cmd(str, tab, i, size);
  return (tab);
}
