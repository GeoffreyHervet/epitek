/*
** my_strlen.c for my_strlen.c in /home/hervet_g//afs/rendu/piscine/Jour_04
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Oct  7 16:19:09 2010 geoffrey hervet
** Last update Wed Dec 29 12:18:16 2010 geoffrey hervet
*/

int	my_strlen(char *str)
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
