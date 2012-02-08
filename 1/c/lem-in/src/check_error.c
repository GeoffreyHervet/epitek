/*
** check_error.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/lemin/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Apr 11 20:11:17 2011 geoffrey hervet
** Last update Sat Apr 23 18:19:35 2011 quentin rufin
*/

#include	<stdlib.h>
#include	"types.h"
#include	"check_error.h"
#include	"my_putstr.h"
#include	"my_strlen.h"
#include	"my_strncmp.h"

static t_func	func [] =
  {
    {T_FOURM, check_fourm},
    {T_ROOM,  check_room},
    {0, NULL}
  };

int	check_room(const char *str)
{
  int		idx;
  int		two_time;

  idx = my_strlen(str);
  two_time = 2;
  while (two_time--)
  {
    while (--idx >= 0 && str[idx] != ' ')
      if (!IS_INT(str[idx]))
      {
        my_putstr(ERR_ROOM, 2);
        return (-1);
      }
    if (idx <= 0 || str[idx] != ' ')
    {
      my_putstr(ERR_ROOM, 2);
      return (-1);
    }
  }
  return (0);
}

int	check_fourm(const char *str)
{
  while (str != NULL && *str)
    if (!IS_INT(*str))
    {
      my_putstr(ERR_FOUR, 2);
      return (-1);
    }
    else
      str++;
  return (0);
}

int		check_error(const t_line *line)
{
  int		idx;

  idx = 0;
  while (func[idx].f != NULL)
  {
    if (func[idx].type & line->type)
      return (func[idx].f(line->strline));
    else if ((func[idx].type < 0) && ((-func[idx].type) & line->type))
      return (func[idx].f(line->strline));
    idx++;
  }
  return (0);
}
