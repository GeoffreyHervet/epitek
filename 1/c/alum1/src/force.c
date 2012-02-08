/*
** force.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/rendu/c/alum1/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun Feb 13 22:30:35 2011 geoffrey hervet
** Last update Sun Feb 13 22:30:35 2011 geoffrey hervet
*/

#include	"alum1.h"

#include	"force.h"

static int		is_good_choice(unsigned int *floors)
{
  int			idx;
  int			only_one;
  int			cmp;

  idx = 0;
  cmp = 0;
  only_one = 1;
  while (idx < NB_FLOORS)
  {
    cmp ^= __builtin_popcount(floors[idx]);
    if (only_one && __builtin_popcount(floors[idx]) > 1)
      only_one = 0;
    idx++;
  }
  return (only_one || cmp == 0);
}

static void		delete_first(t_game *game)
{
  int			idx;
  int			dec;

  idx = 0;
  while (idx < NB_FLOORS && !game->floors[idx])
    idx++;
  dec = 0;
  while (!((game->floors[idx] & (1 << dec))))
    dec++;
  game->floors[idx] &= ~(1 << dec);
}

static unsigned	int	del_allum(unsigned int floor)
{
  int			idx;

  idx = 0;
  while (!((1 << idx) & floor))
    idx++;
  floor &= ~(1 << idx);
  return (floor);
}

void			force(t_game *game)
{
  int			idx;
  unsigned int		test[NB_FLOORS];

  idx = -1;
  while (++idx < NB_FLOORS)
    test[idx] = game->floors[idx];
  idx = -1;
  while (++idx < NB_FLOORS)
  {
    while (test[idx] && !is_good_choice(test))
      test[idx] = del_allum(test[idx]);
    if (is_good_choice(test))
    {
      game->floors[idx] = test[idx];
      return ;
    }
    test[idx] = game->floors[idx];
  }
  delete_first(game);
}
