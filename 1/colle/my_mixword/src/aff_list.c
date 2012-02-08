/*
** aff_list.c for  in /u/all/hervet_g/public/KHOL
** 
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
** 
** Started on  Wed May  4 19:52:07 2011 tracy nelcha
** Last update Wed May  4 19:53:43 2011 tracy nelcha
*/

#include	<unistd.h>

void		aff_list(t_list *begin)
{
  t_list	*tmp;

  tmp = begin;
  while (tmp != NULL)
  {
    my_putstr(tmp);
    tmp = tmp->next;
  }
}
