/*
** main.c for ex01 in /home/hervet_g/piscine/d01/piscine_cpp_d01-2015-hervet_g/ex01
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Jan 04 12:24:42 2012 geoffrey hervet
** Last update Wed Jan 04 12:24:42 2012 geoffrey hervet
*/

#include	<string.h>

/*
 * size
 * level
 */

void	menger(unsigned int, unsigned int);

static unsigned int	getNbr(const char *s)
{
  int			idx = 0;
  unsigned int		ret = 0;

  while (s[idx])
    ret = ret * 10 + s[idx++] - '0';
  return ret;
}

int	main(int ac, char **av)
{
  if (ac != 3)
    return 0;
  menger(getNbr(av[1]), getNbr(av[2]));
  return 1;
}
