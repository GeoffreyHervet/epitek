/*
** colle.c for colle 1-1 in /home/hervet_g//work/piscine/colles/Semaine_01
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sat Oct  9 15:18:04 2010 geoffrey hervet
** Last update Tue Dec 14 13:46:35 2010 geoffrey hervet
*/

int     my_putchar(char c)
{
  write(1, &c, 1);
}

void    my_put_char_rec(char c, int nb_fois)
{
  if (nb_fois)
    {
      my_putchar(c);
      my_put_char_rec(c, (nb_fois - 1));
    }
}

void    aff_ligne(int nb_col, int ligne_extr)
{
  if (nb_col)
    {
      if (ligne_extr)
        {
          my_put_char_rec('o', 1);
          nb_col = nb_col - 1;
          if (nb_col)
            {
              my_put_char_rec('-', nb_col - 1);
              my_put_char_rec('o', 1);
            }
        }
      else
        {
          my_put_char_rec('|', 1);
          nb_col = nb_col - 1;
          if (nb_col)
            {
              my_put_char_rec(' ', nb_col - 1);
              my_put_char_rec('|', 1);
            }
        }
    }
}
void    colle(int x, int y)
{
  int   i;

  i = 0;
  while ((y  > 0) && (x > 0))
    {
      i = i + 1;
      if ((i == 1) || (y == 1))
        {
          aff_ligne(x, 1);
        }
      else
        {
          aff_ligne(x, 0);
        }
	   my_putchar('\n');
      y = y - 1;
    }
}

int     main(int ac, char **av)
{
  int	nb1;
  int	nb2;
  int	idx;

  nb1 = 0;
  nb2 = 0;
  idx = -1;
  if (ac < 3)
    return (0);
  while (av[1][++idx])
    nb1 = nb1 * 10 + av[1][idx] - '0';
  idx = -1;
  while (av[2][++idx])
    nb2 = nb2 * 10 + av[2][idx] - '0';
  colle(nb1, nb2);
  return (0);
}
