/*
** my_strlen.c for my_strlen.c in /home/hervet_g//work/piscine/lib/my
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Oct 13 17:48:56 2010 geoffrey hervet
** Last update Wed Oct 13 17:50:52 2010 geoffrey hervet
*/

int     my_strlen(char *str)
{
  int   length;

  length = 0;
  while (*str)
    {
      str = str + 1;
      length = length + 1;
    }
  return (length);
}
