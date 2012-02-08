/*
** bbsort.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/KHOL/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed May 04 21:52:37 2011 geoffrey hervet
** Last update Wed May 04 21:52:37 2011 geoffrey hervet
*/

#include	<stdlib.h>

#include	"types.h"

#include	"bbsort.h"
#include	"my_strcmp.h"
#include	"my_putstr.h"

int		bbsort(t_list *item1,
		       t_list *item2)
{
  int		idx;

  idx = 0;
  if (item1 == NULL || item2 == NULL)
    return (0);
  while (CAST_CHAR_S(item1->data)[idx] && 
	 CAST_CHAR_S(item2->data)[idx])
  {
    if (CAST_CHAR_S(item1->data)[idx] > 
	CAST_CHAR_S(item2->data)[idx])
      return (1);
    if (CAST_CHAR_S(item1->data)[idx] <
	CAST_CHAR_S(item2->data)[idx])
      return (0);
    idx++;
  }
  return (0);
}
