/*
** collision.h for  in /home/wotan/projects/Epikong/etape_2
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sun Mar  4 13:24:28 2012 geoffroy aubey
** Last update Sun Mar  4 13:24:28 2012 geoffroy aubey
*/

#ifndef _COLLISION_H_
# define _COLLISION_H_

e_map_tile	*find_map_collisions(t_game *g, t_entity *e, float x, float y);
e_map_tile	check_wall_collide(t_game *g, float x, float y);

int manage_event_item(t_game *g, t_player *p, t_entity *e);

#endif /* !_COLLISION_H_ */
