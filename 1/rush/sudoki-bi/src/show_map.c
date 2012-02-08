/*
** show_map.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/suck/rendu/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun May 08 22:54:33 2011 geoffrey hervet
** Last update Sun May 08 22:54:33 2011 geoffrey hervet
*/

#include			<unistd.h>
#include			<stdio.h>

#include			"get_digit.h"
#include			"show_map.h"

void				show_map(unsigned short grid[9][9],
					 const unsigned char nb)
{
  register unsigned char	y;
  register unsigned char	x;

  if (nb != 0)
    printf("####################\n");
  y = 0;
  printf("|------------------|\n");
  while (y < 9)
  {
    printf("|");
    x = 0;
    while (x < 9)
    {
      printf(" %c", (__builtin_popcount(grid[y][x]) == 1) ?
                  GET_DIGIT(grid[y][x]) + '0'
                  : '0');
      x++;
    }
    printf("|\n");
    y++;
  }
  printf("|------------------|\n");
}
