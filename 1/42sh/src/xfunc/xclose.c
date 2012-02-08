/*
** xclose.c for  in /home/rufin_q//projet/42sh/42sh
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Tue May  3 20:25:07 2011 quentin rufin
** Last update Tue May  3 23:28:59 2011 quentin rufin
*/

#include	<unistd.h>
#include	<stdio.h>

void	xclose(int fd)
{
  if (close(fd) == -1)
    {
      fprintf(stderr, "Error on close\n");
    }
}
