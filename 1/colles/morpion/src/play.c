/*
** header for norme in /
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.eu>
** 
** Started on  Mon Jan 01 00:00:00 2011 geoffrey hervet
** Last update Wed May 25 22:42:58 2011 tracy nelcha
*/

#include	<stdlib.h>

#include	"aff_win.h"
#include	"aff_grid.h"
#include	"aff_win.h"
#include	"play.h"
#include	"is_win.h"
#include	"play_ai.h"
#include	"play_player.h"
#include	"my_putstr.h"
#include	"my_putchar.h"

static void	play2(char grid[3][3], char sign, char win)
{
  while (!win)
  {
    aff_grid(grid);
    play_player(grid, !sign);
    win = is_win(grid);
    if (!win)
    {
      play_ai(grid, sign);
      win = is_win(grid);
    }
    if (!win)
      aff_grid(grid);
  }
  if (win)
  {
    aff_win(grid, sign);
  }
}

void		play(char grid[3][3], int timestamp)
{
  char	sign;
  char	win;

  srand(timestamp);
  sign = rand() % 2;
  win = 0;
  if (rand() % 2)
  {
    my_putstr("Computer start.\n");
    grid[0][0] = 1 << (sign + 1);
  }
  else
    my_putstr("You start !\n");
  my_putstr("Your sign is ");
  my_putchar(sign ? 'O' : 'X');
  my_putstr(".\n");
  play2(grid, sign, win);
}
