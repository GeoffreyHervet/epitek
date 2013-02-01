/*
** animation.h for  in /home/wotan/projects/Epikong/etape_2
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sun Mar  4 16:51:34 2012 geoffroy aubey
** Last update Sun Mar  4 16:51:34 2012 geoffroy aubey
*/

#ifndef _ANIMATION_H_
# define _ANIMATION_H_

# include "list/list.h"

typedef struct s_animation
{
  int		time_frame;
  int		last_time;
  int		pause;
  t_list	surfaces;
  t_list	it;
} t_animation;

t_animation	*create_animation(int time_frame);
int		anim_add_surface(t_animation *a, SDL_Surface *s);
SDL_Surface	*anim_get_current_surface(t_animation *a);
int		anim_update(t_animation *a, int delta);
void		anim_delete(t_animation *a);
void		anim_clear(t_animation *a);

#endif /* !_ANIMATION_H_ */
