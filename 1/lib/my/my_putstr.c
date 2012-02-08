/*
** my_putstr.c for my_putstr in /home/hervet_g//work/piscine/lib/my
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Oct 13 17:46:24 2010 geoffrey hervet
** Last update Wed Oct 13 17:46:32 2010 geoffrey hervet
*/

int     my_putstr(char *str)
{
  while (*str)
    {
      my_putchar(*str);
      str = str + 1;
    }
  return (0);
}
