/*
** my_strlen.c for  in /u/all/hervet_g/public/Pi/basic
** 
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
** 
** Started on  Wed Apr 27 22:10:30 2011 tracy nelcha
** Last update Wed Apr 27 22:10:49 2011 tracy nelcha
*/

int             my_strlen(char *str)
{
  int           idx;

  idx = 0;
  while (str[idx])
    idx++;
  return (idx);
}
