/*
** main.c for sudoki-bi in /u/all/hervet_g/public/suck/rendu/src
** 
** Made by vincent caggiari
** Login   <caggia_v@epitech.net>
** 
** Started on  Fri May  6 22:55:38 2011 vincent caggiari
** Last update Sun May  8 22:47:45 2011 vincent caggiari
*/

#include      	<string.h>
#include	<stdio.h>

#include	"get_map.h"
#include	"get_digit.h"
#include	"show_map.h"
#include	"solve.h"

int			main()
{
  unsigned short	grid[9][9];
  unsigned int		nb_aff;

  nb_aff = 0;
  while (memset(grid, 0xFFFFFFFF, sizeof(grid)) && get_map(grid))
    {
      solve(grid);
      show_map(grid, nb_aff++);
    }
  return (0);
}
