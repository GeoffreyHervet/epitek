/*
** sapin.c for sapinc in /home/hervet_g//work/piscine/sapin
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Fri Oct  8 18:05:01 2010 geoffrey hervet
** Last update Mon Nov  8 22:32:17 2010 geoffrey hervet
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	put_chars(char c, int nb)
{
  if (nb)
    {
      my_putchar(c);
      put_chars(c, nb - 1);
    }
}

int	get_max_width(int taille)
{
  int	i;
  int	nb_inc;
  int	result;

  nb_inc = 4;
  result = 1;
  i = 0;
  while (i != taille)
    {
      i = i + 1;
      if (i % 2)
	nb_inc = nb_inc + 2;
      result = result + nb_inc;
    }
  return (result);
}

void	print_etage(int nb_spaces, int nb_etoiles, int is_tronc)
{
  if (is_tronc)
    {
      put_chars(' ', nb_spaces);
      put_chars('|', nb_etoiles);
    }
  else
    {
      put_chars(' ', nb_spaces);
      put_chars('*', nb_etoiles);
    }
  put_chars('\n', 1);
}

void	do_pipes(int taille, int taille_act, int max_spaces)
{
  int	 nb_pipes;

  nb_pipes = (taille % 2) ? taille : taille + 1;
  taille_act = taille;
  if (taille % 2)
    taille + 1;
  while (taille_act--)
    {
      print_etage((max_spaces - (nb_pipes / 2)), nb_pipes, 1);
    }
}

void	sapin(int taille)
{
  int	max_spaces;
  int	taille_act;
  int	nb_etoiles;
  int	val_del;
  int	i;

  max_spaces = (get_max_width(taille) - 1) / 2;
  i = 0;
  val_del = 2;
  taille_act = 1;
  nb_etoiles = 1;
  while ((taille_act <= taille) && (++i))
    {
      nb_etoiles = nb_etoiles + 2;
      if ((!(taille_act % 2)) && i == 1)
        val_del = val_del + 2;
      if (i == 1)
        nb_etoiles = nb_etoiles - val_del;
      print_etage(max_spaces - ((nb_etoiles - 1) / 2), nb_etoiles, 0);
      if (i == (taille_act + 3))
        {
          i = 0;
          taille_act = taille_act + 1;
        }
    }
  do_pipes(taille, taille, max_spaces);
}

int	main(int ac, char **av)
{
  int	size;
  int	i;

  if (ac > 1)
    {
      size = 0;
      i = -1;
      while (av[1][++i])
	if (av[1][i] >= '0' && av[1][i] <= '9')
	  size = size * 10 + av[1][i] - '0';
      sapin (size);

    }
  return (0);
}
