/*
** my_str_isnum.c for my_str_isnum.c in /home/hervet_g//work/piscine/Jour_06
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Oct 11 18:51:29 2010 geoffrey hervet
** Last update Tue Oct 12 08:58:33 2010 geoffrey hervet
*/

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] >= '0') && (str[i] <= '9'))
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
