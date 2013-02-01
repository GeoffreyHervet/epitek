/*
** camera.h for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 19:19:19 2012 geoffroy aubey
** Last update Sat Mar  3 19:19:19 2012 geoffroy aubey
*/

#ifndef _CAMERA_H_
# define _CAMERA_H_

typedef struct
{
  float	x;
  float	y;
  int	max_x;
  int	max_y;
  int	min_x;
  int	min_y;
} t_camera;

void	camera_set_pos(t_camera *cam, float x, float y);
void	camera_move(t_camera *cam, float x, float y);
void	camera_init(t_camera *cam);

#endif /* !_CAMERA_H_ */
