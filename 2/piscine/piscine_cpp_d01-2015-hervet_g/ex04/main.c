/*
** main.c for ex01 in /home/hervet_g/piscine/d01/piscine_cpp_d01-2015-hervet_g/ex01
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Jan 04 12:24:42 2012 geoffrey hervet
** Last update Wed Jan 04 12:24:42 2012 geoffrey hervet
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	<string.h>

#include	"drawing.h"
#include	"bitmap.h"

#ifndef ERR_MSG
# define ERR_MSG	("menger_face file_name size level\n")
#endif

void	menger(int, int, unsigned int **);

int	main(int ac, char **av)
{
  t_bmp_header header;
  t_bmp_info_header info;
  unsigned int *buffer;
  unsigned int **img;

  size_t size = 0;
  int d;

  if (ac != 4)
  {
    write(STDERR_FILENO, ERR_MSG, strlen(ERR_MSG));
    return EXIT_FAILURE;
  }

  size = atoi(av[2]);

  buffer = malloc(size * size * sizeof(*buffer));
  img = malloc(size * sizeof(*img));

  d = open(av[1], O_CREAT | O_TRUNC | O_WRONLY, 0644);

  if (d == -1 || buffer == NULL || img == NULL)
    return EXIT_FAILURE;

  memset(buffer, 0, size * size * sizeof(*buffer));

  for (size_t i = 0; i < size; ++i)
    img[i] = buffer + i * size;

  make_bmp_header(&header, size);
  make_bmp_info_header(&info, size);

  menger((int)size, atoi(av[3]), img);
  write(d, &header, sizeof(header));
  write(d, &info, sizeof(info));
  write(d, buffer, size * size * sizeof(*buffer));
  close(d);
  return EXIT_SUCCESS;
}
