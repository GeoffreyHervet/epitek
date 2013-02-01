/*
** surface.c for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 20:05:42 2012 geoffroy aubey
** Last update Sat Mar  3 20:05:42 2012 geoffroy aubey
*/

#include <SDL/SDL.h>
#include "graphics.h"

int	load_player(t_graphics *g)
{
  if (add_surface(g, "data/sprites/p_climb_1.bmp", PLAYER_CLIMB_1) == -1 ||
      add_surface(g, "data/sprites/p_climb_2.bmp", PLAYER_CLIMB_2) == -1 ||
      add_surface(g, "data/sprites/p_dead.bmp", PLAYER_DEAD) == -1 ||
      add_surface(g, "data/sprites/p_fall_1.bmp", PLAYER_FALL_1) == -1 ||
      add_surface(g, "data/sprites/p_fall_2.bmp", PLAYER_FALL_2) == -1 ||
      add_surface(g, "data/sprites/p_fall_3.bmp", PLAYER_FALL_3) == -1 ||
      add_surface(g, "data/sprites/p_jump_1.bmp", PLAYER_JUMP_1) == -1 ||
      add_surface(g, "data/sprites/p_left_1.bmp", PLAYER_LEFT_1) == -1 ||
      add_surface(g, "data/sprites/p_left_2.bmp", PLAYER_LEFT_2) == -1 ||
      add_surface(g, "data/sprites/p_left_3.bmp", PLAYER_LEFT_3) == -1 ||
      add_surface(g, "data/sprites/p_look_left.bmp", PLAYER_LO_L) == -1 ||
      add_surface(g, "data/sprites/p_look_right.bmp", PLAYER_LO_R) == -1 ||
      add_surface(g, "data/sprites/p_right_1.bmp", PLAYER_RIGHT_1) == -1 ||
      add_surface(g, "data/sprites/p_right_2.bmp", PLAYER_RIGHT_2) == -1 ||
      add_surface(g, "data/sprites/p_right_3.bmp", PLAYER_RIGHT_3) == -1)
    return (-1);
  return (0);
}

int	load_world(t_graphics *g)
{
  if (add_surface(g, "data/sprites/wall.bmp", S_WALL) == -1 ||
      add_surface(g, "data/sprites/free.bmp", S_FREE) == -1 ||
      add_surface(g, "data/sprites/scale.bmp", S_SCALE) == -1 ||
      add_surface(g, "data/sprites/monster.bmp", S_MONSTER) == -1 ||
      add_surface(g, "data/sprites/exit.bmp", S_EXIT) == -1 ||
      add_surface(g, "data/sprites/exit_o.bmp", S_EXIT_O) == -1 ||
      add_surface(g, "data/sprites/gun.bmp", S_GUN) == -1 ||
      add_surface(g, "data/sprites/life.bmp", S_LIFE) == -1 ||
      add_surface(g, "data/sprites/key.bmp", S_KEY) == -1)
    return (-1);
  return (0);
}

int	load_enemy(t_graphics *g)
{
  if (add_surface(g, "data/sprites/enemy_left_1.bmp", ENEMY_LEFT_1) == -1 ||
      add_surface(g, "data/sprites/enemy_left_2.bmp", ENEMY_LEFT_2) == -1 ||
      add_surface(g, "data/sprites/enemy_left_3.bmp", ENEMY_LEFT_3) == -1 ||
      add_surface(g, "data/sprites/enemy_left_4.bmp", ENEMY_LEFT_4) == -1 ||
      add_surface(g, "data/sprites/enemy_right_1.bmp", ENEMY_RIGHT_1) == -1 ||
      add_surface(g, "data/sprites/enemy_right_2.bmp", ENEMY_RIGHT_2) == -1 ||
      add_surface(g, "data/sprites/enemy_right_3.bmp", ENEMY_RIGHT_3) == -1 ||
      add_surface(g, "data/sprites/enemy_right_4.bmp", ENEMY_RIGHT_4) == -1)
    return (-1);
  return (0);
}
