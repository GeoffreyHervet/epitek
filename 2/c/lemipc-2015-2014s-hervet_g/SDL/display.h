/*
** o.c for HEADER A LA NORME!!! in /home/hervet_g/
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sun Mar 25 13:36:49 2012 geoffrey hervet
** Last update Sun Mar 25 13:36:49 2012 geoffrey hervet
*/

#ifndef DISPLAY_H_
# define DISPLAY_H_

# include	"lemipc.h"

extern char	sdl_quit;

void		display_player(int team_id,
			       int idx,
			       SDL_Surface *s);

void		display_map(SDL_Surface *s, unsigned char map[MAP_SIZE]);

void		*check_quit(void *a);
int		get_key(key_t *ret);
int		get_shared_information(t_infos **i, key_t key);

#endif /* DISPLAY_H_ */
