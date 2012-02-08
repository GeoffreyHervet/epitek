/*
** header for norme in /
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.eu>
** 
** Started on  Mon Jan 01 00:00:00 2011 geoffrey hervet
** Last update Mon Jan 01 00:00:00 2011 geoffrey hervet
*/

#include	<unistd.h>
#include	<stdlib.h>

#include	"play_player.h"
#include	"my_putstr.h"

static int	has_error(int coo[2], char buf[5], int nb)
{
  if (nb != 4 || buf[1] != ',' ||
      WRONG_NB(GET_NB(buf[0])) || WRONG_NB(GET_NB(buf[2])))
  {
    my_putstr("Error, you have to enter X,Y with x & y <= 2 and >= 0\n");
    return (1);
  }
  coo[0] = GET_NB(buf[0]);
  coo[1] = GET_NB(buf[2]);
  return (0);
}

static void	get_coo(int coo[2])
{
  char		buf[5];
  int		nb_read;

  while ((nb_read = read(0, buf, 4)) > 0)
  {
    if (!has_error(coo, buf, nb_read))
      return;
  }
  exit(EXIT_FAILURE);
}

int		play_player(char grid[3][3], char sign)
{
  int		coo[2];

  my_putstr("What do you want to play?\n");
  get_coo(coo);
  while (grid[coo[1]][coo[0]])
  {
    my_putstr("This case isn't empty\n");
    get_coo(coo);
  }
  grid[coo[1]][coo[0]] = 1 << (sign + 1);
  return (0);
}
