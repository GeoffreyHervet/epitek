/*
** my_revstr.c for my_revstr.c in /home/hervet_g//work/piscine/Jour_06
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Oct 11 10:59:48 2010 geoffrey hervet
** Last update Wed Oct 13 22:49:49 2010 geoffrey hervet
*/
char    *my_revstr(char *str)
{
  int   length;
  int   i;
  int   pivot;

  i = 0;
  length = my_strlen(str);
  pivot = length / 2;
  while (i <= pivot)
    {
      my_swap_str((str + i), (str + length - i - 1));
      i = i + 1;
    }
  return (str);
}
