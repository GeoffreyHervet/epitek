/*
** save_item.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/lemin/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Apr 11 18:51:55 2011 geoffrey hervet
** Last update Sat Apr 23 18:18:53 2011 quentin rufin
*/

#include	<stdlib.h>
#include	"types.h"
#include	"check_error.h"
#include	"get_id.h"
#include	"my_getnbr.h"
#include	"my_strcmp.h"
#include	"my_strdup.h"
#include	"my_strlen.h"
#include	"my_putstr.h"
#include	"save_item.h"

static t_list	*put_inlist(t_list *begin)
{
  if (begin == NULL)
  {
    if ((begin = malloc(sizeof(*begin))) == NULL)
      return (NULL);
    begin->next = NULL;
    return (begin);
  }
  while (begin != NULL && begin->next != NULL)
   begin = begin->next;
 if ((begin->next = malloc(sizeof(*begin))) == NULL)
   return (NULL);
  begin->next->next = NULL;
  return (begin->next);
}

static int	get_last_int(char *str)
{
  int		idx;
  int		ret;

  idx = my_strlen(str) - 1;
  while (IS_INT(str[idx]))
    idx--;
  ret = my_getnbr(&(str[idx + 1]));
  str[idx] = 0;
  return (ret);
}

static int	room_exist(t_infos *inf,
			   char *str)
{
  t_list	*tmp;

  tmp = inf->rooms;
  while (tmp != NULL)
  {
    if (!my_strcmp(str, ((t_room *)(tmp->data))->name))
    {
      my_putstr("Room already exist \n", 2);
      return (-1);
    }
    tmp = tmp->next;
  }
  return (0);
}

static int	add_room(t_line *line,
			 t_infos *infos,
                         const int id)
{
  int		val[2];
  t_list	*item;

  val[0] = get_last_int(line->strline);
  val[1] = get_last_int(line->strline);
  if (room_exist(infos, line->strline))
    return (-1);
  if ((val[0] < 0 || val[1] < 0) ||
      ((item = put_inlist(infos->rooms)) == NULL) ||
      ((item->data = malloc(sizeof(t_room))) == NULL) ||
      (((t_room *)(item->data))->name = my_strdup(line->strline)) == NULL)
  {
    my_putstr((val[0] < 0 || val[1] < 0) ? ERR_COOR : ERR_MALLOC, 2);
    return (-1);
  }
  if (infos->rooms == NULL) (infos->rooms = item);
  ((t_room *)(item->data))->coo[0] = val[0];
  ((t_room *)(item->data))->coo[1] = val[1];
  ((t_room *)(item->data))->id = id;
  if (T_END == line->type)
    infos->end = (t_room *)(item->data);
  if (T_START == line->type)
    infos->start = (t_room *)(item->data);
  free(line->strline);
  return (0);
}

int		save_item(t_line *line,
			  t_infos *infos)
{
  static int	max_id = -1;

  if (check_error(line))
    return (-1);
  if ((line->type == T_START && infos->start != NULL) ||
      (line->type == T_END && infos->end != NULL))
  {
    my_putstr("This limit is allready fixed\n", 2);
    return (-1);
  }
  if (max_id == -1)
  {
    if ((infos->nb_fourm = my_getnbr(line->strline)) <= 0)
    {
      my_putstr("Error, check number of ants ...\n", 2);
      return (-1);
    }
    max_id = 0;
    free(line->strline);
    return (0);
  }
  if (line->type & T_ROOM)
    return (add_room(line, infos, ++max_id));
  return (0);
}
