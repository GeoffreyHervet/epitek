/*
** test_find.c for  in /u/all/hervet_g/public/KHOL
**
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
**
** Started on  Wed May  4 20:11:16 2011 tracy nelcha
** Last update Wed May  4 22:48:59 2011 tracy nelcha
*/

#include	<unistd.h>
#include	<stdlib.h>
#include        "gnl.h"
#include        "putinlist.h"
#include        "read_file.h"
#include	"color_txt.h"
#include	"my_strlen.h"
#include	"my_strcmp.h"
#include	"my_putstr.h"

void		show_tab(t_list *list, char *word)
{
  t_list	*tmp;
  int		idx;

  idx = 1;
  tmp = list;
  while (tmp->next)
  {
    if (my_strcmp((char *)tmp->data, word) == 0)
    {
      my_putstr(BLUE, 1);
      my_putstr((char *)tmp->data, 1);
      my_putstr(WHITE, 1);
      my_putstr("\n", 1);
    }
    else
    {
      my_putstr(tmp->data, 1);
      my_putstr("\n", 1);
    }
    tmp = tmp->next;
  }
  my_putstr("\n", 1);
}

void		find_word(t_list *list, char *word)
{
  t_list	*tmp;
  int		idx;

  idx = 0;
  tmp = list;
  while (tmp->next)
  {
    if (my_strcmp((char *)tmp->data, word) == 0)
    {
      show_tab(list, word);
      exit(EXIT_SUCCESS);
    }
    else
      tmp = tmp->next;
  }
  my_putstr(RED"Your word isn't find in the grid\n"WHITE, 1);
}

int             read_file(t_infos *inf)
{
  char          *str;
  t_list        *begin;

  begin = NULL;
  if ((inf->fd = open(inf->name, O_RDONLY)) == -1)
  {
    my_putstr(ERR_OPEN, 2);
    return (-1);
  }
  while ((str = gnl(inf->fd)) != NULL)
  {
    if (my_strlen(str) <= inf->size)
    {
      if (putinlist(&begin, str))
        return (-1);
    }
    else
      free(str);
  }
  if (close(inf->fd))
    my_putstr(ERR_CLOSE, 2);
  find_word(&begin, "coucou");
  return (0);
}
