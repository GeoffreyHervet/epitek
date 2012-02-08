/*
** my_strstr.c for my_strstr.c in /home/hervet_g//work/piscine/Jour_06
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Oct 11 13:32:38 2010 geoffrey hervet
** Last update Tue Oct 12 09:01:59 2010 geoffrey hervet
*/

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	i2;
  int	i_ret;

  i = 0;
  i2 = 0;
  while (str[i])
    {
      if (str[i] == to_find[0])
	{
	  i2 = 0;
	  i_ret = i;
	  while (str[i] == to_find[i2])
	    {
	      i = i + 1;
	      i2 = i2 + 1;
	      if (!to_find[i2])
		{
		  return (str + i_ret);
		}
	    }
	  i = i_ret;
	}
      i = i + 1;
    }
  return (0);
}
