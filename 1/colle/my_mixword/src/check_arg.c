/*
** check_arg.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/KHOL/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed May 04 20:03:20 2011 geoffrey hervet
** Last update Wed May 04 20:03:20 2011 geoffrey hervet
*/

#include	<stdlib.h>

#include	"types.h"

#include	"check_arg.h"
#include	"my_putstr.h"
#include	"my_strcmp.h"

static int	get_nb(const char *str)
{
  int		ret;

  ret = 0;
  while (str != NULL && *str && IS_DIGIT(*str))
    ret = (ret * 10) + (*str++ - '0');
  return ((*str) ? -1 : ret);
}

int		check_arg(char **av,
			  int ac,
			  t_infos *infos)
{
  int		idx;

  infos->name = NULL;
  infos->size = 0;
  idx = 0;
  while (idx < ac)
  {
    if (!my_strcmp(av[idx], "-f"))
      infos->name = av[++idx];
    if (!my_strcmp(av[idx], "-s"))
      infos->size = get_nb(av[++idx]);
    idx++;
  }
  if (infos->name == NULL)
  {
    my_putstr(USAGE, 2);
    return (-1);
  }
  if (infos->size <= 0)
    infos->size = DEFAULT_SIZE;
  return (0);
}
