/*
** my_putnbr_base.c for my_putnbr_base.c in /home/hervet_g//work/piscine/Jour_06
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Oct 11 21:40:23 2010 geoffrey hervet
** Last update Tue Oct 12 22:56:44 2010 geoffrey hervet
*/

int	my_swap_str(char *a, char *b)
{
  char	c;

  c = *a;
  *a = *b;
  *b = c;
  return (0);
}

void	my_putstr(char *str)
{
  while (*str)
    {
      my_putchar(*str);
      str = str + 1;
    }
}

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

int	my_power_it(int nb, int power)
{
  int	result;

  result = 1;
  while (power)
    {
      if (nb > 0)
        {
          result = result * nb;
          power = power - 1;
        }
      else
        {
          result = result / nb;
          power = power + 1;
        }
    }
  return (result);
}

int	reset_n(int n, char *base, int largeur_base, int largeur_aff)
{
  my_putchar(base[(n / my_power_it(largeur_base, largeur_aff))]);
  return (n % my_power_it(largeur_base, largeur_aff));
}

int	my_putnbr_base(int nbr, char *base)
{
  int	n;
  int	largeur_aff;
  int	largeur_base;

  largeur_base = 0;
  largeur_aff = 0;
  n = (nbr > 0) ? nbr : - nbr;
  if (n < 0)
      my_putchar('-');
  while (base[largeur_base])
      largeur_base = largeur_base + 1;
  while (n)
    {
      n = n / largeur_base;
      largeur_aff = largeur_aff + 1;
    }
  n = (nbr > 0) ? nbr : - nbr;
  while (largeur_aff--)
    {
      if (n < largeur_base)
	  (largeur_aff) ? my_putchar(base[0]) : my_putchar(base[n]);
      else
	n = reset_n(n, base, largeur_base, largeur_aff);
    }
  return (nbr);
}
