/*
** my_strlowcase.c for my_strlowcase.c in /home/hervet_g//work/piscine/Jour_06
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Oct 11 17:15:12 2010 geoffrey hervet
** Last update Tue Oct 12 09:00:14 2010 geoffrey hervet
*/

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] >= 'A') && (str[i] <= 'Z'))
	{
	  str[i] = str[i] + 'a' - 'A';
	}
      i = i + 1;
    }
  return (str);
}
