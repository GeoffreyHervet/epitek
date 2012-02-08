/*
** linker.c for fdf in /home/hervet_g//work/projets/libx
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Dec  6 14:20:04 2010 geoffrey hervet
** Last update Wed Dec  8 13:42:48 2010 geoffrey hervet
*/

#include	<unistd.h>
#include	<stdio.h>
#include	"fdf.h"

void		linker(t_mlx *mlx)
{
  t_list	*list[3];
  int		item;

  item = 1;
  list[item % 2] = mlx->list;
  if (!list[item % 2])
    return ;
  list[2] = list[item % 2]->bottom;
  list[!(item % 2)] = list[2];
  while (list[2] && ++item)
    {
      while (list[!(item % 2)])
	{
	  list[!(item % 2)]->bottom = list[item % 2];
	  list[!(item % 2)] = list[!(item % 2)]->next;
	  list[item % 2] = list[item % 2]->next;
	}
      list[!(item % 2)] = list[2];
      list[2] = list[2]->bottom;
      list[!(item % 2)] = list[2];
    }
}

/*
** 		  +---+  +---+  +---+
** t_list[k%2]    |   |=>|   |=>|   |=> NULL
** 		  +---+  +---+  +---+
**		    |      |      |
** 		    V      V      V
**		  +---+  +---+  +---+
** t_list[!k%2]   |   |=>|   |=>|   |=> NULL
** t_list[2]	  +---+  +---+  +---+
** 		    |      |      |
** 		    V      V      V
**		  +---+  +---+  +---+
**                |   |=>|   |=>|   |=> NULL
** 		  +---+  +---+  +---+
** 		    |      |      |
**		    V      V      V
** 		   NULL   NULL   NULL
*/
