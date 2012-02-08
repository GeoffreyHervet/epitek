/*
** my_getnbr.c for  in /home/tuilli_s//projet/42sh/src/history
** 
** Made by silvain tuilliere
** Login   <tuilli_s@epitech.net>
** 
** Started on  Thu Apr  7 14:05:03 2011 silvain tuilliere
** Last update Tue May 10 15:59:54 2011 tom-brent yau
*/

int     my_getnbr(char *str)
{
  int   pos;
  int   sign;
  int   nbr;

  sign = 1;
  pos = 0;
  while (str[pos] != '\0' && (str[pos] == '+' || str[pos] == '-'))
    {
      if (str[pos++] == '-')
        sign = sign * -1;
    }
  str = str + pos;
  nbr = 0;
  pos = 0;
  while (str[pos] >= '0' && str[pos] <= '9')
    {
      nbr = nbr * 10;
      nbr = nbr - (str[pos] - '0');
      pos = pos + 1;
    }
  return (nbr * sign * -1);
}
