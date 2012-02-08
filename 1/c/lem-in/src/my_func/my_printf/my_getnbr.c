/*
** my_getnbr.c for my_getnbr in /home/yau_t/
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Wed Oct 13 16:16:26 2010 tom-brent yau
** Last update Wed Oct 13 16:58:03 2010 tom-brent yau
*/

int	my_getnbr(char *str)
{
  int	i;
  int	sign;
  int	nbr;

  sign = 1;
  i = 0;
  while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
    {
      if (str[i] == '-')
	{
	  sign = -sign;
	}
      i = i + 1;
    }
  str = str + i;
  nbr = 0;
  i = 0;
  while (str[i] >= '0' && str[i] <= '9')
    {
      nbr = nbr * 10;
      nbr = nbr + (str[i] - '0');
      i = i + 1;
    }
  return (nbr * sign);
}
