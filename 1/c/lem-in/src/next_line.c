/*
** next_line.c for next_line in /u/all/hervet_g/public/lemin/src
** 
** Made by claire lefauconnier
** Login   <lefauc_c@epitech.net>
** 
** Started on  Mon Apr 11 17:03:32 2011 claire lefauconnier
** Last update Sat Apr 23 18:27:58 2011 quentin rufin
*/

#include <stdlib.h>
#include "types.h"
#include "epurstr.h"
#include "gnl.h"
#include "my_putstr.h"
#include "my_strlen.h"
#include "my_strcmp.h"
#include "next_line.h"

static int	put_error(const char *str)
{
  my_putstr(str, 2);
  return (-1);
}

static int	set_nb_fourm(t_line *line)
{
  if (line->strline[0] == '#' && line->strline[1] == '#')
    return (put_error("Where is the number of ants?\n"));
  if (line->strline[0] == '#')
  {
    free(line->strline);
    if ((line->strline = epurstr(gnl(0))) == NULL)
      return (-1);
    else
      return (set_nb_fourm(line));
  }
  line->type = T_FOURM;
  return (0);
}

static int	is_room(const char *str)
{
  int		idx;

  idx = my_strlen(str);
  while (--idx > 0 && str[idx] != ' ')
    if (!IS_INT(str[idx]))
      return (0);
  if (idx <= 0 || str[idx] != ' ')
    return (0);
  while (idx >= 0 && str[idx] != ' ')
    if (!IS_INT(str[idx]) && idx--)
      return (0);
  if (idx <= 0 || str[idx] != ' ')
    return (0);
  return (1);
}

static int	set_room(t_line *line,
			 int *change,
                         int type)
{
  if (line->strline[0] == '#' && line->strline[1] != '#')
  {
    free(line->strline);
    if ((line->strline = epurstr(gnl(0))) == NULL)
      return (-1);
    return (set_room(line, change, type));
  }
  if (!my_strcmp(line->strline, M_ST) || !my_strcmp(line->strline, M_END))
    type = !my_strcmp(line->strline, M_ST) ? -T_START : -T_END;
  else if (line->strline[1] == '#')
    return (put_error(ERR_COMM));
  if (type < 0)
  {
    free(line->strline);
    if ((line->strline = epurstr(gnl(0))) == NULL)
      return (-1);
    return (set_room(line, change, -type));
  }
  if (is_room(line->strline))
  {
    line->type = type;
    return (0);
  }
  line->type = T_TUBE; *change = 2;
  return (0);
}

int		next_line(t_line *line)
{
  static int	have_nb_fourm = 0;

  if ((line->strline = epurstr(gnl(0))) == NULL)
    return ((have_nb_fourm) ? 1 : -1);
  if (!have_nb_fourm)
  {
    have_nb_fourm = 1;
    return (set_nb_fourm(line));
  }
  else if (have_nb_fourm == 1)
    return (set_room(line, &have_nb_fourm, T_ROOM));
  else if (line->strline[0] == '#' && line->strline[1] == '#')
    return (-1);
  else if ((line->strline[0] == '#') || (!line->strline[0]))
  {
    free(line->strline);
    return (next_line(line));
  }
  line->type = T_TUBE;
  return (0);
}
