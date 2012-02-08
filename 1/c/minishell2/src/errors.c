/*
** errors.c for my_sh in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun Dec 19 10:02:18 2010 geoffrey hervet
** Last update Fri Dec 31 10:56:45 2010 geoffrey hervet
*/

#include	<sys/types.h>

#include	<stdlib.h>

#include	"my_sh.h"
#include	"libmy.h"
#include	"errors.h"

void		critical_error(int func_ret,
			       int check_val_ret,
			       int have_quit,
			       char *msg)
{
  if (func_ret == check_val_ret)
    {
      if (msg)
	my_putstr(msg, 2);
      else
	my_putstr(ERR_DEFAULT, 2);
      if (have_quit)
	exit(EXIT_FAILURE);
    }
}
