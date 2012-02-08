/*
** my_strncmp.c for my_strncmp.c in /home/hervet_g//work/piscine/Jour_06
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Oct 11 15:11:54 2010 geoffrey hervet
** Last update Wed Oct 13 22:53:44 2010 geoffrey hervet
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	length;
  int	val1;
  int	val2;
  int	i;

  val1 = 0;
  val2 = 0;
  length = n;
  while (*s1 && (length > 0))
    {
      length = length - 1;
      val1 = val1 + (ten_to(length) * (*s1));
      s1 = s1 + 1;
    }
  length = n;
  while (*s2 && (length > 0))
    {
      length = length - 1;
      val2 = val2 + (ten_to(length) * (*s2));
      s2 = s2 + 1;
    }
  if (val1 == val2)
    return (0);
  return ((val1 > val2) ? 1 : -1);
}
