/*
** main.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/rendu/c/alum1/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Feb 11 17:51:52 2011 geoffrey hervet
** Last update Fri Feb 11 17:51:52 2011 geoffrey hervet
*/

#include	"libmy.h"
#include	"alum1.h"

#include	"init_game.h"
#include	"init_term.h"
#include	"play.h"

int		main()
{
  t_game	game;

  init_term();
  if (init_game(&game) == -1)
  {
    my_putstr("Memorry allocation failed...\n", 2);
    return (1);
  }
  play(&game);
  return (0);
}
