/*
** menu.c for  in /home/wotan/projects/Epikong/etape_2
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sun Mar  4 03:59:19 2012 geoffroy aubey
** Last update Sun Mar  4 03:59:19 2012 geoffroy aubey
*/

#include "SDL/SDL.h"
#include "graphics/graphics.h"
#include "game/game.h"
#include "menu.h"

t_menu *create_menu()
{
  t_menu *m;

  m = malloc(sizeof(*m));
  return (m);
}

int	menu_init(t_menu *m)
{
  m->cur_selection = 0;
  m->hit = 1000;
  m->file_names[0] = "stage1.map";
  m->file_names[1] = "stage2.map";
  m->file_names[2] = "stage3.map";
  m->file_names[3] = "stage4.map";
  m->file_names[4] = "stage5.map";
  return (0);
}

int	draw_menu(t_game *game)
{
  t_pos pos;
  t_menu *m;
  int i;
  char buffer[512];

  SDL_WM_SetCaption("Main menu", NULL);
  i = 0;
  m = game->menu;
  pos.x = (WIN_X / 2) - 150;
  pos.y = 160;
  while (i < 5)
    {
      snprintf(buffer, 512, "%i. %s", i, m->file_names[i]);
      graphics_draw_text(game->graphics, buffer,
			 (i == m->cur_selection) ? RED : WHITE, &pos);
      ++i;
      pos.y += 50;
    }
  graphics_draw_text(game->graphics, "5. exit", (5 == m->cur_selection)
		     ? RED : WHITE, &pos);
  return (0);
}

int	menu_load_map(t_game *g, t_menu *m, char *file_name)
{
  char path[512];

  (void)m;
  snprintf(path, 512, "maps/%s", file_name);
  g->map = create_map();
  if (game_load_map(g, path) == -1)
    {
      g->state = MENU;
      delete_map(g->map);
      return (-1);
    }
  g->state = INGAME;
  return (0);
}

int	menu_update(t_menu *menu, t_event *e, int delta)
{
  menu->hit += delta;
  if (menu->hit < 300)
    return (0);
  if (e->action & MOVE_UP)
    {
      menu->hit = 0;
      menu->cur_selection--;
    }
  if (e->action & MOVE_DOWN)
    {
      menu->hit = 0;
      menu->cur_selection++;
    }
  if (menu->cur_selection > 5)
    menu->cur_selection = 0;
  if (menu->cur_selection < 0)
    menu->cur_selection = 5;
  return (0);
}
