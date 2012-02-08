/*
** bitmap.h for ex02 in /home/hervet_g/piscine/d01/piscine_cpp_d01-2015-hervet_g/ex02
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Jan 04 15:11:28 2012 geoffrey hervet
** Last update Wed Jan 04 15:11:28 2012 geoffrey hervet
*/

#ifndef   __BITMAP_H__
# define  __BITMAP_H__

#include	<stdint.h>

typedef struct __attribute__((packed))
{
  uint16_t	magic;
  uint32_t	size;
  uint16_t	_app1;
  uint16_t	_app2;
  uint32_t	offset;
}		t_bmp_header;

typedef struct __attribute__((packed))
{
  uint32_t	size;
  uint32_t	width;
  uint32_t	height;
  uint16_t	planes;
  uint16_t	bpp;
  uint32_t	compression;
  uint32_t	raw_data_size;
   int32_t	h_resolution;
   int32_t	v_resolution;
  uint32_t	palette_size;
  uint32_t	important_colors;
}		t_bmp_info_header;


void		make_bmp_info_header(t_bmp_info_header *,
    				     size_t size);

void		make_bmp_header(t_bmp_header *,
    				size_t size);


#endif     /* !__BITMAP_H__ */
