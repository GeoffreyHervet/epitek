/*
** inf_add.c for bistromathique in /home/follet_e//work/bistro/.bistro
** 
** Made by estelle follet
** Login   <follet_e@epitech.net>
** 
** Started on  Thu Oct 28 10:41:02 2010 estelle follet
** Last update Sun Oct 31 16:07:49 2010 estelle follet
*/

#include <stdlib.h>
#include <unistd.h>

int	my_strlen(char *str);
char	*my_revstr(char *str);

void	my_putstr(char *str)
{
  write (1, str, my_strlen(str));
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

char	*fill(char *nbr1, char *nbr2)
{
  char	*str;
  int	i;
  int	size_res;

  if (my_strlen(nbr1) > my_strlen(nbr2))
    size_res = my_strlen(nbr1) + 1;
  else
    size_res = my_strlen(nbr2) + 1;
  str = malloc(sizeof(str) * (size_res));  
  if (str == NULL)
    {
      my_putstr("erreur malloc\n");
      return (0);
    }
  i = size_res;
  while (i != -1)
      str[i--] = '0';
  str[size_res + 1] = '\0';
  return (str);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr0(char *str)
{
  int	i;
  int	zero;

  zero = 0;
  i = 0;
  while (str[i + 1])
    {
      if (!zero && str[i] != '0')
	zero = 1;
      if (zero)
	my_putchar(str[i]);
      i++;
    }
}

int	inf_add(char *nbr1, char *nbr2)
{
  char	*res;
  int	i;
  int	size1;
  int	size2;

  i = 0;
  size1 = my_strlen(nbr1);
  size2 = my_strlen(nbr2);
  res = fill(nbr1, nbr2);
  while ((size1 - i > -1) || (size2 - i > -1))
    {
      if ((size1 - i) > -1)
	res[i] += nbr1[size1 - i] - '0';
      if ((size2 - i) > -1)
	res[i] += nbr2[size2 - i] - '0';
      if (res[i] > '9')
	{
	  res[i] -= 10;
	  res[i + 1]++;
	}
      i++;
    }
  my_revstr(res);
  my_putstr0(res);
  free(res);
  return (0);
}


int	main(int argc,  char **argv)
{
  if (argc == 3)
      inf_add(argv[1], argv[2]);
  else
    my_putstr("erreur argument\n");
  return (0);
}
