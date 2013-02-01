/*
** map.h for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 19:10:12 2012 geoffroy aubey
** Last update Sat Mar  3 19:10:12 2012 geoffroy aubey
*/

#ifndef _MAP_H_
# define _MAP_H_

# include "epikong.h"
# include "list/list.h"

typedef enum
  {
    WALL,
    SCALE,
    FREE
  } e_map_tile;

typedef struct
{
  e_map_tile	**tiles;
  t_list	entities;
  t_pos		start;
  t_pos		end;
  int		width;
  int		height;
  char		*error;

  int		is_start;
  int		is_end;
} t_map;

t_map	*create_map();
void	delete_map(t_map *map);

#endif /* !_MAP_H_ */
