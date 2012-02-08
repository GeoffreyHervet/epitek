/*
** my_str_isprintable.c for my_str_isprintable.c in /home/hervet_g//work/piscine/Jour_06
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Oct 11 19:50:28 2010 geoffrey hervet
** Last update Wed Oct 13 23:10:44 2010 geoffrey hervet
*/

int	my_str_isprintable(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if(((str[i] >=  0 ) && (str[i] < '\a')) ||
	 ((str[i] > '\r') && (str[i] < ' ' )) ||
	 ((str[i] > '~')))
	return (0);
      i = i + 1;
    }
  return (1);
}
