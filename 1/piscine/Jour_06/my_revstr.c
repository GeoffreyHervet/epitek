/*
** my_revstr.c for my_revstr.c in /home/hervet_g//work/piscine/Jour_06
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Oct 11 10:59:48 2010 geoffrey hervet
** Last update Tue Oct 12 08:53:59 2010 geoffrey hervet
*/
int	my_strlen(char *str)
{
  int	length;

  length = 0;
  while (*str)
    {
      str = str + 1;
      length = length + 1;
    }
  return (length);
}

int	my_swap_str(char *a, char *b)
{
  char	c;

  c = *a;
  *a = *b;
  *b = c;
  return (0);
}

char	*my_revstr(char *str)
{
  int	length;
  int	i;
  int	pivot;

  i = 0;
  length = my_strlen(str);
  pivot = length / 2;
  while (i <= pivot)
    {
      my_swap_str((str + i), (str + length - i - 1));
      i = i + 1;
    }
  return (str);
}
