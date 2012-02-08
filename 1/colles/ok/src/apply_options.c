/*
** apply_options.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/ok/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue May 17 20:56:40 2011 geoffrey hervet
** Last update Tue May 17 20:56:40 2011 geoffrey hervet
*/

#include	<stdlib.h>

#include	"types.h"

#include	"apply_options.h"
#include	"option_c.h"

void		apply_options(t_infos *inf, char *str)
{
  if (inf->opt_c != NULL)
    option_c(inf->opt_c, str);
}
