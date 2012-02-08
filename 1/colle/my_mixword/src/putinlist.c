/*
** putinlist.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/KHOL/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed May 04 20:58:18 2011 geoffrey hervet
** Last update Wed May 04 20:58:18 2011 geoffrey hervet
*/

#include	<stdlib.h>

#include	"types.h"

#include	"my_putstr.h"
#include	"putinlist.h"

int		putinlist(t_list **begin,
			  void *data)
{
  t_list	*tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
  {
    my_putstr(ERR_MALLOC, 2);
    return (-1);
  }
  tmp->next = *begin;
  *begin = tmp;
  tmp->data = data;
  return (0);
}
