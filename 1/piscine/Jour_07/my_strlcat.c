/*
** my_strlcat.c for my_strlcat.c in /home/hervet_g//work/piscine/Jour_07
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Oct 13 13:51:42 2010 geoffrey hervet
** Last update Wed Oct 13 21:42:21 2010 geoffrey hervet
*/

int	my_strlcat(char *dest, char *scr, int size)
{
  int	i;
  int	ii;

  i = 0;
  ii = 0;
  while (dest[i])
    i = i + 1;
  while (scr[ii] && size--)
    {
      dest[i + ii] = scr[i];
      ii = ii + 1;
    }
  return (i + ii - 1);
}
