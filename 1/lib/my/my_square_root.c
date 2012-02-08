/*
** my_square_root.c for my_square_root.c in /home/hervet_g//work/piscine/lib/my
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Oct 13 21:28:58 2010 geoffrey hervet
** Last update Wed Oct 13 22:37:09 2010 geoffrey hervet
*/

int	my_square_root(int nb)
{
  int i;
  int ret;

  i = 1;
  ret = 1;
  while (nb > 0 && ret <= nb)
    {
      if ((ret * ret) == nb)
	return (ret);
      i = i + 2;
      ret = ret + 1;
    }
  return (0);
}
