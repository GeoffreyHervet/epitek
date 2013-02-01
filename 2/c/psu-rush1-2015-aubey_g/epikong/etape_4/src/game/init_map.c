/*
** map.c for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 19:09:08 2012 geoffroy aubey
** Last update Sat Mar  3 19:09:08 2012 geoffroy aubey
*/

#include <stdlib.h>
#include "game.h"

t_map	*create_map()
{
  t_map *map;

  map = malloc(sizeof(*map));
  map->entities = NULL;
  map->tiles = NULL;
  map->height = 0;
  map->width = -1;
  map->error = NULL;
  map->is_end = 0;
  map->is_start = 0;
  return (map);
}

