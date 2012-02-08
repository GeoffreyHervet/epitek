/*
** load_file.c for fdf in /home/hervet_g//work/projets/libx
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Dec  1 11:29:10 2010 geoffrey hervet
** Last update Wed Dec  8 16:13:16 2010 geoffrey hervet
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<stdlib.h>

#include	"fdf.h"
#include	"load_file.h"
#include	"get_next_line.h"
#include	"set.h"
#include	"char_to_int.h"
#include	"list.h"
#include	"is.h"

static int	check_line(char *line, t_mlx *mlx)
{
  static int	have_count = 0;
  static int	nb_element = 0;
  int		current_elements;
  int		idx;

  current_elements = 0;
  idx = -1;
  while (line[++idx])
    {
      if ((idx) && (line[idx] == ' ') && (line[idx - 1] != ' '))
	++current_elements;
      if (!is_valid_char(line, idx))
	return (-1);
    }
  if  (!have_count)
    {
      have_count = 1;
      nb_element = current_elements;
      mlx->ppl = nb_element;
      return (0);
    }
  if (nb_element != current_elements)
    return (-1);
  return (0);
}

static int	save_point(char *line, int end, t_coords coo, t_list *item)
{
  t_coords	*data;

  if ((data = malloc(sizeof(*data))) == NULL)
    return (-1);
  data->z = 0;
  while (coo.z < end && line[coo.z] != ',')
    data->z = data->z * 10 + char_to_int(line[coo.z++]);
  data->x = coo.x;
  data->y = coo.y;
  coo.z += 3;
  data->color = (coo.z < end) ? 0 : DEFAULT_COLOR;
  while (coo.z < end)
    data->color = data->color * 10 + char_to_int(line[coo.z++]);
  if (!item->data)
    item->data = data;
  else
    {
      if ((item->next = malloc(sizeof(*(item->next)))) == NULL)
	return (-1);
      item = item->next;
      item->data = data;
      item->next = NULL;
      item->bottom = NULL;
    }
  return (0);
}

static int	save_line(t_list *item, char *line, int y)
{
  int		x;
  int		idx;
  int		tmp_idx;

  x = 0;
  tmp_idx = 0;
  idx = -1;
  while (1)
    {
      ++idx;
      if (line[idx] == ' ' && tmp_idx == idx)
	tmp_idx = idx + 1;
      if ((line[idx] == ' ' || !line[idx]) && idx && is_num(line[idx - 1], 16))
	{
	  if (save_point(line, idx, set_coords(x, y, tmp_idx, 0), item) == -1)
	    return (-1);
	  else
	    tmp_idx = idx + 1;
	}
      if (!line[idx])
	return (0);
    }
}

static int	load_line(t_mlx *mlx, char *line, int y)
{
  static t_list	*tmp = NULL;

  if (check_line(line, mlx) == -1)
    return (-1);
  if (tmp == NULL)
    {
      if ((tmp = malloc(sizeof(*tmp))) == NULL)
	return (-1);
      mlx->list = tmp;
    }
  else
    {
      if ((tmp->bottom = malloc(sizeof(*(tmp->bottom)))) == NULL)
	return (-1);
      tmp = tmp->bottom;
    }
  tmp->bottom = NULL;
  tmp->next = NULL;
  tmp->data = NULL;
  if (save_line(tmp, line, y) == -1)
    return (-1);
  return (0);
}

int		load_file(t_mlx *mlx, char *path)
{
  int		fd;
  char		*line;
  int		nb_line;

  if ((fd = open(path, O_RDONLY)) == -1)
    return (-1);
  nb_line = 0;
  while ((line = get_next_line(fd)))
    {
      if (line[0])
	if (load_line(mlx, line, nb_line++) == -1)
	  return (-1);
      free(line);
    }
  mlx->list_elemt = nb_line;
  if (close(fd) == -1)
    write(2, "[ERROR] - The program can't close the file...\n", 46);
  return (0);
}
