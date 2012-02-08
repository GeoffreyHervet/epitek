/*
** my_str_delim_to_wtab.c for my in /home/hervet_g//work/projets/minishel/lib/my
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Dec 29 11:30:47 2010 geoffrey hervet
** Last update Sun Jan  2 11:27:30 2011 geoffrey hervet
*/

#include		<stdlib.h>

#include		"libmy.h"

unsigned int		my_get_nb_occ(char *str,
				      const char delim)
{
  unsigned int		idx;
  unsigned int		nb;

  idx = 0;
  nb = 0;
  while (str[idx])
    {
      if (str[idx] == delim)
	++nb;
      ++idx;
    }
  return (idx + nb);
}

static char		*my_strcpy_ab(char *str,
				      unsigned int start,
				      const unsigned int end)
{
  char			*ret;
  unsigned int		idx;

  if ((ret = malloc(sizeof(*ret) * (end - start + 1))) == NULL)
    return (NULL);
  idx = 0;
  while (str[start] && start < end)
    ret[idx++] = str[start++];
  ret[idx] = '\0';
  return (ret);
}

char			**my_explode(const char delim,
				     char *str)
{
  char			**wtab;
  unsigned int		idx1;
  unsigned int		idx2;
  unsigned int		pos_wtab;

  if ((wtab = malloc(sizeof(*wtab) * (1 + my_get_nb_occ(str, delim)))) == NULL)
    return (NULL);
  idx1 = 0;
  idx2 = 0;
  pos_wtab = 0;
  while (idx1 == 0 || str[idx1 - 1])
    {
      if (str[idx1] == delim || !str[idx1])
	{
	  wtab[pos_wtab++] = my_strcpy_ab(str, idx2, idx1);
	  idx2 = idx1 + 1;
	}
      ++idx1;
    }
  wtab[pos_wtab] = NULL;
  return (wtab);
}
