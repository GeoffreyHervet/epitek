/*
** map.c for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 19:09:08 2012 geoffroy aubey
** Last update Sat Mar  3 19:09:08 2012 geoffroy aubey
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <SDL/SDL.h>
#include "map.h"
#include "list/list.h"
#include "game.h"
#include "entity/entity.h"

void	delete_map(t_map *map)
{
  int	i;

  i = 0;
  if (map->tiles != NULL)
    while (i < map->height)
      free(map->tiles[i++]);
  free(map->tiles);
}

static void	treat_char(t_game *g, t_map *map, char c, t_pos *pos)
{
  if (c == 'm')
    spaw_entity(g, MONSTER, pos->x * SIZE_TILE_X, pos->y * SIZE_TILE_Y);
  else if (c == 'i')
    {
      if (map->is_start)
	map->error = "Multiple start";
      map->is_start = 1;
      map->start.x = pos->x;
      map->start.y = pos->y;
    }
  else if (c == 'o')
    {
      spaw_entity(g, E_EXIT, pos->x * SIZE_TILE_X, pos->y * SIZE_TILE_Y);
      if (map->is_end)
	map->error = "Multiple end";
      map->is_end = 1;
      map->end.x = pos->x;
      map->end.y = pos->y;
    }
  else if (c == 'k')
    spaw_entity(g, E_KEY, pos->x * SIZE_TILE_X, pos->y * SIZE_TILE_Y);
  else if (c == 'l')
    spaw_entity(g, E_LIFE, pos->x * SIZE_TILE_X, pos->y * SIZE_TILE_Y);
  else if (c == 'g')
    spaw_entity(g, E_GUN, pos->x * SIZE_TILE_X, pos->y * SIZE_TILE_Y);
}

static int	treat_line(t_game *g, char *line, t_map *map, int pos)
{
  int	i;
  t_pos	cur_pos;

  i = 0;
  map->tiles[pos] = malloc(sizeof(**map->tiles) * map->width);
  while (i < map->width && line[i])
    {
      map->tiles[pos][i] = FREE;
      cur_pos.x = i;
      cur_pos.y = pos;
      if (line[i] == 'w')
	map->tiles[pos][i] = WALL;
      else if (line[i] == 's')
	map->tiles[pos][i] = SCALE;
      else
	treat_char(g, map, line[i], &cur_pos);
      ++i;
    }
  printf("%s\n", line);
  return (0);
}

static int	load_map_list(t_game *g, t_list list, t_map *map)
{
  int	i;
  t_list head;

  head = list;
  i = 0;
  map->tiles = malloc(sizeof(*map->tiles) * map->height);
  while (list != END)
    {
      treat_line(g, list->value, map, i++);
      free(list->value);
      NEXT(list);
    }
  list_clear(&head);
  return (0);
}

int	load_map(t_game *g, char *file_name, t_map *map)
{
  FILE	*file;
  t_list list_line;
  ssize_t n;
  size_t tmp;
  char	*line;

  list_line = NULL;
  line = NULL;
  if ((file = fopen(file_name, "r")) == NULL)
    return (load_error(file_name));
  while ((n = getline(&line, &tmp, file)) > 0)
    {
      if (line[n - 1] == '\n')
	line[n - 1] = 0;
      if (map->width == -1)
	map->width = strlen(line);
      if (map->width != (int)strlen(line))
	return (-1);
      list_push_back(&list_line, line);
      ++map->height;
      line = NULL;
    }
  free(line);
  fclose(file);
  return (load_map_list(g, list_line, map));
}
