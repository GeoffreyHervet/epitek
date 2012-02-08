/*
** create_matrice.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/lemin/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Apr 12 13:34:48 2011 geoffrey hervet
** Last update Sat Apr 23 18:28:18 2011 quentin rufin
*/

#include	<stdlib.h>
#include	"types.h"
#include	"create_matrice.h"
#include	"get_id.h"
#include	"my_putstr.h"

static int	get_size(const t_list *begin)
{
  int		ret;

  ret = 0;
  while (begin != NULL)
  {
    begin = begin->next;
    ret++;
  }
  return (ret);
}

int		create_matrice(t_infos *infos)
{
  int		size;
  int		pos;
  int		pos2;
  t_matrice	*matrice;

  size = get_size(infos->rooms);
  if (((matrice = malloc(sizeof(*matrice))) == NULL) ||
      ((matrice->tab = malloc(sizeof(*(matrice->tab)) * size)) == NULL))
    return (-1);
  matrice->size = size;
  if ((matrice->corresp = malloc(sizeof(*(matrice->corresp)) * size)) == NULL)
    return (-1);
  pos = -1;
  while (++pos < size)
  {
    matrice->corresp[pos] = NULL;
    if ((matrice->tab[pos] = malloc(sizeof(**(matrice->tab)) * size)) == NULL)
      return (-1);
    pos2 = -1;
    while (++pos2 < size)
      matrice->tab[pos][pos2] = (pos == pos2) ? 0 : -1;
  }
  infos->matrice = matrice;
  return (0);
}
