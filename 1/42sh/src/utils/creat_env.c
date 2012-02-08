/*
** creat_env.c for  in /home/rufin_q/projet/42sh/42sh/src/exec
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Sat Apr 16 15:00:21 2011 quentin rufin
** Last update Sat Apr 16 15:02:29 2011 quentin rufin
*/

#include <stdlib.h>
#include "sh.h"
#include "xmalloc.h"

char	**creat_env(t_env *env)
{
  int		number;
  int		count;
  char		**tab;
  t_env		*tmp;

  tmp = env;
  number = 0;
  while (tmp)
    {
      number++;
      tmp = tmp->next;
    }
  tab = xmalloc(sizeof(*tab) * (number + 1));
  count = 0;
  while (count < number)
    {
      tab[count] = env->var;
      env = env->next;
      count++;
    }
  tab[count] = NULL;
  return (tab);
}
