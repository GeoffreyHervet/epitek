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
#include "game.h"
#include "event.h"
#include "menu.h"
#include "entity/entity.h"

static int	menu_check_key(t_game *g, t_menu *menu, t_event *e)
{
  if (e->action & SELECT)
    {
      e->action &= ~SELECT;
      menu->hit = 0;
      if (menu->cur_selection == 5)
	g->run = 0;
      else
	menu_load_map(g, menu, menu->file_names[menu->cur_selection]);
    }
  if (e->action & ESCAPE)
    g->run = 0;
  return (0);
}

static int	update_entities(t_game *g, int delta)
{
  t_list	list;

  list = g->entities;
  while (list != END)
    {
      entity_update(g, list->value, delta);
      NEXT(list);
    }
  return (0);
}

static int game_finish(t_game *g)
{
  game_unload_map(g);
  if (g->menu->cur_selection + 1 > 4)
    {
      printf("Bravo ! You win !\n");
      g->load_next = 0;
    }
  if (g->load_next && g->menu)
    {
      g->menu->cur_selection++;
      menu_load_map(g, g->menu, g->menu->file_names[g->menu->cur_selection]);
    }
  else
    {
      g->state = MENU;
      g->map = NULL;
    }
  g->finish = 0;
  g->load_next = 0;
  return (0);
}

static void	manage_move(t_game *game, t_event *e, int delta)
{
  if (e->action & JUMP && (game->player->entity.state == ONGROUND
        || game->player->entity.state == ONSCALE))
    game->player->entity.vector.y = -0.4;
  if (e->action & MOVE_DOWN && game->player->entity.state == ONSCALE)
    game->player->entity.vector.y = PLAYER_SPEED;
  if (e->action & MOVE_RIGHT)
    game->player->entity.vector.x = PLAYER_SPEED;
  if (e->action & MOVE_LEFT)
    game->player->entity.vector.x = -PLAYER_SPEED;
  update_entities(game, delta);
  update_camera(game, delta);
}

int	game_logic(t_game *game, t_event *e, int delta)
{
  if (game->state == MENU)
    {
      menu_update(game->menu, e, delta);
      menu_check_key(game, game->menu, e);
      return (0);
    }
  if (e->action & ESCAPE)
    {
      e->action &= ~ESCAPE;
      game_unload_map(game);
      game->map = NULL;
      game->state = MENU;
    }
  manage_move(game, e, delta);
  game->player->invuln += delta;
  player_check_death(game, game->player);
  if (game->finish)
    game_finish(game);
  return (0);
}
