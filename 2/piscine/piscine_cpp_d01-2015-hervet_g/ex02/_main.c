/*
** main.c for ex02 in /home/hervet_g/piscine/d01/piscine_cpp_d01-2015-hervet_g/ex02
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Jan 04 16:40:34 2012 geoffrey hervet
** Last update Wed Jan 04 16:40:34 2012 geoffrey hervet
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "bitmap.h"

int main(void)
{
  t_bmp_header header;
  t_bmp_info_header info;
  int d;
  uint32_t pixel = 0x00FFFFFF;

  make_bmp_header(&header, 32);
  make_bmp_info_header(&info, 32);

  d = open("32px.bmp", O_CREAT | O_TRUNC | O_WRONLY, 0644);
  write(d, &header, sizeof(header));
  write(d, &info, sizeof(info));
  for (size_t i = 0; i < 32 * 32; ++i)
    write(d, &pixel, sizeof(pixel));
  close(d);
  return EXIT_SUCCESS;
}

