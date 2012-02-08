/*
** display_history.c for  in /home/tuilli_s//projet/42sh/src/history
** 
** Made by silvain tuilliere
** Login   <tuilli_s@epitech.net>
** 
** Started on  Thu Apr  7 14:28:18 2011 silvain tuilliere
** Last update Tue May 10 18:07:21 2011 tom-brent yau
*/

#include <stdlib.h>
#include <stdio.h>
#include "sh.h"
#include "history.h"

int	display_history(t_history *list)
{
  if (list != NULL)
    printf("History:\n");
  while (list != NULL)
    {
      if (list->cmd != NULL)
	{
	  printf("  %d  %02d:%02d", list->id, list->hours, list->min);
	  printf("  %s\n", list->cmd);
	}
      list = list->next;
    }
  return (TRUE);
}
