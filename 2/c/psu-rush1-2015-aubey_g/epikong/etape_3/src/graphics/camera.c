/*
** camera.c for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 19:31:55 2012 geoffroy aubey
** Last update Sat Mar  3 19:31:55 2012 geoffroy aubey
*/

#include <SDL/SDL.h>
#include "graphics.h"
#include "camera.h"
#include "epikong.h"

void	camera_init(t_camera *cam)
{
  cam->max_x = WIN_X;
  cam->max_y = WIN_Y;
  cam->min_x = 0;
  cam->min_y = 0;
  camera_set_pos(cam, 0, 0);
}

void	camera_move(t_camera *cam, float x, float y)
{
  camera_set_pos(cam, cam->x + x, cam->y + y);
}

void	camera_set_pos(t_camera *cam, float x, float y)
{
  cam->x = x;
  cam->y = y;
  if (x > cam->max_x)
    cam->x = cam->max_x;
  if (y > cam->max_y)
    cam->y = cam->max_y;
  if (x < cam->min_x)
    cam->x = cam->min_x;
  if (y < cam->min_y)
    cam->y = cam->min_y;
}
