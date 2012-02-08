/*
** get_format.c for opt_get in /afs/epitech.net/users/epitech_2015/hervet_g/public/opt_get/src/opt_get
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon May 09 22:21:40 2011 geoffrey hervet
** Last update Mon May 09 22:21:40 2011 geoffrey hervet
*/

#include	<stdlib.h>

#include	"get_format.h"
#include	"my_strndup.h"

static int	in_list(const t_format *list,
			const char *opt)
{
  while (list != NULL)
  {
    if (strcmp(opt, list->str))
      return (1);
    list = list->next;
  }
  return (0);
}

static int	insert_list(t_format **list,
			    const char *str,
                            int end,
                            int *start)
{
  t_format	*tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (-1);
  tmp->next = *list;
  *list = tmp;
  tmp->str = my_strndup(str + *start, 2);
  tmp->nb_arg = 0;
  tmp->nb_oblig = 0;
  *start = *start + end + 1;
  return (0);
}

t_format	*get_format(const char *str)
{
  t_format	*ret;
  int		start;
  int		end;
  int		in_option;

  ret = NULL;
  start = 0;
  end = 0;
  in_option = 0;
  while (str[end])
  {
    if ((str[end] == '[' &&  in_option) ||
        (str[end] == ']' && !in_option) ||
        (str[end] == ' ' &&  in_option) ||
        (str[end] == '\t'))
      return (NULL);
    if (str[end] == '[' || str[end] == ']')
      in_option = (str[end] == '[');
    if (str[end] == ' ' && !in_option)
      if (insert_list(&ret, str, end, &start))
        return (NULL);
    ret++;
  }
}
