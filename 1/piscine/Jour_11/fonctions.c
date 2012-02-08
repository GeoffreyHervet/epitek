/*
** fonctions.c for fincitons.c in /home/hervet_g//work/piscine/Jour_11
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Oct 20 16:13:14 2010 geoffrey hervet
** Last update Wed Oct 20 23:23:25 2010 geoffrey hervet
*/

#include	"definition.h"
void		show_t_list(t_list *ptr)
{
  t_list	*tmp;

  tmp = ptr;
  while (tmp != NULL)
    {
      my_putstr(tmp->data);
      my_putchar('\n');
      tmp = tmp->next;
    }
}
