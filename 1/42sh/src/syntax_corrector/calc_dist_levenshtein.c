/*
** calc_dist_levenshtein.c for  in /home/rufin_q//projet/42sh/42sh/src/syntax_corrector
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Wed Jun  8 15:40:19 2011 quentin rufin
** Last update Wed Jun  8 16:13:45 2011 quentin rufin
*/

#include <stdlib.h>
#include <string.h>
#include "sh.h"
#include "dist_levenshtein.h"
#include "xmalloc.h"

static void	calc_all_values(int **tab, t_two_str_info *info)
{
  int		line;
  int		column;
  int		first;
  int		second;
  int		third;

  line = 1;
  while (line < info->size2 + 1)
    {
      column = 1;
      while (column < info->size1 + 1)
	{
	  first = tab[line - 1][column] + 1;
	  second = tab[line][column - 1] + 1;
	  third = tab[line][column] + tab[line - 1][column - 1];
	  tab[line][column] = calc_min_of_three_values(first, second, third);
	  column++;
	}
      line++;
    }
}

static void		fill_tab(int **tab, t_two_str_info *info)
{
  int			line;
  int			column;

  line = 0;
  column = 0;
  while (column <= info->size1)
    {
      tab[0][column] = column;
      column++;
    }
  while (++line <= info->size2)
    tab[line][0] = line;
  line = 1;
  while (info->str2[line - 1] != 0)
    {
      column = 1;
      while (info->str1[column - 1] != 0)
	{
	  tab[line][column] = info->str1[column - 1] != info->str2[line - 1];
	  column++;
	}
      line++;
    }
}

static int		**init_tab(int **tab)
{
  int			count;
  int			*line;

  if (tab != NULL)
    return (tab);
  count = 0;
  line = xmalloc(sizeof(*line) * ((SIZE_MAX_WORD + 1) * (SIZE_MAX_WORD + 1)));
  tab = xmalloc(sizeof(*tab) * (SIZE_MAX_WORD + 1));
  while (count < SIZE_MAX_WORD + 1)
    {
      tab[count] = line + count * (SIZE_MAX_WORD + 1);
      count++;
    }
  return (tab);
}

int			calc_dist_levenshtein(char *s1, char *s2)
{
  static int		**tab = NULL;
  t_two_str_info	info;
  int			distance;

  if (s1 == NULL || s2 == NULL)
    return (-1);
  tab = init_tab(tab);
  info.size1 = strlen(s1);
  info.size2 = strlen(s2);
  info.str1 = s1;
  info.str2 = s2;
  fill_tab(tab, &info);
  calc_all_values(tab, &info);
  distance = tab[info.size2][info.size1];
  return (distance);
}
