/*
** my_evil_str.c for my_evil_str.c in /home/hervet_g//work/piscine/Jour_04
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Thu Oct  7 10:17:29 2010 geoffrey hervet
** Last update Fri Oct  8 21:30:37 2010 geoffrey hervet
*/

int	my_putstr(char *str)
{
  while (*str)
    {
      my_putchar(*str);
      str = str + 1;
    }
  return (0);
}

int	my_strlen(char *str)
{
  int   length;

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
  char  c;

  c = *a;
  *a = *b;
  *b = c;
  return (0);
}

char	*my_evil_str(char *str)
{
  int   length;
  int   i;
  int   pivot;

  i = 0;
  length = my_strlen(str);
  my_put_nbr(length);
  pivot = length / 2;
  while (i <= pivot)
    {
      my_swap_str((str + i), (str + length - i - 1));
      i = i + 1;
    }
  return (str);
}
