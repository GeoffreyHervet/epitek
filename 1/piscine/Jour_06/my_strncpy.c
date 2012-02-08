/*
** my_strncpy.c for my_strncpy in /home/hervet_g//work/piscine/Jour_06
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Oct 11 10:13:31 2010 geoffrey hervet
** Last update Tue Oct 12 09:05:30 2010 geoffrey hervet
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (i <= (n - 1))
    {
      dest[i] = src[i];
      i = i + 1;
    }
  if (dest[i])
    dest[i] = '\0';
  return (dest);
}
