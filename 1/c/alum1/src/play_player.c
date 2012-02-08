/*
** play_player.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/rendu/c/alum1/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Feb 11 19:20:00 2011 geoffrey hervet
** Last update Fri Feb 11 21:52:59 2011 geoffrey hervet
*/

#include	<unistd.h>

#include	<curses.h>
#include	<stdlib.h>
#include	<term.h>

#include	"libmy.h"
#include	"alum1.h"

#include	"play_player.h"
#include	"keys.h"

static t_tab	action[] =
{
  {_key_down, "j"},
  {_key_down, "J"},
  {_key_down, "kd"},
  {_key_up, "k"},
  {_key_up, "K"},
  {_key_up, "ku"},
  {_key_right, "l"},
  {_key_right, "L"},
  {_key_right, "kr"},
  {_key_left, "h"},
  {_key_left, "H"},
  {_key_left, "kl"},
  {_key_select, " "},
  {_key_valid, "\n"},
  {NULL, NULL}
};

static int	(*get_funct(char *buffer))(t_game *game)
{
  int		idx;

  idx = 0;
  while (action[idx].key != NULL)
    {
      if ((my_strlen(action[idx].key) == 2) && (action[idx].key[0] == 'k'))
	action[idx].key = tgetstr(action[idx].key, NULL);
      if (!my_strcmp(action[idx].key, buffer))
	return (action[idx].func);
      idx++;
    }
  return (NULL);
}

void		play_player(t_game *game)
{
  char		buffer[5];
  int		nb_read;
  int		(*func)(t_game *);

  if ((nb_read = read(0, buffer, 4)) == -1)
  {
    my_putstr("ERROR : can't read ...\n", 2);
    free(game->floors);
    exit(1);
  }
  buffer[nb_read] = 0;
  if ((func = get_funct(buffer)) != NULL)
    func(game);
}
