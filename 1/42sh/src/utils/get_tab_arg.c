/*
** exec_command.c for  in /home/rufin_q/projet/42sh/42sh/src/exec
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Sat Apr 16 14:56:56 2011 quentin rufin
** Last update Tue Apr 19 17:58:32 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	"sh.h"
#include	"xmalloc.h"
#include	"utils.h"

char	**get_tab_arg(t_tree *tree)
{
  int		count;
  char		**tab;
  t_tree	*tmp;
  int		number;

  tmp = tree;
  number = 0;
  while (tmp)
    {
      tmp = tmp->right;
      number++;
    }
  tab = xmalloc(sizeof(*tab) * (number + 1));
  tab[0] = tree->info.str;
  tmp = tree->right;
  count = 1;
  while (count < number && tmp != NULL)
    {
      tab[count++] = tmp->info.str;
      tmp = tmp->right;
    }
  tab[count] = NULL;
  return (tab);
}
