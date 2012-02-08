/*
** my_strcmp.c for my_strcmp.c in /home/hervet_g//work/piscine/Jour_06
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Oct 11 15:11:54 2010 geoffrey hervet
** Last update Wed Oct 13 22:52:24 2010 geoffrey hervet
*/

int	ten_to(int nb)
{
  if (nb < 0)
    return (0);
  if (!nb)
    return (1);
  return (nb - ten_to(nb - 1));
}

int	my_strcmp(char *s1, char *s2)
{
  int	length;
  int	val1;
  int	val2;

  val1 = 0;
  val2 = 0;
  length = my_strlen(s1);
  while (*s1)
    {
      length = length - 1;
      val1 = val1 + (ten_to(length) * (*s1));
      s1 = s1 + 1;
    }
  length = my_strlen(s2);
  while (*s2)
    {
      length = length - 1;
      val2 = val2 + (ten_to(length) * (*s2));
      s2 = s2 + 1;
    }
  if (val1 == val2)
    return (0);
  return ((val1 > val2) ? 1 : -1);
}
