/*
** get_name.c for  in /u/all/hervet_g/public/morpion/src
** 
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
** 
** Started on  Wed May 25 21:56:57 2011 tracy nelcha
** Last update Wed May 25 21:57:11 2011 tracy nelcha
*/

#include	"get_name.h"
#include	"my_strcmp.h"
#include	"my_strncpy.h"

void		get_name(int ac,
			 char **av,
                         char *def,
                         char name[256])
{
  int		idx;

  name[0] = 0;
  idx = 1;
  while (idx < ac)
  {
    if (!my_strcmp("--name", av[idx]))
    {
      my_strncpy(name, ((idx + 1) == ac) ? def : av[idx + 1], 255);
      return ;
    }
    idx++;
  }
  my_strncpy(name, def, 255);
}
