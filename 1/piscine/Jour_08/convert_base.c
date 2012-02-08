/*
** convert_base.c for convert_base.c in /home/hervet_g//work/piscine/Jour_08
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Oct 15 10:13:27 2010 geoffrey hervet
** Last update Fri Oct 15 23:06:39 2010 geoffrey hervet
*/

#include <stdlib.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}

int	my_power_it(int nb, int power)
{
  int	res;

  res = 1;
  while (power--)
    res = nb * res;
  return (res);
}

int     get_char_pos(char *str, char s)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] == s)
        return (i);
      i = i + 1;
    }
  return (-1);
}

int     my_getnbr_base(char *str, char *base)
{
  int   i;
  int   ret;
  int   larg_base;
  int   larg_int;

  larg_base = my_strlen(base);
  larg_int = my_strlen(str);
  ret = 0;
  i = 0;
  while (str[i])
    {
      ret = ret + 
        get_char_pos(base, str[i]) * my_power_it(larg_base, larg_int - i - 1);
      i = i + 1;
    }
  return (ret);
}

char	my_add_char(int largeur_base, int largeur_aff, char *base, int nbr)
{
  if (nbr < largeur_base)
    return (largeur_aff ?  base[0] : base[nbr]);
  else
    {
      return (base[(nbr / my_power_it(largeur_base, largeur_aff))]);
    }
}

char	*my_putnbr_base(int nbr, char *base)
{
  int	n;
  int	largeur_aff;
  int	largeur_base;
  char	*ret;

  largeur_base = 0;
  largeur_aff = 0;
  ret = 0;
  n = nbr;
  while (base[largeur_base])
      largeur_base = largeur_base + 1;
  while (n)
    {
      n = n / largeur_base;
      largeur_aff = largeur_aff + 1;
    }
  ret = malloc( sizeof(*ret) * (largeur_aff + 1));
  n = 0;
  while (largeur_aff--)
    {
      ret[n++] = my_add_char(largeur_base, largeur_aff, base, nbr);
      if (nbr >= largeur_base)
	nbr = nbr % my_power_it(largeur_base, largeur_aff);
    }
  ret[n] = 0;
  return (ret);
}


char	*convert_base(char *nbr, char *base_from, char *base_to)
{
  int	nbr_10;
  
  nbr_10 = my_getnbr_base(nbr, base_from);
  return (my_putnbr_base(nbr_10, base_to));
}
