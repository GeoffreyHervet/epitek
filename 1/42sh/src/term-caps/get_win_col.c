/*
** get_win_col.c for  in /home/yau_t//local/Projets/semestre_2/42sh
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sun May 22 17:27:42 2011 tom-brent yau
** Last update Sun May 22 17:29:21 2011 tom-brent yau
*/

#include	<sys/ioctl.h>
#include	<stdio.h>
#include	<termios.h>

int	get_win_col(void)
{
  struct winsize	sz;

  if (ioctl(0, TIOCGWINSZ, &sz) == -1)
    fprintf(stderr, "Ioctl error\n");
  else
    {
      return (sz.ws_col);
    }
  return (-1);
}
