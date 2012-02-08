/*
** my_str_islower.c for my_str_islower.c in /home/hervet_g//work/piscine/Jour_06
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Oct 11 18:51:29 2010 geoffrey hervet
** Last update Wed Oct 13 23:10:00 2010 geoffrey hervet
*/

int	my_str_islower(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] >= 'a') && (str[i] <= 'z'))
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
