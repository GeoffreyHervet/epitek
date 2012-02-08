/*
** look_in_exec.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/term-caps
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sat May 21 17:18:20 2011 tom-brent yau
** Last update Sun May 22 21:39:24 2011 quentin rufin
*/

#include	<stdlib.h>
#include	<string.h>

#include	"sh.h"

#include	"termcp.h"
#include	"utils.h"

static int	get_size(t_list_correc *list, char *buffer)
{
  int	count;
  int	len;

  count = 0;
  len = (int)strlen(buffer);
  while (list)
    {
      if (strncmp(buffer, list->name, len) == 0)
	++count;
      list = list->next;
    }
  return (count);
}

static char	**get_name(t_list_correc *list, char *buffer)
{
  char	**ret;
  int	len;
  int	count;

  if ((len = get_size(list, buffer)) == 0)
    return (NULL);
  if ((ret = malloc((len + 1) * sizeof(*ret))) == NULL)
    return (NULL);
  len = (int)strlen(buffer);
  count = 0;
  while (list)
    {
      if (strncmp(buffer, list->name, len) == 0)
	ret[count++] = list->name;
      list = list->next;
    }
  ret[count] = NULL;
  return (ret);
}

void	look_in_exec(t_inf *infos, t_termcp *t, t_list_correc *list,
		     char *buffer)
{
  int	count;
  char	tmp[SIZE + 1];
  char	**name;

  if (list == NULL)
    return ;
  memset(tmp, 0, SIZE + 1);
  count = t->idx - 1;
  while (count >= 0 && buffer[count] != ' ' && buffer[count] != '|' &&
	 buffer[count] != '&' && buffer[count] != ';')
    --count;
  ++count;
  strncpy(tmp, buffer + count, strclen(buffer + count, " <>|;&"));
  name = get_name(list, tmp);
  if (name == NULL)
    return ;
  complete_file(t, name, buffer, strclen(buffer + count, " <>|;&"));
  aff_list(infos, t, name, buffer);
  free(name);
}
