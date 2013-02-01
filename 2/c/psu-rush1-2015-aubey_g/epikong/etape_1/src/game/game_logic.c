/*
** game_logic.c for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 21:57:07 2012 geoffroy aubey
** Last update Sat Mar  3 21:57:07 2012 geoffroy aubey
*/

#include <SDL/SDL.h>
#include "graphics/graphics.h"
#include "graphics/graphics.h"
#include "game.h"
#include "event.h"

int	game_logic(t_game *game, t_event *e, int delta)
{
  if (e->action & MOVE_UP)
    camera_move(&game->graphics->cam, 0, -(delta / MOVE_SPEED));
  if (e->action & MOVE_DOWN)
    camera_move(&game->graphics->cam, 0, (delta / MOVE_SPEED));
  if (e->action & MOVE_RIGHT)
    camera_move(&game->graphics->cam, (delta / MOVE_SPEED), 0);
  if (e->action & MOVE_LEFT)
    camera_move(&game->graphics->cam, -(delta / MOVE_SPEED), 0);
  return (0);
}
