/*
** my_putstr.c for  in /u/all/hervet_g/public/Pi/basic
** 
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
** 
** Started on  Wed Apr 27 22:10:01 2011 tracy nelcha
** Last update Wed Apr 27 22:10:22 2011 tracy nelcha
*/

#include	<unistd.h>

void            my_putstr(char *s1)
{
  int           idx;

  idx = 0;
  while (s1[idx])
    write(1, &s1[idx++], 1);
  write(1, "\n", 1);
}
