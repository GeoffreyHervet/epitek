/*
** bitmap_header.c for ex02 in /home/hervet_g/piscine/d01/piscine_cpp_d01-2015-hervet_g/ex02
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Jan 04 15:58:31 2012 geoffrey hervet
** Last update Wed Jan 04 15:58:31 2012 geoffrey hervet
*/

#include	<strings.h>

#include	"bitmap.h"

void		make_bmp_header(t_bmp_header *header,
    				size_t size)
{
  bzero(header, sizeof(t_bmp_header));
  header->magic = 0x4D42; //x424D
  header->size = sizeof(t_bmp_info_header) + sizeof(t_bmp_header) + size * size * 4;
  header->offset = sizeof(t_bmp_header) + sizeof(t_bmp_info_header);
}

void		make_bmp_info_header(t_bmp_info_header *header,
    				     size_t size)
{
  bzero(header, sizeof(t_bmp_info_header));
  header->size = 40;
  header->width  = size;
  header->height = size;
  header->planes = 1;
  header->bpp = 32;
  header->raw_data_size = size * size * 4;
}
