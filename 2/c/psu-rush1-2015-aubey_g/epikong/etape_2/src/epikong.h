/*
** epikong.h for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 19:10:22 2012 geoffroy aubey
** Last update Sat Mar  3 19:10:22 2012 geoffroy aubey
*/

#ifndef _EPIKONG_H_
# define _EPIKONG_H_

# define SIZE_TILE_X 32
# define SIZE_TILE_Y 32

# define WIN_X 800
# define WIN_Y 600

typedef struct
{
  float	x;
  float	y;
} t_pos;

int	load_error(char *str);

#endif /* !_EPIKONG_H_ */
