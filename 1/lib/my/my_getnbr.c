/*
** my_getnbr.c for my_getnbr.c in /home/hervet_g//work/piscine/lib/my
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Oct 13 17:52:59 2010 geoffrey hervet
** Last update Wed Oct 13 17:53:30 2010 geoffrey hervet
*/

int     ten_to(int exp)
{
  int   result;

  if (exp < 0)
    {
      return (0);
    }
  result = 1;
  while (exp)
    {
      result = result * 10;
      exp = exp - 1;
    }
  return (result);
}

int     my_getnbr_clean(char *str, int length, int neg, char *int_start)
{
  int   result;

  result = 0;

  while (*str)
    {
      result = result + (ten_to(length) * (*str - '0'));
      length = length - 1;
      str = str + 1;
    }
  return (result * neg);
}

int     my_getnbr(char *str)
{
  int   neg;
  int   length;
  char  *int_start;

  neg = 1;
  length = 0;
  while ((*str == '-') || (*str == '+'))
    {
      neg = (*str == '-') ? - neg : neg;
      str = str + 1;
    }
  int_start = str;
  if ((*(str + length) >= '0') && (*(str + length) <= '9'))
    {
      length = length + 1;
    }
  if (!length)
    {
      return (0);
    }
  return (my_getnbr_clean(str, length, neg, int_start));
}
