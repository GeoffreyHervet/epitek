/*
** my_strcapitalize.c for my_strcapitalize.c in /home/hervet_g//work/piscine/Jour_06
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Oct 11 17:15:12 2010 geoffrey hervet
** Last update Tue Oct 12 22:58:12 2010 geoffrey hervet
*/

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  if (str[i] && (str[i] >= 'a') && (str[i] <= 'z'))
    str[i] = str[i] - 'a' + 'A';
  while (str[i])
    {
      if (((str[i] < '0') || (str[i] > '9')) &&
	  ((str[i] < 'a') || (str[i] > 'z')) &&
	  ((str[i] < 'A') || (str[i] > 'Z')))
	{
	  i = i + 1;
	  if (str[i] && (str[i] >= 'a') && (str[i] <= 'z'))
	    str[i] = str[i] - 'a' + 'A';
	  else
	    i = i - 1;
	}
      i = i + 1;
    }
  return (str);
}
