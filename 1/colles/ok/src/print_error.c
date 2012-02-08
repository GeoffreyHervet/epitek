/*
** print_error.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/ok/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue May 17 19:53:08 2011 geoffrey hervet
** Last update Tue May 17 19:53:08 2011 geoffrey hervet
*/

#include	"my_putstr.h"
#include	"print_error.h"

int	  print_error(const char *str, int ret)
{
  my_putstr(str, 2);
  return (ret);
}
