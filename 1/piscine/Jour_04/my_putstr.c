/*
** my_putstr.c for my_putstr.c in /home/hervet_g//afs/rendu/piscine/Jour_04
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Oct  7 12:14:44 2010 geoffrey hervet
** Last update Thu Oct  7 12:21:32 2010 geoffrey hervet
*/

int	my_putstr(char *str)
{
  while (*str)
    {
      my_putchar(*str);
      str = str + 1;
    }
  return (0);
}
