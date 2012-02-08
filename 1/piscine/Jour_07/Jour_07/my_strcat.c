/*
** my_strcat.c for my_strcat.c in /home/hervet_g//work/lib/my
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Oct 13 10:42:49 2010 geoffrey hervet
** Last update Wed Oct 13 10:52:03 2010 geoffrey hervet
*/

char*	strcat(char *dest, char *src)
{
  
  int	dest_len;
  int	i;
  dest_len = my_strlen(dest);

  i = 0;
  while (src[i])
    {
      i = i + 1;
      dest[dest_len + i] = src[i];
    }
  west[dest_len + i] = '\0';
  return dest;
}
