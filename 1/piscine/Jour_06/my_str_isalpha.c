/*
** my_str_isalpha.c for my_str_isalpha.c in /home/hervet_g//work/piscine/Jour_06
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Oct 11 18:51:29 2010 geoffrey hervet
** Last update Tue Oct 12 08:57:47 2010 geoffrey hervet
*/

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (((str[i] >= 'a') && (str[i] <= 'z')) ||
	  ((str[i] >= 'A') && (str[i] <= 'Z')))
	{
	  i = i + 1;
	}
      else
	{
	  return (0);
	}
    }
  return (1);
}
