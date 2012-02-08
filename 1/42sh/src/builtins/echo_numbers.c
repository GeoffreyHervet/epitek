/*
** header for norme in /
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.eu>
** 
** Started on  Mon Jan 01 00:00:00 2011 geoffrey hervet
** Last update Mon Jan 01 00:00:00 2011 geoffrey hervet
*/

#include	"echo_numbers.h"

static int	get_value(char c, int base_dec)
{
  if (c >= '0' && c <= '8')
    return (c - '0');
  if (base_dec == 3)
    return (-1);
  if (c == '9')
    return (9);
  if (c >= 'A' && c <= 'F')
    return (c - 'A' + 10);
  if (c >= 'a' && c <= 'f')
    return (c - 'a' + 10);
  return (-1);
}

static int	updater(int *nbr, int base_dec, int dec)
{
  *nbr = *nbr >> base_dec;
  return (dec - 1);
}

int		number_str(char *str,
                           int *count,
                           int *count2)
{
  int		dec;
  int		nbr;
  int		to_add;
  int		base_dec;
  int		conti;

  dec = 2;
  nbr = 0;
  base_dec = (str[*count2 + 1] == 'x') ? 4 : 3;
  conti = 1;
  while (conti && nbr < 127)
  {
    to_add = get_value(str[*count2 + dec], base_dec);
    if (to_add == -1)
      conti = 0;
    if (conti)
      nbr = (nbr << base_dec) + to_add;
    if (conti)
      dec++;
  }
  if (nbr > 127)
    dec = updater(&nbr, base_dec, dec);
  str[*count] = (dec == 2) ? str[*count2 + 1] : (char)nbr;
  *count2 += dec;
  return (0);
}
