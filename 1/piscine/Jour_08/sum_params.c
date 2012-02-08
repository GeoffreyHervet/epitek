/*
** sum_params.c for sum_params.c in /home/hervet_g//work/piscine/Jour_08
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Oct 15 23:09:06 2010 geoffrey hervet
** Last update Sat Oct 16 00:18:40 2010 geoffrey hervet
*/

#include <stdlib.h>

void	my_putchar(char c);
int	my_putstr(char *str);

int	my_strlen(char *str)
{
  int	ret;

  ret = 0;
  while (str[ret])
    ret = ret + 1;
  return (ret);
}

char	*sum_params(int argc, char **argv)
{
  char	*ret;
  int	width;
  int	i;
  int	arg_pos;
  int	ret_pos;

  width = 0;
  ret_pos = 0;
  i = argc;
  while (i < argc)
    width = width + my_strlen(argv[i++]);
  i = 0;
  ret = malloc(sizeof(*ret) * (width + 1));
  while (i < argc)
    {
      arg_pos = 0;
      while (argv[i][arg_pos])
	{
	  ret[ret_pos++] = argv[i][arg_pos++];
	}
      ret[ret_pos++] = '\n';
      i = i + 1;
    }
  ret[ret_pos - 1] = 0;
  return (ret);
}

int	main(int ac, char **av)
{
  printf("%s",sum_params(ac, av));
  return (0);
}
