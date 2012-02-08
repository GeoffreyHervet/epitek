/*
** fdf.h for fdf in /home/hervet_g//work/projets/libx
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Nov 30 13:00:46 2010 geoffrey hervet
** Last update Wed Dec  8 16:04:00 2010 geoffrey hervet
*/

#ifndef		__FDF_H__
#  define	__FDF_H__

#  define	DEFAULT_COLOR		0xFFFFFF
#  define	MIN_WIDTH		500
#  define	CST_1			0.5
#  define	CST_2			0.5
#  define	TRANS_ISO_X(x, y, z)	((CST_1 * (x)) - (CST_2 * (y)))
#  define	TRANS_ISO_Y(x, y, z)	((z) + ((x) * CST_1 + (y) * CST_2) / 2)

typedef struct	s_coords
{
  int		x;
  int		y;
  int		z;
  unsigned int	color;
}		t_coords;

typedef struct	s_list
{
  t_coords	*data;
  struct s_list	*next;
  struct s_list	*bottom;
}		t_list;

typedef struct	s_mlx
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  t_list	*list;
  char		*data;
  int		bpp;
  int		sizeline;
  int		endian;
  int		width;
  int		height;
  int		ppl;
  int		list_elemt;
  int		espaces_btw_pxl;
}		t_mlx;

#endif		/* !__FDF_H__ */
