/*
** philosophe.h for  in /home/hervet_g/philosophe
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Mar 17 16:42:41 2012 geoffrey hervet
** Last update Sat Mar 17 16:42:42 2012 geoffrey hervet
*/

#ifndef GRAPHIC_H_
# define GRAPHIC_H_

# include <SDL/SDL.h>

# define MAX_WIDTH		800
# define MAX_HEIGHT		600
# define SQUARE_CONTENT		100
# define PHILOS_PER_LINE	8
# define OFFSET_IMG		25

# define WHITE_3P		0xFF, 0xFF, 0xFF

# define IDX_SLEEP		0
# define IDX_EAT		1
# define IDX_THINK		2

typedef struct
{
  int		x;
  int		y;
  SDL_Rect	img_pos;
}		t_philo_coord;

typedef struct
{
  SDL_Surface	*screen;
  SDL_Surface	*ressources[3];
  SDL_Surface	*cleaner;
  t_philo_coord	*philos;
}		t_graphic;

/*
** SDL_FreeSurface(x)
*/

t_graphic	*init_graphic(unsigned int);
void		graphic_sleep(size_t, t_graphic *);
void		graphic_think(size_t, t_graphic *);
void		graphic_eat(size_t, t_graphic *);

#endif /* GRAPHIC_H_ */
