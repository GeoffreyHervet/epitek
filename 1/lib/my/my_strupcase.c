/*
** my_strupcase.c for my_strupcase.c in /home/hervet_g//work/piscine/Jour_06
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Oct 11 17:15:12 2010 geoffrey hervet
** Last update Wed Oct 13 23:11:41 2010 geoffrey hervet
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] >= 'a') && (str[i] <= 'z'))
	{
	  str[i] = str[i] - 'a' + 'A';
	}
      i = i + 1;
    }
  return (str);
}