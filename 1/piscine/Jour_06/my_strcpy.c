/*
** my_strcpy.c for my_strcpy.c in /home/hervet_g//work/piscine/Jour_06
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Oct 11 09:34:13 2010 geoffrey hervet
** Last update Tue Oct 12 08:57:19 2010 geoffrey hervet
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}
