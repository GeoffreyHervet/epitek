/*
** my_free_wortab.c for my in /home/hervet_g//work/projets/minishel/lib/my
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Dec 30 15:09:59 2010 geoffrey hervet
** Last update Thu Dec 30 15:15:01 2010 geoffrey hervet
*/

#include		<stdlib.h>

#include		"libmy.h"

void			my_free_wordtab(char **tab)
{
  unsigned int		idx;

  idx = 0;
  while (tab[idx])
    free(tab[idx++]);
  free(tab);
}
