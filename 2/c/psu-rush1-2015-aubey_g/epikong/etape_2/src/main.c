/*
** main.c for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 19:09:16 2012 geoffroy aubey
** Last update Sat Mar  3 19:09:16 2012 geoffroy aubey
*/

#include <stdlib.h>
#include <SDL/SDL.h>
#include "game/game.h"
#include "sound/sound.h"

int main(int ac, char *av[])
{
  t_game *game;
  t_sound sound;

  msound_init_engine(&sound);
  msound_start_song(&sound);

  game = game_create();
  if (game_parse_arguments(game, ac , av) == -1)
    return (EXIT_FAILURE);
  printf("Game init\n");
  if (game_init(game) == -1)
    {
      fprintf(stderr, "Unable to init game, exiting...\n");
      return (EXIT_FAILURE);
    }
  printf("Game run\n");
  game_run(game);
  printf("Game end\n");
  game_end(game);
  return (EXIT_SUCCESS);
}
