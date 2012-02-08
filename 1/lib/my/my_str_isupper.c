/*
** my_str_isupper.c for my_str_isupper.c in /home/hervet_g//work/piscine/Jour_06
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Oct 11 18:51:29 2010 geoffrey hervet
** Last update Wed Oct 13 23:11:06 2010 geoffrey hervet
*/

int	my_str_isupper(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] >= 'A') && (str[i] <= 'Z'))
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
