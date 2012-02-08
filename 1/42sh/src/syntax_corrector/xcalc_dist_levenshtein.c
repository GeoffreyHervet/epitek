/*
** xcalc_dist_levenshtein.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/exec
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Wed Apr 27 18:39:34 2011 tom-brent yau
** Last update Wed Apr 27 18:50:29 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	"sh.h"
#include	"dist_levenshtein.h"

int	xcalc_dist_levenshtein(char *s1, char *s2)
{
  int		ret;

  ret = calc_dist_levenshtein(s1, s2);
  if (ret == -1)
    exit(EXIT_FAILURE);
  return (ret);
}
